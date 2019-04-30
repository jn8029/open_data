#ifndef SLQUEUE_H
#define SLQUEUE_H
#include <iostream>
using namespace std;
template <typename T>
struct Node {
  T value;
  Node* next;
};

template <typename T>
class SLQueue{
public:
  SLQueue(){
    struct Node<T>* dummy;
    dummy = (struct Node<T>*)malloc(sizeof(struct Node<T>));
    dummy->next = dummy;
    head = dummy;
    tail = dummy;

  }
  void push(T value){
    // below implementation is wrong.
    // struct Node<T> node;
    // node.value = value;
    // node.next = head;
    // head = &node;

    struct Node<T>* node;
    node = (struct Node<T>*)malloc(sizeof(struct Node<T>));
    node->value = value;
    node->next = node;
    tail->next = node;
    tail = node;
    if (elementCount==0) head = node;
    elementCount++;
  }
  T pop(){
    if (elementCount == 0){
      throw("pop: queue is empty.");
    }
    T value = head->value;
    head = head->next;
    elementCount--;
    return value;
  }
  int getElementCount(){
    return elementCount;
  }
  void printAll(){
    Node<T>* node;
    node = head;
    for (int i = 0; i<elementCount; i++){
      cout << node->value << '\t';
      node = node->next;
    }
    cout <<endl;
  }
private:
  struct Node<T>* head;
  struct Node<T>* tail;
  int elementCount = 0;
};


#endif
