#include <iostream>
#include <limits>
#include <random>
#include "../catch2.hpp"
#include "AVLTree.h"
using namespace std;

// int getRandomIndex(){
//   const int range_from = 0;
//   const int range_to = 1000;
//   random_device rand_dev;
//   mt19937 generator(rand_dev());
//   uniform_int_distribution<int> distro(range_from, range_to);
//   return distro(generator);
// }
#define SIZE 1024
TEST_CASE("initiate empty AVLTree") {
  AVLTree<int, int> AVLTree;
  REQUIRE(AVLTree.size()==0);
  REQUIRE(AVLTree.remove(100)==false);
}
TEST_CASE("inserting numbers in sequence") {
  AVLTree<int, int> AVLTree;
  for (size_t i = 0; i<SIZE; i++){
    AVLTree.insert(i,i);
    REQUIRE(AVLTree.size() == i+1);
    REQUIRE(AVLTree.isBalanced(AVLTree.getRoot())==true);


  }

  for (size_t i = 0; i<SIZE; i++){
    REQUIRE(AVLTree.search(i) == i);
  }
  for (size_t i = 0; i<SIZE; i++){
    bool root_bal = AVLTree.isBalanced(AVLTree.getRoot());
    REQUIRE(AVLTree.remove(i) == true);
    REQUIRE(AVLTree.size() == SIZE-(i+1));
    REQUIRE(AVLTree.isBalanced(AVLTree.getRoot())==true);
    cout <<"height is "<<AVLTree.height(AVLTree.getRoot())<<endl;
  }

}
