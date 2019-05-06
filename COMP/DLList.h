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
  void insert(int index, T value){
    if ((index>=count && count!=0) || (index>0 && count==0)){
      throw out_of_range("insert: index out of range");
    }
    addBefore(getNode(index), value);
  }
  T remove(int index){
    if (count==0 || index>=count){
      throw out_of_range("remove: index out of range");
    }
    struct Node<T>* nodeToBeRemoved;
    nodeToBeRemoved = getNode(index);
    T value = nodeToBeRemoved->value;
    removeNode(nodeToBeRemoved);
    return value;
  }
  T get(int index){
    if (count==0 || index>=count){
      throw out_of_range("get: index out of range");
    }
    T value = getNode(index)->value;
    return value;
  }
  T set(int index, T value){
    if (count==0 || index>=count){
      throw out_of_range("get: index out of range");
    }
    Node<T>* node = getNode(index);
    T old_value = node->value;
    node->value = value;
    return old_value;
  }
  int size(){
    return count;
  }
  void swap(int index){
    /*
      implementation of element swap between index and index+1

      edge case: index>=count-1, the biggest input acceptable is count-2, so that
      count-2 and count-1 can be swapped, and count-1 is the biggest index that is
      not out of range.
    */
    if (index>=count-1 || index<0){
      throw out_of_range("swap: no element after index location to swap with.");
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
  void reverse(){
    Node<T>* node;
    node = dummy;
    for (int i = 0; i<count+1; i++){
      Node<T>* temp;
      temp = node->next;
      node->next = node->prev;
      node->prev = temp;
      node = temp;
    }
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
