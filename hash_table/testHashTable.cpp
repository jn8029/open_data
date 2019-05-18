
#include "../catch2.hpp"
#include "hashTable.h"
#include <iostream>
using namespace std;


TEST_CASE("initiate empty Queue") {
  HashTable<int, int> map;
  for (int i = 0 ; i <10; i++){
    int* key = new int;
    *key = i;
    int* v = new int;
    *v = 0;
    map.insert(*key, *v);
  }



}
