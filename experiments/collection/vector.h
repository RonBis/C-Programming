#include <stdarg.h>
#include <stdlib.h>

typedef struct VECTOR {
  int *values;
  int length;

  void (*show)(struct VECTOR *this);
  void (*append)(struct VECTOR *this, int value);
  void (*insert)(struct VECTOR *this, int position, int value);
  int (*pop)(struct VECTOR *this);
  void (*popAt)(struct VECTOR *this, int position);
  int (*shift)(struct VECTOR *this);
} vector;

void append(vector *this, int value) {
  int *tmp = (int *)calloc(this->length + 1, sizeof(int));
  for (int i = 0; i < this->length; i++) {
    tmp[i] = this->values[i];
  }
  free(this->values);
  this->values = tmp;
  this->values[this->length] = value;
  this->length++;
}

void insert(vector *this, int position, int value) {
  if (position > this->length) {
    printf("Error: Vector index out of bounds.\n");
    return;
  }

  int *tmp = (int *)calloc(this->length + 1, sizeof(int));
  for (int i = 0; i < position; i++) {
    tmp[i] = this->values[i];
  }
  tmp[position] = value;
  for (int i = position + 1; i <= this->length; i++) {
    tmp[i] = this->values[i - 1];
  }
  free(this->values);
  this->values = tmp;
  this->length++;
}

int shift(vector *this) {
  int res = this->values[0];
  int *tmp = (int *)calloc(this->length - 1, sizeof(int));

  for (int i = 0; i < this->length; i++) {
    tmp[i] = this->values[i + 1];
  }
  free(this->values);
  this->values = tmp;
  this->length--;

  return res;
}

int pop(vector *this) {
  int res = this->values[this->length - 1];
  this->length--;
  return res;
}

void popAt(vector *this, int position) {}

void show(vector *this) {
  for (int i = 0; i < this->length; i++) {
    printf("%d\t", this->values[i]);
  }
  printf("\n");
}

vector Vector(int length, ...) {
  int *values = (int *)calloc(length, sizeof(int));

  va_list vals;
  va_start(vals, length);

  for (int i = 0; i < length; i++) {
    values[i] = va_arg(vals, int);
  }
  va_end(vals);

  return (vector){
      .values = values,
      .length = length,
      .show = show,
      .append = append,
      .insert = insert,
      .pop = pop,
      .popAt = popAt,
      .shift = shift,
  };
}
