#include <iostream>

class SmartPtr {
 public:
  // Constructor: Refer
  // https://www.geeksforgeeks.org/g-fact-93/ for use of
  // explicit keyword
  explicit SmartPtr(int* p = nullptr) { ptr = p; }

  // Destructor
  ~SmartPtr() {
    std::cout << "free-mem" << std::endl;
    delete (ptr);
  }

  // Overloading dereferencing operator
  int& operator*() { return *ptr; }

 private:
  int* ptr; // Actual pointer
};

void foo(int* var) {
  // By taking a pointer p and
  // dynamically creating object
  // of class rectangle
  SmartPtr the_ptr(var);
  std::cout << "the_ptr: " << *the_ptr << std::endl;
}

int main(int argc, char **argv) {
  while (true) {
    int* var = new int(200);

    std::cout << "var_start: " << *var << std::endl;
    foo(var);
    std::cout << "var_end: " << *var << std::endl;

    std::cout << std::endl;
  }

  // We don't need to call delete ptr: when the object
  // ptr goes out of scope, the destructor for it is
  // automatically called and destructor does delete ptr.

  return 0;
}
