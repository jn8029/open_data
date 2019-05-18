#ifndef PQUEUE_H
#define PQUEUE_H

#include <iostream>
#include <limits>
#include "DLList.h"
#include <bitset>
#include <string>

using namespace std;

template <typename value_type>
struct Pair{
  unsigned long long key;
  value_type* value;
};

template <typename key_type, typename value_type>
class HashTable {
public:
  HashTable(){
    for (size_t i =0; i<arraySize; i++){
      DLList<Pair<value_type>*>* dllist = new DLList<Pair<value_type>*>;
      array[i] = dllist;
    }
  }
  void insert(key_type &key, value_type& value){
    cout <<"address is "<<(unsigned long long int)&key<<endl;
    unsigned long long int hash_value = hash((unsigned long long)&key);
    size_t bucket = hash_value%arraySize;
    struct Pair<value_type>* pair= new Pair<value_type>;
    pair->key = hash_value;
    pair->value = &value;
    array[bucket]->insert(0, pair);
    cout <<"bucket is "<<bucket<<endl;
  }
  value_type find(key_type &key){
    cout <<"address is "<<(unsigned long long int)&key<<endl;
    size_t bucket = hash((unsigned long long)&key);
    if (array[bucket]->size()==0){
      cout <<"key doesnt exist";
    } else{


    }

  }

private:
  unsigned long long int hash(unsigned long long key){

    return ((key*2654435761)>>22);

  }

  int arraySize = 1024;
  DLList<Pair<value_type>*>* array[1024];


};


#endif
