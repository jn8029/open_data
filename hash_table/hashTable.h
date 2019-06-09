#ifndef PQUEUE_H
#define PQUEUE_H

#include <iostream>
#include <limits>
#include <bitset>
#include <string>

using namespace std;

template <typename value_type>
struct Node{
  unsigned long long key;
  value_type* value;
  Node<value_type>* next;
  Node<value_type>* prev;
};

template <typename key_type, typename value_type>
class HashTable {
public:
  HashTable(){
    this->array = new Node<value_type>*[arraySize];
    for (size_t i =0; i<arraySize; i++){
      this->array[i] = new Node<value_type>;
      this->array[i]->prev = this->array[i];
      this->array[i]->next = this->array[i];
    }
  }
  void insert(key_type &key, value_type& value){
    cout <<"address is "<<(unsigned long long int)&key<<endl;
    size_t bucket = hash((unsigned long long)&key);
    Node<value_type>* node= new Node<value_type>;
    node->key = key;
    node->value = &value;
    node->prev = array[bucket];
    node->next = array[bucket];
    array[bucket] = node;
  }
  value_type find(key_type &key){
    cout <<"address is "<<(unsigned long long int)&key<<endl;
    size_t bucket = hash((unsigned long long)&key);
    Node<value_type>* listTraverser = array[bucket];
    while (listTraverser->next != listTraverser){

      if (listTraverser->key == key){
          return *(listTraverser->value);
      }
    }
    throw out_of_range("find: key does not exists.");
  }

private:
  unsigned long long int hash(unsigned long long key){

    return ((key*2654435761)>>22)%arraySize;

  }

  int arraySize = 16;
  Node<value_type>** array;


};


#endif
