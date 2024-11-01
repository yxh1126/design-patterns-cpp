#include <iostream>
#include <memory>
#include <map>

struct LinkedListNode {
  int data;
  LinkedListNode* next;
  LinkedListNode* random;
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

std::map<int, int*> temp_stack() {
  std::map<int, int*> mp_space;
  int* temp;
  // int i = 0;

  for (int i = 0; i < 10; i++) {
    mp_space[i] = &i;
  }

  for (auto mp : mp_space) {
    temp = mp.second;
    std::cout << mp.first << " <---> " << temp << std::endl;
    std::cout << mp.first << " <---> " << *temp << std::endl;
  }

  std::cout << "mp.first" << " <---> " << *temp << std::endl;
  std::cout << "mp.first" << " <---> " << *temp << std::endl;
  std::cout << "mp.first" << " <---> " << *temp << std::endl;
  std::cout << "mp.first" << " <---> " << *temp << std::endl;
  std::cout << "mp.first" << " <---> " << *temp << std::endl;

  return mp_space;
}

int main(int argc, char **argv) {
  std::map<int, int*> mp_space = temp_stack();

  for (auto mp : mp_space) {
    std::cout << mp.first << " <---> " << (mp.second) << std::endl;
    std::cout << mp.first << " <---> " << *(mp.second) << std::endl;
  }

  std::cout << mp_space[299] << std::endl;
  // std::cout << nullptr << std::endl;

  if (mp_space[200] == nullptr)
    std::cout << "YES" << std::endl;
}
