#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct msgchar {
  char ch;
  int freq;
} msgchar;

void read_string(char *r_str, int *r_strlen) {
  fgets(r_str, 100, stdin);

  *r_strlen = strlen(r_str);
  r_str[*r_strlen - 1] = '\0';
  (*r_strlen)--;
}

/// @brief Generates the frequency table of the characters in the message.
/// @param msg
/// @param r_chars will hold the distinct characters in the message along with their frequency
/// @return The length of distinct characters found in the message.
int generate_freq_table(char *msg, msgchar *r_chars) {
  // assume all characters are distinct
  // later realloc() to necessary amount
  char *found_chars = malloc(255 * sizeof(char));
  int found_chars_len = 1;
  found_chars[0] = msg[0];

  r_chars = (msgchar*)malloc(sizeof(msgchar));
  r_chars[0] = (msgchar){ .ch = msg[0], .freq = 0 };

  for (int i = 0; msg[i] != '\0'; i++) {
    // checks if character is already found in msg or not
    bool found_new = true;
    for (int j = 0; j < found_chars_len; j++) {
      if (msg[i] == found_chars[j]) {
        found_new = false;

        // increase frequency by 1
        r_chars[j] = (msgchar){ .ch = msg[i], .freq = r_chars[j].freq + 1 };
        break;
      }
    }
    if (found_new == true) {
      found_chars_len++;
      found_chars[found_chars_len - 1] = msg[i];

      r_chars = (msgchar *)realloc(r_chars, found_chars_len * sizeof(msgchar));
      r_chars[found_chars_len - 1] = (msgchar){ .ch = msg[i], .freq = 1 };
    }
  }

  free(found_chars);
  // print out the frequenc table
  for (int i = 0; i < found_chars_len; i++) {
    printf("%c: %d\n", r_chars[i].ch, r_chars[i].freq);
  }

  return found_chars_len;
}

int main() {
  char msg[100];
  int msg_len;
  msgchar *chars;
  int distinct_chars_len;

  // sample message: abbcaddabc
  printf("Enter message: ");
  read_string(msg, &msg_len);

  // printf("Message length is %d\n", msg_len);
  if (msg_len == 0) {
    printf("Message cannot be empty.");
    return 0;
  }

  distinct_chars_len = generate_freq_table(msg, chars);

  return 0;
}
