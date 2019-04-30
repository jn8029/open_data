#ifndef PQUEUE_H
#define PQUEUE_H

#include <iostream>
#include <limits>
using namespace std;
struct Node {
  int value;
  Node* next;

};

class PriorityQueue{
public:
  void add(int value){
    Node* newNode = new struct Node;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
    elementCount++;
  }
  int deleteMin(){
    if (elementCount==0){
      throw("deleteMin: queue is empty.");
    }
    int min = numeric_limits<int>::max();
    Node* nodeBeforeMin;
    Node* dummy = new Node;
    dummy->next = head;
    for (size_t i =0; i< elementCount; i++){
      if (dummy->next->value < min){
        min = dummy->next->value;
        nodeBeforeMin = dummy;
      }
      dummy = dummy->next;
    }
    ///bug found: edge case, if first is min...
    if (nodeBeforeMin->next == head){
      head = head->next;
    } else {
      nodeBeforeMin->next = nodeBeforeMin->next->next;

    }


    elementCount--;
    return min;
  }
  int size(){
    return elementCount;
  }
  void print(){
    Node* iter = head;
    for (size_t i = 0 ; i < elementCount ; i++){
      cout<< iter->value << '\t';
      iter = iter->next;
    }
    cout<<endl;
  }
private:
  Node* head = nullptr;
  int elementCount = 0;

};


#endif
