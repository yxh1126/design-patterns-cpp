/*
We have a special hardware component that we need to integrate with the main
computer that is running other components of our stack. This new hardware
component will message the main compute unit, using the protocol below, to
create a new file. Below are the specifications of the protocol and two example
packets that together form a full message:


  30-31(2bit)   27-29 (3bit) 24-26 (3bit)  20-23 (4bit)  4-19 (16bit)   0-3(4bit)
------------------------------------------------------------------------------------
| Message ID |  Num Packets | Packet ID |  Permissions  |  Data Frame | Error Code |
------------------------------------------------------------------------------------
      0            2            0              1           0x1122         0
      0            0            1              0           0x3344         0

Example full-file name (“Data Frame” field) received over 2 packets (ASCII-encoded):
0x11223344

On the first packet of a message received, bits 27-29 will indicate the number
of packets that will be in the complete request message. In the following packets
for this message these bits will be cleared. Likewise, bits 20-23 of the first
packet will indicate the permissions to create the file with:

0000 - Read-only
0001 - Read-write

The aggregation of the data frames will dictate the filename to create on disk.
Each letter of the final filename will be encoded in ASCII in the data frame.
The least significant bit is the 0th bit.

For the purposes of this interview, we’ve provided a create_file() function that
you will call to create the file.

*/
