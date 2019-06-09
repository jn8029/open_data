/**
  Assignment 2, Question 2, test.cpp
  Purpose: tests isBST method to check if the tree satisfied the property of a BST
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
int getRandomIndex(){
  const int range_from  = 0;
  const int range_to   = SIZE;
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
    cout<<endl;

    if (i==0){
      REQUIRE_THROWS(bst.getRoot());
    } else {
      REQUIRE(bst.isBST(bst.getRoot())==true);
      int randomIndex = getRandomIndex();
      Node<int, int>* randomNode = bst.searchNode(randomIndex);
      if (randomNode==bst.getRoot() && i == 1){
        //if randomNode is root and tree size is 1, it is always BST and no manipulation can be
        //done to make it non BST
        REQUIRE(bst.isBST(bst.getRoot())==true);
      } else{
        //manipulating a key of a random node so that the BST becomes
        //not BST
        if (randomNode->left){
          //if randomNode has left child, manipulate left child key to be bigger
          randomNode->left->key = randomNode->key+10000;
        } else if (randomNode->right){
          //if randomNode has right child, manipulate right child key to be smaller
          randomNode->right->key = randomNode->key-10000;
        } else if (randomNode->parent && randomNode->parent->left == randomNode){
          //if randomNode has parent and randomNode is left child, manipulate parent key to be smaller
          randomNode->parent->key = randomNode->key-10000;
        } else if (randomNode->parent && randomNode->parent->right == randomNode){
          // if randomNode has parent and randomNode is right child, manipulate parent key to be bigger
          randomNode->parent->key = randomNode->key+10000;
        }
        REQUIRE(bst.isBST(bst.getRoot())==false);
      }




    }
  }
}
