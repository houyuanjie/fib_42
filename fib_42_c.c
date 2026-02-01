#include <stdio.h>

int fib(int n);

int main(int argc, char const *argv[]) {
  int result;

  result = fib(42);
  printf("fib(42) = %d\n", result);

  return 0;
}

int fib(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }

  return fib(n - 1) + fib(n - 2);
}
