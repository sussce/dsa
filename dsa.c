#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ds/macro.h"
#include "ds/list.h"
#include "ds/tree.h"
#include "a/search.c"
#include "a/sort.c"

int main(int argc, char **argv) {
  int pre[] = {4, 2, 1, 3, 5, 7, 6};
  size_t n = array_sz(pre);
  
  tree *t = t_fork_order(pre, n);
  t_print(t);

  return 0;
}
