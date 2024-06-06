class Rectangle {
 private:
  int length;
  int breadth;
};

void fun() {
  // By taking a pointer p and
  // dynamically creating object
  // of class rectangle
  Rectangle* p = new Rectangle();
}

int main(int argc, char **argv) {
  // Infinite Loop
  while (1) {
    fun();
  }
}
