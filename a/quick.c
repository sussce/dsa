#include <stdio.h>

void quick(int s[], int n);
void __quick(int s[], int left, int right);
int partition(int s[], int left, int right);

void quick(int s[], int n) {
  __quick(s, 0, n-1);
}

void __quick(int s[], int left, int right) {
  if(left >= 0 <= right && left < right) {
    int p = partition(s, left, right);
    __quick(s, left, p);
    __quick(s, p+1, right);
  }
}

int partition(int s[], int left, int right) {
  int pivot = s[(left + right)/2];
  int i = left-1, j = right+1;
  
  while(1) {
    while(s[++i] < pivot) {}
    while(j > 0 && s[--j] > pivot) {}
    if(i >= j) return j;
    swap(&s[i], &s[j]);
  }
}
