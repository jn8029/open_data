#include "hashTable.h"
#include <random>
#include <iostream>
#include <vector>
#include "../catch2.hpp"
#define SIZE 10
using namespace std;
const int range_from  = 0;
const int range_to   = SIZE;
random_device rand_dev;
mt19937 generator(rand_dev());
uniform_int_distribution<int> distro(range_from, range_to);

bool naiveCheckSetsTheSame(vector<int> &s1, vector<int> &s2){
  for (auto i:s1){
    bool found = false;
    for (auto j:s2){
      if (i==j){
        found = true;
      }
    }
    if (!found) return false;
  }
  for (auto i:s2){
    bool found = false;
    for (auto j:s1){
      if (i==j){
        found = true;
      }
    }
    if (!found) return false;
  }
  return true;

}
bool checkSetsTheSame(vector<int> &s1, vector<int> &s2){
  HashTable<int> tb1;
  HashTable<int> tb2;
  cout<<"s1:"<<s1.size()<<endl;
  for (auto i:s1){
    cout<<i<<',';
    tb1.insert(i);
  }
  cout<<endl;
  cout<<"s2:"<<s2.size()<<endl;
  for (auto i:s2){
    cout<<i<<",";
    tb2.insert(i);
  }
  cout<<endl;
  if (tb1.getKeyCount() != tb2.getKeyCount()) return false;
  for (auto i: s1){
    if (!tb2.find(i)){
      return false;
    }
  }
  return true;
}

TEST_CASE(""){
  for (int test_size = 0 ; test_size<10*10; test_size ++){
    HashTable<int> tb1;
    HashTable<int> tb2;
    vector<int> s1;
    vector<int> s2;

    for (int i =0; i <test_size; i++){
      int random1 = distro(generator);
      int random2 = distro(generator);

      s1.push_back(random1);
      s2.push_back(random2);
    }

    bool theSame = checkSetsTheSame(s1,s2);
    bool naiveTheSame = naiveCheckSetsTheSame(s1,s2);
    REQUIRE(theSame == naiveTheSame);
  }



}
