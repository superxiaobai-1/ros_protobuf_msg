#include "./sfinae_test.h"

int main() {
  Test<double> t1(1.1);
  Test<int> t2(1);
  return 0;
}