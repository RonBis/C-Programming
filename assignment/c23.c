#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int length(char *p) {
  int count = 0;
  while (*p != '\0') {
    count++;
    p++;
  }
  return count;
}
void catenation(char *s1, char *s2) {
  s1 += length(s1);
  for (; *s2 != '\0'; s1++, s2++) {
    *s1 = *s2;
  }
  *s1 = '\0';
}
int compare(char *s1, char *s2) {
    while (*s1) {
      if (*s1 != *s2)
        break; // if characters differ, or end of the second string is reached
      s1++, s2++; // move to the next pair of characters
    }
    return *s1 - *s2;
  }

void upper(char *s) {
  for (; *s != '\0'; s++) {
    if (*s >= 'a' && *s <= 'z') // ASCII value of a=97,z=122
    {
      *s -= 32; // ASCII value of A=65, Z=90
    }
  }
}
void lower(char *s) {
  for (; *s != '\0'; s++) {
    if (*s >= 'A' && *s <= 'Z') // ASCII value of A=65 , Z=90
    {
      *s += 32; // ASCII value of a=97,z=122
    }
  }
}
void rev(char *s) {
  char *p, t;
  p = s;
  p += length(s) - 1;
  for (; s < p; s++, p--) {
    t = *s;
    *s = *p;
    *p = t;
  }
}

int main() {
  char str[20], str1[20], str2[20], *p;
  int len, ch, i, diff, c = 0;
  printf(
      "Choose from the following:\n1.Show the address of each character in a "
      "string.\n2.Concatenate two strings without strcat() "
      "function.\n3.Concatenate two strings by using the strcat() "
      "function.\n4.Compare two strings\n5.Calculate length of the string (use "
      "pointers)\n6.Convert all lowercase characters to uppercase\n7.Convert "
      "all uppercase characters to lowercase\n8.Calculate number of "
      "vowels\n9.Reverse the string\n10.Exit");
  while (1) {
    printf("\n\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      printf("\nEnter the string: ");
      fflush(stdin);
      gets(str);
      len = length(str);
      p = str;
      for (i = 0; i < len; i++) {
        printf("\nThe address of character %d is %u\n", i + 1, p);
        p++;
      }
      break;
    case 2:
      printf("\nEnter 1st string: ");
      fflush(stdin);
      gets(str1);
      printf("\nEnter 2nd string: ");
      fflush(stdin);
      gets(str2);
      catenation(str1, str2);
      printf("\nAfter concatenation: %s", str1);
      break;
    case 3:
      printf("\nEnter 1st string: ");
      fflush(stdin);
      gets(str1);
      printf("\nEnter 2nd string: ");
      fflush(stdin);
      gets(str2);
      strcat(str1, str2);
      printf("\nAfter concatenation: %s", str1);
      break;
    case 4:
      printf("\nEnter 1st string: ");
      fflush(stdin);
      gets(str1);
      printf("\nEnter 2nd string: ");
      fflush(stdin);
      gets(str2);
      diff = compare("helloi", "hello");
      if (diff != 0) {
        printf("\nStrings are not equal");
      } else
        printf("\nStrings are equal");
      break;
    case 5:
      printf("\nEnter the string: ");
      fflush(stdin);
      gets(str);
      printf("\nThe length of the given string is %d", length(str));
      break;
    case 6:
      printf("\nEnter the string: ");
      fflush(stdin);
      gets(str);
      upper(str);
      printf("\nConverting lowercase characters to uppercase: %s", str);
      break;
    case 7:
      printf("\nEnter the string: ");
      fflush(stdin);
      gets(str);
      lower(str);
      printf("\nConverting uppercase characters to lowercase: %s", str);
      break;
    case 8:
      printf("\nEnter the string: ");
      fflush(stdin);
      gets(str);
      len = length(str);
      for (i = 0; i < len; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
            str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' ||
            str[i] == 'O' || str[i] == 'U')
          c++;
      }
      printf("\nThe number of vowels in the string is %d", c);
      c = 0; // c is reinitialised to 0, so that next time when option 8 is
             // chosen, it doesn't show its previous result.
      break;
    case 9:
      printf("\nEnter the string: ");
      fflush(stdin);
      gets(str);
      rev(str);
      printf("\nThe reverse of the string is: %s", str);
      break;
    case 10:
      exit(1);
      break;
    default:
      printf("\nError, select a valid option!");
    }
  }
  return 0;
}