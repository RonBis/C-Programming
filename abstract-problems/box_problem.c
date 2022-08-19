//     Suppose, you have been given "N" rectangular wooden blocks,
//     where "N" is a user -
//         defined integer.Collect the dimensions of each box from a
//         file(format described below),
//     and then store the numbers in an array of structure,
//     where each entry of the array is a structure called
//     "box" containing three floats,
//     containing the three dimensions of the boxes.Note that since "N" is
//     not initially known,
//     the array must be allocated space dynamically.Then,
//     call a function
//     "float find_maximum_height (box *box_array, int num_boxes)" to calculate
//         and return the maximum height that can be obtained by arranging these
//     cube one above another.Note that a box can be placed on any of its six
//     faces
//         .While accessing each element from the "box_array" array,
//     do not directly use the individual elements of the array but,
//     use pointer to a structure.e.g.to access the "i" - th element of the
//     array, declare and use a structure pointer as follows : box *box_ptr;
//     ...........
//     box_ptr = box_array + i; // note the use of pointer arithmetic

//     INPUT : Input will be given in a file "dimensions.txt",
//     which you should create yourself.The
//     first line of the file contains the numerical value "N",
//     and each of the next "N" lines contains 3 floating
//     point values separated by spaces.You can consider using the
//     "fgets()" function to read the lines from the file,
//     and"sscanf()" or
//     "strtok()" to collect the individual numbers from a line.Example
//     "dimension.txt" :
//        4
//        1.2 2.5 3.1
//        2.7 4.0 2.4
//        5.3 6.4 2.2
//        3.0 4.1 6.8

//     OUTPUT : the maximum height of the arrangement

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Box {
  float h;
  float w;
  float l;
};
typedef struct Box box;

float find_max_height(box *boxes, int N) {
  float max_height = 0;
  for(int i = 0;i<N;i++) {
    max_height += (boxes + i)->h;
  }

  return max_height;
}

char *readfile(FILE *fp) {
  // find out the file content length
  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);

  rewind(fp); // move pointer back to start

  char *str = malloc(fsize + 1);
  fread(str, fsize, sizeof(char), fp);
  str[fsize] = '\0'; // terminate the string

  return str;
}

int main() {
  box *boxes;
  FILE *srcfp;
  char *src_content, ch;

  // let max number of boxes -> 9999
  char _N_str[4];
  int N;

  srcfp = fopen("dimension.file", "r");
  src_content = readfile(srcfp);

  char *line;
  // read N from the first line & convert to int
  N = (int)strtol(strtok(src_content, "\n"), NULL, 10);
  // allocate space for N boxes
  boxes = (box *)malloc(sizeof(box) * N);

  line = strtok(NULL, "\n");

  // read the remaining lines
  int box_number = 0;
  while (line != NULL) {
    // while(dimension = strtok_r(line_cpy, " ", &line_cpy)) {
    //   printf("dim_count>%d, dimensions>%s\t", dim_count, dimension);
    //   dim_count++;
    // }
    char *end_ptr;
    float d1 = strtof(line, &end_ptr);
    float d2 = strtof(end_ptr, &end_ptr);
    float d3 = strtof(end_ptr, NULL);

    if (d1 >= d2) {
      if (d1 >= d3) {
        *(boxes + box_number) = (box){.h = d1, .l = d2, .w = d3};
      } else {
        *(boxes + box_number) = (box){.h = d3, .l = d1, .w = d2};
      }
    } else {
      if (d2 >= d3) {
        *(boxes + box_number) = (box){.h = d2, .l = d3, .w = d1};
      } else {
        *(boxes + box_number) = (box){.h = d3, .l = d1, .w = d2};
      }
    }
    line = strtok(NULL, "\n");
    box_number++;
  }

  printf("Maximum height will be %.1f\n", find_max_height(boxes, N));

  fclose(srcfp);
  return 0;
}
