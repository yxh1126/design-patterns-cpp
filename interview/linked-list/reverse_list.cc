#include <iostream>
#include <memory>

struct LinkedListNode {
  int data;
  LinkedListNode* next;
};

class LinkedList {
 public:
  void push_back(int data) {
    LinkedListNode* node = new LinkedListNode();
    node->data = data;
    node->next = head;
    head = node;
  }

  LinkedListNode* pop_node() {
    if (head == nullptr) {
      std::cout << "null" << std::endl;
      return nullptr;
    }
    std::cout << head->data << std::endl;
    head = head->next;
    return head;
  }

  void traverse() {
    print_list(this->head);
  }

  void print_list(LinkedListNode* head) {
    if (head == nullptr) {
      std::cout << "null" << std::endl;
      return;
    }

    std::cout << head->data << "-->";
    print_list(head->next);
    // std::cout << head->data << "-->";
  }

  void print_list() {
    auto* curr_node = head;

    if (curr_node == nullptr) {
      return;
    }

    while (curr_node->next != nullptr) {
      std::cout << curr_node->data << "-->";
      curr_node = curr_node->next;
    }
    std::cout << curr_node->data << "-->null" << std::endl;
  }

  void reverse_list() {
    LinkedListNode* prev = nullptr;
    LinkedListNode* curr = head;

    if (curr == nullptr) {
      return;
    }

    while (head->next != nullptr) {
      head = head->next;
      curr->next = prev;
      prev = curr;
      curr = head;
    }
    curr->next = prev;
    head = curr;
  }

 private:
  LinkedListNode* head;
};

int main(int argc, char **argv) {
  LinkedList *list = new LinkedList();
  for (int i = 0; i < 10; i++) {
    list->push_back(i);
  }
  list->print_list();

  list->reverse_list();
  list->print_list();
  list->traverse();

  while (list->pop_node() != nullptr) {}

  list->reverse_list();
  list->print_list();
}
