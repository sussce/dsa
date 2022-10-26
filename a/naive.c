#include <stdio.h>

bool naive(char *x, int m, char *y, int n);

bool naive(char *x, int m, char *y, int n) {
  if (m > n) return false;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (*(y+i+j) != *(x+j)) break;
      if (j == m-1) return true;
    }
  }
  return false;
}
