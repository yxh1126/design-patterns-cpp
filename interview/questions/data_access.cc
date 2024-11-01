#include <iostream>

#define N   101
#define RAW -1

class NumStoreSet {
 public:
  NumStoreSet() : cnt_{0} {
    for (int i = 0; i < N; i++) {
      map_[i] = RAW;
      key_[i] = RAW;
    }
  }

  ~NumStoreSet() {
    for (int i = 0; i < 10; i++) {
      std::cout << i << "\t";
    }
    std::cout << std::endl;

    for (int i = 0; i < 10; i++) {
      std::cout << map_[i] << "\t";
    }
    std::cout << std::endl;

    for (int i = 0; i < 10; i++) {
      std::cout << key_[i] << "\t";
    }
    std::cout << std::endl;
  }

  // The key is also the value
  void Insert(int n) {
    if (!ValidCheck(n)) return;
    if (!Find(n)) {
      // key : index
      int value = key_[cnt_];
      if (value != RAW) {
        // clear value
        map_[value] = RAW;
      }
      map_[n] = cnt_;
      // index : value
      key_[cnt_] = n;
      cnt_++;
    }
  }

  void Remove(int n) {
    if (!ValidCheck(n)) return;
    if (Find(n)) {
      int idx = map_[n];
      map_[n] = RAW;
      if (idx != cnt_ - 1) {
        key_[idx] = key_[cnt_ - 1];
        map_[key_[idx]] = idx;
      }
      cnt_--;
    }
  }

  bool Find(int n) {
    if (!ValidCheck(n)) return false;
    if (cnt_ == 0) return false;
    return (map_[n] < cnt_ && map_[n] >= 0);
  }

  void Clear() {
    cnt_ = 0;
  }

  int Size() {
    return cnt_;
  }

  void PrintInfo(const std::string& info) {
    std::cout << info << std::endl;
    std::cout << Size() << std::endl;
  }

 private:
  static constexpr const char* kClassName = "NumStoreSet";
  int map_[N];
  int key_[N];
  int cnt_;

  bool ValidCheck(int n) {
    if (n <= 0 || n >= 101) return false;
    return true;
  }
};

int main() {
  NumStoreSet n;
  n.Insert(5);
  n.Insert(4);
  n.Insert(6);

  n.Clear();
  n.Insert(4);

  if (n.Find(5) || n.Find(4)) {
    n.PrintInfo("Find");
  }
  return 0;
}
