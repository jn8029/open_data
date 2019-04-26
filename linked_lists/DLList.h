#ifndef DLLIST_H
#define DLLIST_H
#include <iostream>
using namespace std;
template <typename T>
struct Node {
  T value;
  Node* next;
  Node* prev;
};

template <typename T>
class DLList{
public:
  DLList(){

    dummy = (struct Node<T>*)malloc(sizeof(struct Node<T>));
    dummy->next = dummy;
    dummy->prev = dummy;
  }
  T get(int i){
    T value = getNode(i)->value;
    return value;
  }
  T set(int i, T value){
    Node<T>* node = getNode(i);
    T old_value = node->value;
    node->value = value;
    return old_value;
  }
  Node<T>* getNode(int i) {
    Node<T>* node;
    if (i < elementCount / 2) {
      node = dummy->next;
      for (int j = 0; j < i; j++){
        node = node->next;
      }

    } else {
      node = dummy;
      for (int j = elementCount; j > i; j--){
        node = node->prev;
      }
    }
    return node;
  }
  Node<T>* addBefore(Node<T>* node, T value){
    struct Node<T>* addedNode;
    addedNode = (struct Node<T>*)malloc(sizeof(struct Node<T>));
    addedNode->prev = node->prev;
    addedNode->next = node;
    addedNode->next->prev = addedNode;
    addedNode->prev->next = addedNode;
    addedNode->value = value;
    elementCount++;
    return addedNode;
  }
  void removeNode(struct Node<T>* node){
    node->prev->next = node->next;
    node->next->prev = node->prev;
    elementCount--;
  }
  void add(int index, T value){
    addBefore(getNode(index), value);
  }

  T remove(int index){

    struct Node<T>* nodeToBeRemoved;
    nodeToBeRemoved = getNode(index);
    T value = nodeToBeRemoved->value;
    removeNode(nodeToBeRemoved);
    return value;
  }
  int getElementCount(){
    return elementCount;
  }
  void printAll(){
    Node<T>* node;
    node = dummy;
    for (int i = 0; i<elementCount; i++){
      node = node->next;
      cout << node->value << '\t';
    }
    cout <<endl;
  }
private:
  struct Node<T>* dummy;
  struct Node<T>* head;
  struct Node<T>* tail;
  int elementCount = 0;
};

#endif
