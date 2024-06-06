/*
 *  T9 stands for Text on 9 keys.
 *  Give an input as a series of number, and return the result
 *  as a list of word that match the input
 *
 *  The keyboard layout looks like this:
 *  [a, b, c]    --> 2
 *  [d, e, f]    --> 3
 *  [g, h, i]    --> 4
 *  [j, k, l]    --> 5
 *  [m, n, o]    --> 6
 *  [p, q, r, s] --> 7
 *  [t, u, v]    --> 8
 *  [w, x, y, z] --> 9
 *
 *  Give an input:
 *  [2, 2, 8] --> ["cat", "bat"]
 *  [7, 4, 6] --> ["sim"]
 *  [9, 6, 2, 4, 6, 4] --> ["woaini"]
 */

#include <iostream>
#include <vector>

std::vector<std::string> word_dic = {"cat", "bat", "sim", "woaini"};

std::string map_num_to_char(int n) {
  switch (n) {
    case 2:
      return "abc";

    case 3:
      return "def";

    case 4:
      return "ghi";

    case 5:
      return "jkl";

    case 6:
      return "mno";

    case 7:
      return "pqrs";

    case 8:
      return "tuv";

    case 9:
      return "wxyz";

    default:
      return "";
  }
}

int map_char_to_num(char c) {
  switch (c) {
    case 'a':
    case 'b':
    case 'c':
      return 2;

    case 'd':
    case 'e':
    case 'f':
      return 3;

    case 'g':
    case 'h':
    case 'i':
      return 4;

    case 'j':
    case 'k':
    case 'l':
      return 5;

    case 'm':
    case 'n':
    case 'o':
      return 6;

    case 'p':
    case 'q':
    case 'r':
    case 's':
      return 7;

    case 't':
    case 'u':
    case 'v':
      return 8;

    case 'w':
    case 'x':
    case 'y':
    case 'z':
      return 9;

    default:
      return -1;
  }
}

std::vector<std::string> number_to_word(std::vector<int>& dial_num) {
  std::vector<std::string> res;
  int dial_len = dial_num.size();

  for (std::string& word : word_dic) {
    if (word.length() == dial_len) {
      int match = 0;

      for (int i = 0; i < dial_len; i++) {
        int target = map_char_to_num(word.at(i));
        if (target == dial_num[i]) {
          match++;
        } else {
          // std::cout << "break: " << target << std::endl;
          break;
        }
      }

      if (match == dial_len) {
        res.push_back(word);
      }
    } else {
      // do nothing
    }
  }

  return res;
}

int main(int argc, char **argv) {
  std::vector<int> in = {2, 2, 8};
  std::vector<std::string> res = number_to_word(in);

  for (std::string r : res) {
    std::cout << r << std::endl;
  }
}
