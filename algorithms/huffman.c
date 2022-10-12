#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct msgchar {
  char ch;
  int freq;
} msgchar;

typedef struct htree_node {
  // char assoc_ch;  // associated character with frequency (NULL unless leaf
  // node)
  int freq;
  struct htree_node *left_child;
  struct htree_node *right_child;
} hnode;

typedef struct huffman_code {
  char ch;
  char *huffman_code;
} hcode;

msgchar *r_chars;
int char_count;
hnode *root;
hcode *codes;

hnode *new_hnode(int freq, hnode *left_child, hnode *right_child) {
  hnode *node = (hnode *)malloc(sizeof(hnode));
  node->freq = freq, node->left_child = left_child,
  node->right_child = right_child;
  return node;
}

void read_string(char *r_str, int *r_strlen) {
  fgets(r_str, 100, stdin);

  *r_strlen = strlen(r_str);
  r_str[*r_strlen - 1] = '\0';
  (*r_strlen)--;
}

/// @brief Generates the sorted frequency table of the characters in the
/// message.
/// @param msg
/// @param r_chars will hold the distinct characters in the message along with
/// their frequency
/// @return The length of distinct characters found in the message.
void generate_freq_table(char *msg) {
  // assume all characters are distinct
  // later realloc() to necessary amount
  char *found_chars = malloc(255 * sizeof(char));
  int found_chars_len = 1;
  found_chars[0] = msg[0];

  r_chars = (msgchar *)malloc(sizeof(msgchar));
  r_chars[0] = (msgchar){.ch = msg[0], .freq = 0};

  for (int i = 0; msg[i] != '\0'; i++) {
    // checks if character is already found in msg or not
    bool found_new = true;
    for (int j = 0; j < found_chars_len; j++) {
      if (msg[i] == found_chars[j]) {
        found_new = false;

        // increase frequency by 1
        r_chars[j] = (msgchar){.ch = msg[i], .freq = r_chars[j].freq + 1};
        break;
      }
    }
    if (found_new == true) {
      found_chars_len++;
      found_chars[found_chars_len - 1] = msg[i];

      r_chars = (msgchar *)realloc(r_chars, found_chars_len * sizeof(msgchar));
      r_chars[found_chars_len - 1] = (msgchar){.ch = msg[i], .freq = 1};
    }
  }

  free(found_chars);

  // sort frequency table
  for (int i = 0; i < found_chars_len; i++) {
    for (int j = 0; j < found_chars_len; j++) {
      if (r_chars[i].freq < r_chars[j].freq) {
        // swap
        msgchar tmp = r_chars[i];
        r_chars[i] = r_chars[j];
        r_chars[j] = tmp;
      }
    }
  }
  char_count = found_chars_len;
}

void generate_tree() {
  hnode *leaf1 = new_hnode(r_chars[0].freq, NULL, NULL);
  hnode *leaf2 = new_hnode(r_chars[1].freq, NULL, NULL);
  hnode *parent = new_hnode(leaf1->freq + leaf2->freq, leaf1, leaf2);

  int count = 2;
  while (count != char_count) {
    leaf2 = new_hnode(r_chars[count].freq, NULL, NULL);
    if (parent->freq <= r_chars[count].freq) {
      parent = new_hnode(parent->freq + r_chars[count].freq, parent, leaf2);
    } else {
      parent = new_hnode(parent->freq + r_chars[count].freq, leaf2, parent);
    }

    count++;
  }
  root = parent;
}

// possible problem is DFS, should be BFS
void traverse_htree(hnode *node, int path_string) {
  static int count = 1;

  if (node->left_child == NULL) {
    // printf("static count: %d\n", count);
    printf("%c: %d\n", r_chars[char_count - count].ch, path_string);
    count++;
    return;
  } else if (node->right_child == NULL) {
    // printf("static count: %d\n", count);
    printf("%c: %d\n", r_chars[char_count - count].ch, path_string);
    count++;
    return;
  } else {
    traverse_htree(node->left_child, path_string * 10 + 0);
    traverse_htree(node->right_child, path_string * 10 + 1);
  }
}

void generate_code() { traverse_htree(root, 0); }

int main() {
  char msg[100];
  int msg_len;

  // sample message: bcaadddccacacac
  printf("Enter message: ");
  read_string(msg, &msg_len);

  // printf("Message length is %d\n", msg_len);
  if (msg_len == 0) {
    printf("Message cannot be empty.");
    return 0;
  }

  generate_freq_table(msg);

  printf("\n## frequency table ##\n");
  for (int i = 0; i < char_count; i++) {
    printf("%c: %d\n", r_chars[i].ch, r_chars[i].freq);
  }

  generate_tree();

  printf("\n## huffman codes ##\n");
  generate_code();

  return 0;
}
