#ifndef PQUEUE_H
#define PQUEUE_H

#include <iostream>
#include <limits>
#include <bitset>
#include <string>

using namespace std;

template <typename key_type>
struct Node{
  unsigned long long key;
  Node<key_type>* next;
};

template <typename key_type>
class HashTable {
public:
  HashTable(){
    this->array = new Node<key_type>*[arraySize];
    for (size_t i =0; i<arraySize; i++){
      this->array[i] = nullptr;
    }
  }
  bool insert(key_type &key){
    if (find(key)){
      return false;
    }
    size_t bucket = hash((unsigned long long)key);
    // cout<<"bucket ="<<bucket<<", key = "<<key<<endl;
    Node<key_type>* node= new Node<key_type>;
    node->key = key;
    node->next = array[bucket];
    array[bucket] = node;
    keyCount++;
    return true;
  }
  bool find(key_type &key){
    if (keyCount==0) return false;
    size_t bucket = hash((unsigned long long)key);
    Node<key_type>* listTraverser = array[bucket];
    while (listTraverser!=nullptr){
      if (listTraverser->key == key){
          return true;
      }
      listTraverser = listTraverser->next;
    }
    return false;
  }
  int getKeyCount(){
    return keyCount;
  }

private:
  unsigned long long int hash(unsigned long long key){
    return ((key*2654435761)>>22)%arraySize;
  }

  int arraySize = 16;
  int keyCount = 0;
  Node<key_type>** array;


};


#endif
