/*
  30-31(2bit)   27-29 (3bit) 24-26 (3bit)  20-23 (4bit)  4-19 (16bit)   0-3(4bit)
------------------------------------------------------------------------------------
| Message ID |  Num Packets | Packet ID |  Permissions  |  Data Frame | Error Code |
------------------------------------------------------------------------------------
      0            2            0              1           0x1122         0
      0            0            1              0           0x3344         0

*/

#include <iostream>
#include <cstdint>
#include <bitset>

struct DataPack {
  // first come is the LSB (least significance bit)
  uint32_t error_code  : 4;    // 0 - 3 bit
  uint32_t data_frame  : 16;
  uint32_t permissions : 4;
  uint32_t packet_id   : 3;
  uint32_t num_packs   : 3;
  uint32_t msg_id      : 2;    // 30 - 31 bit
  // last come is the MSB (most significance bit)
};

union DataPackWrap {
  DataPack frame;
  uint32_t raw_data;
};

void using_bit_shift(uint32_t raw_frame) {
  uint32_t msg_id = (raw_frame >> 30) & 0b11;
  uint32_t num_packs = (raw_frame >> 27) & 0b111;
  uint32_t packet_id = (raw_frame >> 24) & 0b111;
  uint32_t permissions = (raw_frame >> 20) & 0b1111;

  std::cout << std::hex << "MSG_ID: 0b" << std::bitset<2>(msg_id) << std::endl;
  std::cout << std::hex << "NUM_PK: 0b" << std::bitset<3>(num_packs) << std::endl;
  std::cout << std::hex << "PAK_ID: 0b" << std::bitset<3>(packet_id) << std::endl;
  std::cout << std::hex << "PEMMIS: 0b" << std::bitset<4>(permissions) << std::endl;
}

void print_uint32_bits(uint32_t num) {
  std::cout << "0b";
  for (int i = 31; i >= 0; i--) {
    bool is_true = ((num & (1 << i)) != 0);
    if (is_true) {
      std::cout << 1;
    } else {
      std::cout << 0;
    }
  }
  std::cout << std::endl;
}

int main(int argc, char **argv) {
  DataPack frame;
  frame.error_code = 0x00;
  frame.data_frame = 0x3344;
  frame.permissions = 0b1011;
  frame.packet_id = 0x01;
  frame.num_packs = 0x02;
  frame.msg_id = 0b10;

  DataPackWrap wrap;
  wrap.frame = frame;

  std::cout << sizeof(frame) << std::endl;
  std::cout << std::hex << "0x" << wrap.raw_data << std::endl;
  print_uint32_bits(wrap.raw_data);
  std::cout << "0b" << std::bitset<sizeof(uint32_t) * 8>(wrap.raw_data) << std::endl;

  uint32_t raw_data = wrap.raw_data;
  uint8_t* view = (uint8_t*) (&raw_data);

  // x86 arch using little-endian byte ordering
  // means: index 0 (which is little) locate at the end of the value
  std::cout << "0b" << std::bitset<8>(*(view + 0)) << std::endl;
  std::cout << "0b" << std::bitset<8>(*(view + 1)) << std::endl;
  std::cout << "0b" << std::bitset<8>(*(view + 2)) << std::endl;
  std::cout << "0b" << std::bitset<8>(*(view + 3)) << std::endl;

  std::cout << std::dec << int(*view) << std::endl;

  // Index 0 is come at the first position (left side) of the array
  int arry[3] = {100, 200, 300};
  std::cout << arry[0] << std::endl;

  using_bit_shift(raw_data);
}
