#include <iostream>

// Uncomment the line blow for pack the memory size
// https://carlosvin.github.io/langs/en/posts/cpp-pragma-pack/

// warning: alignment must be a small power of two
#pragma pack(1)
class CombStruct {
 public:
  bool a;
  unsigned char b;
  int c;
  char d;

 public:
  void print_struct_size() {
    int* a_ptr;
    std::cout << "sizeof(int*) = " << sizeof(a_ptr) << std::endl;
    std::cout << "sizeof(this) = " << sizeof(this) << std::endl;
    std::cout << "sizeof(*this) = " << sizeof(*this) << std::endl;
    std::cout << "sizeof(CombStruct) = " << sizeof(CombStruct) << std::endl;

    size_t sum = sizeof(a) + sizeof(b) + sizeof(c) + sizeof(d);

    std::cout << "sizeof(each member) = ";
    std::cout << sizeof(a) << " + ";
    std::cout << sizeof(b) << " + ";
    std::cout << sizeof(c) << " + ";
    std::cout << sizeof(d) << " = ";
    std::cout << sum << std::endl;
  }
};
#pragma pack(0)

int main(int argc, char **argv) {
  CombStruct cs;
  cs.print_struct_size();

  return 0;
}
