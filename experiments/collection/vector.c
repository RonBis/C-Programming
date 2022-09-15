#include "vector.h"
#include <stdio.h>

int main() {
  vector vec = Vector(5, 1, 2, 3, 4, 5);
  vec.show(&vec);

  return 0;
}
