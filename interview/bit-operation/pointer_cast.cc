#include <iostream>
#include <cstdint>

// If comment using command below for compailation:
// g++ pointer_cast.cc -DARCH64

// #define ARCH64

#ifdef ARCH64
#define BUFSIZE 4
#else
#define BUFSIZE 2
#endif

union CombVar {
#ifdef ARCH64
  uint32_t vars;
#else
  uint16_t vars;
#endif
  char chars[BUFSIZE];
};

void uint32_pointer_cast(uint32_t vars) {
  char *w_ptr = (char*) &vars;
  for (int i = BUFSIZE - 1; i >= 0; i--) {
    std::cout << w_ptr[i];
  }
}

int main(int argc, char **argv) {
  std::string word = "puppys";
  CombVar comb[3];

  // Init the data structure
  for (int i = 0; i < 3; i++) {
    comb[i].vars = 0x00;
  }

  // Fill the uint32_t with data
  for (int i = 0; i < word.length(); i++) {
    comb[i / 2].chars[BUFSIZE - 1 - (i % 2)] = word.at(i);
  }

  // Print out the value as dec and hex
  for (int i = 0; i < 3; i++) {
    std::cout << std::dec << comb[i].vars << std::endl;
    std::cout << std::hex << "0x" << comb[i].vars << std::endl;
  }

  // Convert the uint32 data back to char
  for (int i = 0; i < 3; i++) {
    uint32_pointer_cast(comb[i].vars);
  }

  std::cout << std::endl;
}
