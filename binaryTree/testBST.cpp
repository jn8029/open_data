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
#define SIZE 100
TEST_CASE("initiate empty BST") {
  BST<int, int> bst;
  REQUIRE(bst.size()==0);
  REQUIRE(bst.remove(100)==false);
}
TEST_CASE("inserting numbers in sequence") {
  BST<int, int> bst;
  for (size_t i = 0; i<SIZE; i++){
    bst.insert(i,i+10);
    REQUIRE(bst.size() == i+1);
  }
  for (size_t i = 0; i<SIZE; i++){
    REQUIRE(bst.search(i) == i+10);
  }
  for (size_t i = 0; i<SIZE; i++){
    REQUIRE(bst.remove(i) == true);
    REQUIRE(bst.size() == SIZE-(i+1));
  }

}
