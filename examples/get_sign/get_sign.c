/*
 * First KLEE tutorial: testing a small function
 */

#include <stdio.h>
#include "klee/klee.h"

int c = 0;

int get_sign(int x) {
  if (x == 0) {
    int b = 0;
    klee_subscribe_changing(&b, sizeof(b), "b_loc");
    return 0;
  }
  if (x < 0)
    return -1;
  else
    return 1;
}

int main() {

  int a;
  klee_make_symbolic(&a, sizeof(a), "a");

  int b = 0;
  klee_subscribe_changing(&b, sizeof(b), "b");
  klee_subscribe_changing(&c, sizeof(c), "c");

  get_sign(a);
  return 0;
}
