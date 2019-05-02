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
    if (count==0 || i>=count){
      throw("get: index out of bound.");
    }
    T value = getNode(i)->value;
    return value;
  }
  T set(int i, T value){
    Node<T>* node = getNode(i);
    T old_value = node->value;
    node->value = value;
    return old_value;
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
  int size(){
    return count;
  }
  void print(){
    Node<T>* node;
    node = dummy;
    for (int i = 0; i<count; i++){
      node = node->next;
      cout << node->value << '\t';
    }
    cout <<endl;
  }
  void swap(int index){
    /*
      implementation of element swap between index and index+1

      edge case: index>=count-1, the biggest input acceptable is count-2, so that
      count-2 and count-1 can be swapped, and count-1 is the biggest index that is
      not out of range.
    */
    if (index>=count-1 || index<0){
      throw("swap: no element after index location to swap with.");
    } else if (index >= 0) {
      Node<T>* nodeOnIndex = getNode(index);
      Node<T>* nodeBeforeIndex = nodeOnIndex->prev;
      Node<T>* nodeAfterIndex = nodeOnIndex->next;
      Node<T>* nodeAfter2Index = nodeAfterIndex->next;

      nodeBeforeIndex->next = nodeAfterIndex;
      nodeAfter2Index->prev = nodeOnIndex;

      nodeAfterIndex->next = nodeOnIndex;
      nodeAfterIndex->prev = nodeBeforeIndex;

      nodeOnIndex->next = nodeAfter2Index;
      nodeOnIndex->prev = nodeAfterIndex;

    }

  }

private:
  struct Node<T>* dummy;
  int count = 0;
  Node<T>* getNode(int i) {
    Node<T>* node;
    if (i < count / 2) {
      node = dummy->next;
      for (int j = 0; j < i; j++){
        node = node->next;
      }

    } else {
      node = dummy;
      for (int j = count; j > i; j--){
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
    count++;
    return addedNode;
  }
  void removeNode(struct Node<T>* node){
    node->prev->next = node->next;
    node->next->prev = node->prev;

    count--;
  }

};

#endif
