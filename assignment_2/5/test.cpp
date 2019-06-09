/**
  Assignment 2, Question 5, test.cpp
  Purpose: test preOrderNumber, postOrderNumber and inOrderNumber that assigns individual sequencial numbers based on the traversal algorithms.
  @author Warren Cheng
  @version 2019.06.05
*/
#include "BST.h"
#include <random>
#include <iostream>
#include <vector>
#include "../catch2.hpp"
#define SIZE 1000
using namespace std;
int getRandomIndex(){
  const int range_from  = 0;
  const int range_to   = 100;
  random_device rand_dev;
  mt19937 generator(rand_dev());
  uniform_int_distribution<int> distro(range_from, range_to);
  return distro(generator);
}
TEST_CASE("test with trees sizes from 0 to 1000"){
  for (size_t size =0; size<SIZE; size++){
    vector<Node<int,int>*> preOrderNodeList;
    vector<Node<int,int>*> inOrderNodeList;
    vector<Node<int,int>*> postOrderNodeList;
    BST<int,int> bst;
    for (size_t i = 0; i<size; i++){
      int k = getRandomIndex();
      bst.insert(k,i);

    }
    bst.inOrderNumber();
    bst.preOrderNumber();
    bst.postOrderNumber();

    bst.inOrderTraverse(bst.getRoot(), inOrderNodeList);
    for (size_t i =0 ; i < inOrderNodeList.size(); i++){
      REQUIRE(i == inOrderNodeList[i]->inOrderNum);
    }
    bst.preOrderTraverse(bst.getRoot(), preOrderNodeList);
    for (size_t i =0 ; i < preOrderNodeList.size(); i++){
      REQUIRE(i == preOrderNodeList[i]->preOrderNum);
    }
    bst.postOrderTraverse(bst.getRoot(), postOrderNodeList);
    for (size_t i =0 ; i < postOrderNodeList.size(); i++){
      REQUIRE(i== postOrderNodeList[i]->postOrderNum);
    }

  }



}
