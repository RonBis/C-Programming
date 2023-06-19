#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef DEBUG

#include <dlfcn.h>
#include <string.h>

// function pointer
typedef void *(*malloc_like_function)(size_t);

void *malloc(size_t size) {
  malloc_like_function sysmalloc =
      (malloc_like_function)dlsym(RTLD_NEXT, "malloc");

  void *result = sysmalloc(size);
  memset(result, 0xCD, size);
  return result;
}

#endif

int main() {
  int *p1 = (int *)malloc(sizeof(int));
  int *p2 = (int *)malloc(sizeof(int));

  *p1 = 0;

  printf("%d %d\n", *p1, *p2);

  return 0;
}
