#include <iostream>
#include <bitset>

template <typename T>
T reverseBits(T num) {
  T reversed = 0;
  int numBits = sizeof(T) * 8;

  for (int i = 0; i < numBits; ++i) {
    if (num & (1 << i)) {
      reversed |= (1 << (numBits - 1 - i));
    }
  }

  return reversed;
}

void foo(int n) {
  if (n <= 0) return;
  foo(n - 1);
  std::cout << &n << std::endl;
}

int main() {
  unsigned int num = 43;
  std::cout << "Original: " << std::bitset<32>(num) << std::endl;
  std::cout << "Reversed: " << std::bitset<32>(reverseBits(num)) << std::endl;

  std::cout << &num << std::endl;
  foo(100);

  return 0;
}