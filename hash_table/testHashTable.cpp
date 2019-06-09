
#include "../catch2.hpp"
#include "hashTable.h"
#include <iostream>
using namespace std;


TEST_CASE("initiate empty Queue") {
  HashTable<int, int> map;
  for (int i = 0 ; i <10; i++){
    int* key = new int;
    *key = i;
    cout <<"address of key "<<i<< "is "<<key<<endl;
    int* v = new int;
    *v = i;
    map.insert(*key, *v);
    int found = map.find(*key);
    cout <<" found "<< found<<endl;
  }





}
