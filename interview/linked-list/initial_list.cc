#include <iostream>
#include <memory>

struct LinkedListNode {
  int data;
  std::unique_ptr<LinkedListNode> next;
};

class LinkedList {
 public:
  void push_back(int data) {
    if (head == nullptr) {
      head = std::make_unique<LinkedListNode>();
      head->data = data;
    } else {
      std::unique_ptr<LinkedListNode> node = std::make_unique<LinkedListNode>();
      node->data = data;
      node->next = std::move(head);
      head = std::move(node);
    }
  }

  void print_list() {
    auto* head_ptr = head.get();
    while (head_ptr->next != nullptr) {
      std::cout << head_ptr->data << "-->";
      head_ptr = (head_ptr->next).get();
    }
    std::cout << "null" << std::endl;
  }

 private:
  std::unique_ptr<LinkedListNode> head;
};

int main(int argc, char **argv) {
  std::unique_ptr<LinkedListNode> p = std::make_unique<LinkedListNode>();
  p->data = 100;
  std::unique_ptr<LinkedListNode> q = std::move(p);
  std::cout << q->data << std::endl;

  // Will have 'Segmentation fault'
  // std::cout << p->data << std::endl;
  LinkedList *list = new LinkedList();
  for (int i = 0; i < 10; i++) {
    list->push_back(i);
  }

  list->print_list();
}
