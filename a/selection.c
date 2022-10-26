#include <stdio.h>

void selection(int s[], int n);

void selection(int s[], int n) {
  int imin;
  for(int i = 0; i < n; i++) {
    imin = i;
    for(int j = i; j < n; j++) {
      if(s[imin] > s[j]) {
        imin = j;
        continue;
      }
    }
    swap(&s[imin], &s[i]);
  }
}
