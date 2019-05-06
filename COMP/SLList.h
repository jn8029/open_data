/**
  Assignment 1, Question 2.a, SLList.h
  Purpose: implementation of swap function in singly linked list

  @author Warren Cheng
  @version 2019.05.01
*/
#ifndef SLLIST_H
#define SLLIST_H
#include <stdexcept>
#include <iostream>
#include <limits>
using namespace std;

template <typename T>
struct Node{
  T value;
  Node<T>* next;
};
template <typename T>
class SLList{
public:
  void insert(int index, T value){
    if ((index>=count && count!=0) || (index>0 && count==0)){
      throw out_of_range("insert: index out of range");
    }
    Node<T>* newNode = new Node<T>;
    newNode->value = value;
    if (index == 0){
      newNode->next=  head;
      head = newNode;
    } else {
      Node<T>* nodeBeforeIndex = getNode(index-1);
      newNode->next = nodeBeforeIndex->next;
      nodeBeforeIndex->next = newNode;
    }
    count++;
  }
  T remove(int index){
    T removed;
    if (count==0 || index>=count){
      throw out_of_range("remove: index out of range");
    }
    if (index == 0){
      removed = head->value;
      head = head->next;
    } else {
      Node<T>* nodeBeforeIndex = getNode(index-1);
      removed = nodeBeforeIndex->next->value;
      nodeBeforeIndex->next =  nodeBeforeIndex->next->next;
    }
    count--;
    return removed;

  }
  T get(int index){
    if (count==0 || index>=count){
      throw out_of_range("get: index out of range");
    }
    T value = getNode(index)->value;
    return value;
  }
  void set(int index, T value){
    if (count==0 || index>=count){
      throw out_of_range("get: index out of range");
    }
    getNode(index)->value = value;
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
    } else if (index > 0) {
      Node<T>* nodeBeforeIndex = getNode(index-1);
      Node<T>* nodeOnIndex = nodeBeforeIndex->next;
      Node<T>* nodeAfterIndex = nodeOnIndex->next;
      nodeOnIndex->next = nodeAfterIndex->next;
      nodeBeforeIndex->next = nodeAfterIndex;
      nodeAfterIndex->next = nodeOnIndex;
    } else {
      /* edge case, index = 0, need to change head; */
      Node<T>* nodeOnIndex = head;
      Node<T>* nodeAfterIndex = nodeOnIndex->next;
      nodeOnIndex->next = nodeAfterIndex->next;
      nodeAfterIndex->next = nodeOnIndex;
      head = nodeAfterIndex;
    }
  }
  void print(){
    Node<T>* iter = new Node<T>;
    iter->next = head;
    for (size_t i =0; i < count; i++){
      iter = iter->next;
      cout << iter->value <<'\t';
    }
    cout<<endl;
  }

private:
  Node<T>* getNode(int index){
    Node<T>* iter = head;
    for (size_t i =1; i <= index; i++){
      iter = iter->next;
    }
    return iter;
  }
  Node<T>* head = nullptr;
  int count = 0;
};
#endif
