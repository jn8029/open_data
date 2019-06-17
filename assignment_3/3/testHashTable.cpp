#include "hashTable.h"
#include <random>
#include <iostream>
#include <vector>
#include "../catch2.hpp"
#define SIZE 100
using namespace std;
const int range_from  = 0;
const int range_to   = SIZE;
random_device rand_dev;
mt19937 generator(rand_dev());
uniform_int_distribution<int> distro(range_from, range_to);



TEST_CASE(""){
  HashTable<int> tb1;
  for (int i =0 ; i < SIZE; i++){
    tb1.insert(i);
    REQUIRE(tb1.find(i)==true);
  }
}
