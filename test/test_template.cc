#include "./test_template.h"

int main() {
  Test<double, double> t1(1.1, 1.1);
  Test<int, int> t2(1, 1);
  Test<int, char*> t3(1, "test");
  return 0;
}