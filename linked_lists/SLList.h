/**
  Assignment 1, Question 2.a, SLList.h
  Purpose: implementation of swap function in singly linked list

  @author Warren Cheng
  @version 2019.05.01
*/
#ifndef SLLIST_H
#define SLLIST_H

#include <iostream>
#include <limits>
using namespace std;


struct Node{
  int value;
  Node* next;
};
class SLList{
public:
  void insert(int index, int value){
    if (index>=count && count!=0){
      cout<<"insert: index out of range."<<endl;
      return;
    }
    Node* newNode = new Node;
    newNode->value = value;
    if (index == 0){
      newNode->next=  head;
      head = newNode;
    } else {
      Node* nodeBeforeIndex = getNode(index-1);
      newNode->next = nodeBeforeIndex->next;
      nodeBeforeIndex->next = newNode;
    }
    count++;
  }
  void print(){
    Node* iter = new Node;
    iter->next = head;
    for (size_t i =0; i < count; i++){
      iter = iter->next;
      cout << iter->value <<'\t';
    }
    cout<<endl;
  }
  int get(int index){
    if (count==0 || index>=count){
      throw("get: index out of range");
    }
    int value = getNode(index)->value;
    return value;
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
      throw("swap: no element after index location to swap with.");
    } else if (index > 0) {
      Node* nodeBeforeIndex = getNode(index-1);
      Node* nodeOnIndex = nodeBeforeIndex->next;
      Node* nodeAfterIndex = nodeOnIndex->next;
      nodeOnIndex->next = nodeAfterIndex->next;
      nodeBeforeIndex->next = nodeAfterIndex;
      nodeAfterIndex->next = nodeOnIndex;
    } else {
      /* edge case, index = 0, need to change head; */
      Node* nodeOnIndex = head;
      Node* nodeAfterIndex = nodeOnIndex->next;
      nodeOnIndex->next = nodeAfterIndex->next;
      nodeAfterIndex->next = nodeOnIndex;
      head = nodeAfterIndex;
    }
  }

private:
  Node* getNode(int index){
    Node* iter = head;
    for (size_t i =1; i <= index; i++){
      iter = iter->next;
    }
    return iter;
  }
  Node* head = nullptr;
  int count = 0;
};
#endif
