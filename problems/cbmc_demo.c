#include <stdlib.h>

/******************************
 * EXAMPLE 1: 1 + 2 + ... + n
 ******************************/

int sum_iter(int n) {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      ans++;
    }
  }
  return ans;
}

int sum_rec(int n) {
  if (n == 0) { return 0; }
  return n + sum_rec(n-1);
}


/*********************************
 * EXAMPLE 2: x[0] + ... + x[n-1]
 *********************************/

int arraySum(const int *x, int n) {
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += x[i];
  }
  return sum;
}

int arraySum_buggy(const int *x, int n) {
  int sum;
  for (int i = 0; i < n; ++i) {
    sum += x[i];
  }
  return sum;
}

/*******************************************
 * EXAMPLE 3: p->data + p->next->data + ...
 *******************************************/

typedef struct node {
  int data;
  struct node *next;
} node;

void freeList(node *p) {
  if (p != NULL) {
    freeList(p->next);
    free(p);
  }
}

int listSum(const node *p) {
  int sum = 0;
  while (p != NULL) {
    sum += p->data;
    p = p->next;
  }
  return sum;
}

int listSum_buggy(const node *p) {
  int sum = 0;
  do {
    sum += p->data;
    p = p->next;
  } while (p != NULL);
  return sum;
}

/*** Assertions in main ***/

int main() {
  int n;
  __CPROVER_assert(sum_iter(n) == sum_rec(n), "sum.1");
  __CPROVER_assert(sum_iter(n) == n*(n+1)/2, "sum.2");
  int m = (n > 0 ? n : 1);
  int x[m];
  int *y = (n > 0 ? x : NULL);
  __CPROVER_assert(arraySum(y, n) == arraySum_buggy(y, n), "arraysum");
  node *p = NULL;
  for (int i = 0; i < n; ++i) {
    node *temp = malloc(sizeof(node));
    temp->next = p;
    p = temp;
  }
  __CPROVER_assert(listSum(p) == listSum_buggy(p), "listsum");
  freeList(p);

  return 0;
}