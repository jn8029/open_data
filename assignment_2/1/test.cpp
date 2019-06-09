/**
  Assignment 2, Question 1, test.cpp
  Purpose: test inOrderNext, preOrderNext, postOrderNext methods
  @author Warren Cheng
  @version 2019.06.05
*/
#include "BST.h"
#include <random>
#include <iostream>
#include <vector>
#include "../catch2.hpp"
#define SIZE 100
using namespace std;
int getRandom(){
  const int range_from  = 0;
  const int range_to   = 1000;
  random_device rand_dev;
  mt19937 generator(rand_dev());
  uniform_int_distribution<int> distro(range_from, range_to);
  return distro(generator);
}

TEST_CASE("test a BST with random insertions of 0 ~ SIZE items") {
  for (size_t i =0; i <SIZE; i++){

    BST<int,int> bst;

    for (size_t j = 0; j<i; j++){
      int k = getRandom();
      bst.insert(k,k);

    }


    if (i==0){
      REQUIRE_THROWS(bst.getRoot());
      REQUIRE(bst.inOrderNext(nullptr)==nullptr);
      REQUIRE(bst.preOrderNext(nullptr)==nullptr);
      REQUIRE(bst.postOrderNext(nullptr)==nullptr);
    } else {
        vector<Node<int,int>*> inOrderNodeList;
        bst.inOrderTraverse(bst.getRoot(), inOrderNodeList);
        int counter= 0;
        Node<int, int>* node = inOrderNodeList[counter];
        while (counter<inOrderNodeList.size()-1){
          node = bst.inOrderNext(node);
          REQUIRE(node->key == inOrderNodeList[counter+1]->key);
          counter++;
        }

        vector<Node<int,int>*> preOrderNodeList;
        bst.preOrderTraverse(bst.getRoot(), preOrderNodeList);
        counter= 0;
        node = preOrderNodeList[counter];
        while (counter<preOrderNodeList.size()-1){
          node = bst.preOrderNext(node);
          REQUIRE(node->key == preOrderNodeList[counter+1]->key);
          counter++;
        }


        vector<Node<int,int>*> postOrderNodeList;
        bst.postOrderTraverse(bst.getRoot(), postOrderNodeList);
        counter= 0;
        node = postOrderNodeList[counter];
        while (counter<postOrderNodeList.size()-1){
          node = bst.postOrderNext(node);
          REQUIRE(node->key == postOrderNodeList[counter+1]->key);
          counter++;
        }


  }
  }
}
