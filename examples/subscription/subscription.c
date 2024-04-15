/*
 * First KLEE tutorial: testing a small function
 */

#include <stdio.h>
#include "klee/klee.h"

int main() {
  int a;
  klee_make_symbolic(&a, sizeof(a), "a");

  int b;
  klee_subscribe(&b, "b", Change);
  b = a;

  if (a > 0) {
    b++;
    printf("0.1: **Priority**\n");

    if (a > 5)
      printf("1.1\n");
    else
      printf("1.2\n");

  } else {
    printf("0.2: **Non-Priority**\n");

    if (a < -5)
      printf("2.1.1\n");
    else {
      printf("2.1.2\n");
      if (a < -6) {
        printf("2.1.2.1\n");
      } else {
        printf("2.1.2.2\n");
        if (a > -5) {
          printf("2.1.2.2.1\n");
        } else {
          /* b++; */
          printf("2.1.2.2.2 - Only reachable with --max-non-priority >= 2\n");
        }
      }
    }
  }

  return 0;
}
