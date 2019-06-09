#include <iostream>
#include <limits>
#include <random>
#include "../catch2.hpp"
#include "scapegoatTree.h"
using namespace std;

// int getRandomIndex(){
//   const int range_from = 0;
//   const int range_to = 1000;
//   random_device rand_dev;
//   mt19937 generator(rand_dev());
//   uniform_int_distribution<int> distro(range_from, range_to);
//   return distro(generator);
// }
#define SIZE 16
TEST_CASE("initiate empty SGT") {



  SGT<int, int> SGT;
  REQUIRE(SGT.size()==0);
  REQUIRE(SGT.remove(100)==false);
  // for (size_t i =0 ; i <SIZE; i++){
  //   SGT.insert(i,i);
  //
  // }
  // for (size_t i =0 ; i <SIZE; i++){
  //
  //   cout << SGT.depth(SGT.searchNode(i)) <<endl;
  //
  // }

}
TEST_CASE("inserting numbers in sequence") {
  SGT<int, int> SGT;
  for (size_t i = 0; i<SIZE; i++){
    cout<<"--------------inserting "<<i<<endl;
    SGT.insert(i,i);
    REQUIRE(SGT.size() == i+1);
    // cout<<"root = "<<SGT.getRoot()->value<<endl;
    // if (SGT.getRoot()->left){
    //   cout<<"left child = "<<SGT.getRoot()->left->value<<endl;
    // }
    // if (SGT.getRoot()->right){
    //   cout<<"right child = "<<SGT.getRoot()->right->value<<endl;
    // }
    // cout<<"root height = "<<SGT.height(SGT.getRoot())<<endl;


    bool root_bal = SGT.treeHeightBalanced();
    cout << "ROOT balanced = "<< root_bal <<endl;
    // SGT.inOrderTraverse();
    cout<<"--------------done inserting "<<i<<endl;

  }
  cout<<"done first part"<<endl;
  for (size_t i = 0; i<SIZE; i++){
    REQUIRE(SGT.search(i) == i);
  }
  for (size_t i = 0; i<SIZE; i++){
    cout << "DELTE:height of root tree (root =" <<SGT.getRoot()->value<< ") is "<<SGT.height(SGT.getRoot())<<endl;

    REQUIRE(SGT.remove(i) == true);
    bool root_bal = SGT.treeHeightBalanced();
    cout << "ROOT balanced = "<< root_bal <<endl;

    REQUIRE(SGT.size() == SIZE-(i+1));
  }

}
