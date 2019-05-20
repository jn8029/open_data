#include <iostream>
#include <vector>
#include "binarySearchTree.h"
#include <limits>
#include <string>
#include <random>
using namespace std;

int getRandomIndex(){
  const int range_from  = 0;
  const int range_to   = 1000;
  random_device rand_dev;
  mt19937 generator(rand_dev());
  uniform_int_distribution<int> distro(range_from, range_to);
  return distro(generator);
}
int main(){
  BST<int,int> bst;
  vector<int> save;
  for (size_t i =0 ;i<10;i++){
    int key = getRandomIndex();
    cout <<"inserting "<<key<<endl;
    bst.insert(key, key);
    save.push_back(key);
  }
  bst.inOrderTraverse();
  for (auto key:save){
    cout <<"remove key "<<key<<endl;
    bst.remove(key);
    bst.inOrderTraverse();
  }
  cout <<"ok"<<endl;
}
