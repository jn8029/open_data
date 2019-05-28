#include <iostream>
#include <limits>
#include <random>
#include "../catch2.hpp"
#include "binarySearchTree.h"
using namespace std;

// int getRandomIndex(){
//   const int range_from = 0;
//   const int range_to = 1000;
//   random_device rand_dev;
//   mt19937 generator(rand_dev());
//   uniform_int_distribution<int> distro(range_from, range_to);
//   return distro(generator);
// }
#define SIZE 4
TEST_CASE("initiate empty BST") {
  BST<int, int> bst;
  REQUIRE(bst.size()==0);
  REQUIRE(bst.remove(100)==false);
}
TEST_CASE("inserting numbers in sequence") {
  BST<int, int> bst;
  for (size_t i = 0; i<SIZE; i++){
    bst.insert(i,i);
    REQUIRE(bst.size() == i+1);
    cout << "height of root tree (root =" <<bst.getRoot()->value<< ") is "<<bst.height(bst.getRoot())<<endl;
    bool root_bal = bst.isBalanced(bst.getRoot());
    cout << "ROOT balanced = "<< root_bal <<endl;

  }

  for (size_t i = 0; i<SIZE; i++){
    REQUIRE(bst.search(i) == i);
  }
  for (size_t i = 0; i<SIZE; i++){
    cout << "DELTE:height of root tree (root =" <<bst.getRoot()->value<< ") is "<<bst.height(bst.getRoot())<<endl;
    bool root_bal = bst.isBalanced(bst.getRoot());
    cout << "ROOT balanced = "<< root_bal <<endl;
    REQUIRE(bst.remove(i) == true);

    REQUIRE(bst.size() == SIZE-(i+1));
  }

}
