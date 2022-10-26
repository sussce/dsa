#include <stdio.h>

int binary(int x, int y[], int n);

int binary(int x, int y[], int n) {
  int f, l, m;
  f = 0, l = n-1, m = (f+l)/2;

  while (y[m] != x && f <= l) {
    if (y[m] > x) l = m-1;
    else f = m + 1;
    m = (f+l)/2;
  }
  return y[m] == x ? m : -1;
}
