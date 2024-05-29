#include <iostream>
#include <memory>

void check_weak(std::weak_ptr<int>& wp) {
  std::shared_ptr<int> sp = wp.lock();
  if (sp != nullptr) {
    std::cout << "The value is " << *sp << std::endl;
  } else {
    std::cout << "Pointer is invalid." << std::endl;
  }
}

int main(int argc, char **argv) {
  std::shared_ptr<int> sp1(new int(10));
  std::shared_ptr<int> sp2 = sp1;
  std::weak_ptr<int> wp = sp1;

  std::cout << *sp1 << std::endl;
  std::cout << *sp2 << std::endl;
  check_weak(wp);

  sp1.reset();
  std::cout << *sp2 << std::endl;
  check_weak(wp);

  sp2.reset();
  check_weak(wp);

  return 0;
}
