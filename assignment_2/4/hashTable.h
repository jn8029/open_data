/**
  Assignment 2, Question 4, hashTable.h
  Purpose: implement a hashtable with linear probing
  @author Warren Cheng
  @version 2019.06.05
*/
#ifndef HASHT_H
#define HASHT_H

#include <iostream>
#include <limits>
#include <bitset>
#include <string>

using namespace std;
struct Node{
  int key;
  bool isDeleted;
};

class HashTable {
public:
  HashTable(){
    this->array = new Node*[arraySize]();
  }
  bool insert(int key){
    if (exists(key)){
      // if key already exists, nothing can be inserted, return false
      return false;
    }
    // if non null count is more than half of the array size, resize
    if (2*(nonNullCount+1) > arraySize) resize();
    size_t hashed_key = hash(key);
    Node* node= new Node;
    node->key = key;
    node->isDeleted = false;
    while (array[hashed_key]!=nullptr && array[hashed_key]->isDeleted==false){
      // linear probing, if the node is not null and the node is not deleted
      // it means that the position is occupied, so hashed_key is incremented to probe the next spot
      hashed_key = (hashed_key + 1) % arraySize;
    }
    // cout to check if the location is stored correctly
    std::cout<<"item "<<key<<" is stored at index "<<hashed_key<<std::endl;
    array[hashed_key] = node;
    count++;
    nonNullCount++;
    return true;
  }
  bool remove(int key){
    size_t hashed_key = hash(key);
    //while the location is not null, it means we need to check if the key is found here
    while(array[hashed_key]!=nullptr){
      //if the node is not deleted and the key matches, we have found the node
      if(array[hashed_key]->isDeleted != true && array[hashed_key]->key==key){

        array[hashed_key]->isDeleted = true;
        count--;
        //after deletion , check if the occupancy is smaller than 12.5% of array size, if so, resize
        if (8 * count < arraySize) resize();// min 12.5% occupancy
        return true;
      }
      //if search has reached the end of the array, start from 0
      if (hashed_key == arraySize-1){

        hashed_key = 0;
      } else {
        hashed_key ++;
      }
    }
    return false;
  }
  bool exists(int key){
    size_t hashed_key = hash(key);
    while(array[hashed_key]!=nullptr){
      if (array[hashed_key]->key==key && array[hashed_key]->isDeleted != true){
        return true;
      }
      hashed_key = (hashed_key+1)%arraySize;
    }
    return false;
  }

private:
  void resize(){
    std::cout<<"resizing"<<std::endl;
    int d = 0;
    // find d where 2^d < 3 * count, use << bit left shift
    while((1<<d) < 3*count) d++;
    int newArraySize = 1<<d;
    Node** newArray = new Node*[newArraySize]();


    std::cout<<"new array size = "<<newArraySize<<std::endl;
    for (size_t i = 0; i < arraySize; i++){
      //mode the node to the new array, skip those that are null or deleted
      if (array[i]!=nullptr && array[i]->isDeleted!=true){

        newArray[i] = array[i];

      }
    }
    arraySize = newArraySize;
    nonNullCount = count;
    array = newArray;
  }
  int hash(int key){
    return key%13;
  }
  int arraySize = 16;
  int count = 0;
  int nonNullCount=0;
  Node** array;
};


#endif
