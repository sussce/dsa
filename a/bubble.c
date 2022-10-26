#include <stdio.h>

void bubble(int s[], int n);
void bubble1(int s[], int n);

void bubble(int s[], int n) {
  for(int i = 0; i < n-1; i++) {
    int e = 0;
    for(int j = 0; j < n-1-i; j++) {
      if(s[j] > s[j+1]) {
        swap(&s[j], &s[j+1]);
        e = 1;
      }
    }
    if(!e) break;
  }
}

void bubble1(int s[], int n) {
  int m = n;
  for(int i = m-1; i > 0; i--) {
    int e = 0;
    for(int j = 0; j < i; j++) {
      if(s[j] > s[j+1]) {
        swap(&s[j], &s[j+1]);
        e = j;
      }
    }
    m = e;
  }
}
