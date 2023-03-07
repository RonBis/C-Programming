/* Longest Common Subsequence problem */
// Given two subsequences, find the longest common subsequence between them

#include <stdio.h>

#define getSize(arr) sizeof(arr) / sizeof(arr[0])

char s1[] = {'a', 'a', 'b', 'b', 'b', 'c'};
char s2[] = {'a', 'a', 'b', 'c'};

int main(void) {
  int s1_size = getSize(s1) + 1; // rows
  int s2_size = getSize(s2) + 1; // cols

  int dp_mat[s1_size][s2_size];
  for (int i = 0; i < s2_size; i++)
    dp_mat[0][i] = 0;
  for (int i = 0; i < s1_size; i++)
    dp_mat[i][0] = 0;

  for (int i = 1; i < s1_size; i++) {
    for (int j = 1; j < s2_size; j++) {
      // checks if row head matches column head
      if (s1[i - 1] == s2[j - 1]) {
        // add 1 with top-left element from dp_mat (dp_mat[i-1][j-1])
        dp_mat[i][j] = dp_mat[i - 1][j - 1] + 1;
      } else {
        int top = dp_mat[i - 1][j];
        int left = dp_mat[i][j - 1];

        dp_mat[i][j] = top > left ? top : left;
      }
    }
  }

  printf("Final dp matrix\n");
  for (int i = 0; i < s1_size; i++) {
    for (int j = 0; j < s2_size; j++) {
      printf("%d  ", dp_mat[i][j]);
    }
    printf("\n");
  }

  return 0;
}
