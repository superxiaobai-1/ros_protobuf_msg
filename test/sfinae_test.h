#include <iostream>
#include <type_traits>

template <class T, class Enable = void>
class Test {
 public:
  explicit Test(T a) : a_(a) { std::cout << "普通模板化: " << a_ << std::endl; }

 private:
  T a_;
};

template <class T>
class Test<T, typename std::enable_if<std::is_floating_point<T>::value>::type> {
 public:
  explicit Test(T a) : a_(a) {
    std::cout << "double 偏特化: " << a_ << std::endl;
  }

 private:
  T a_;
};

// template <class T>
// class test<T,
//            typename std::enable_if<!std::is_floating_point<T>::value>::type>
//            {
//  public:
//   Test(T a) : a_(a) { std::cout << " not double" << std::endl; }

//  private:
//   T a_;
// };