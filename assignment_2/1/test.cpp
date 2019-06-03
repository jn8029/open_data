#include "BST.h"
#include <random>
#include <iostream>
#include <vector>
#include "../../catch2.hpp"
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

TEST_CASE("test inOrderNext") {
  vector<Node<int,int>*> inOrderNodeList;
  BST<int,int> bst;
  cout<<"Inserting..."<<endl;
  for (size_t i = 0; i<SIZE; i++){
    int k = getRandom();
    bst.insert(k,i);
    cout<<k<<'\t';
  }
  bst.inOrderTraverse(bst.getRoot(), inOrderNodeList);
  int counter= 0;
  Node<int, int>* node = inOrderNodeList[counter];
  while (counter<inOrderNodeList.size()-1){
    node = bst.inOrderNext(node);
    REQUIRE(node->key == inOrderNodeList[counter+1]->key);
    counter++;
  }
}
TEST_CASE("test preOrderNext") {
  vector<Node<int,int>*> preOrderNodeList;
  BST<int,int> bst;
  cout<<"Inserting..."<<endl;
  for (size_t i = 0; i<SIZE; i++){
    int k = getRandom();
    bst.insert(k,i);
    cout<<k<<'\t';
  }
  bst.preOrderTraverse(bst.getRoot(), preOrderNodeList);
  int counter= 0;
  Node<int, int>* node = preOrderNodeList[counter];
  while (counter<preOrderNodeList.size()-1){
    node = bst.preOrderNext(node);
    REQUIRE(node->key == preOrderNodeList[counter+1]->key);
    counter++;
  }
}

TEST_CASE("test postOrderNext") {
  vector<Node<int,int>*> postOrderNodeList;
  BST<int,int> bst;
  cout<<"Inserting..."<<endl;
  for (size_t i = 0; i<SIZE; i++){
    int k = getRandom();
    bst.insert(k,i);
    cout<<k<<'\t';
  }
  bst.postOrderTraverse(bst.getRoot(), postOrderNodeList);
  int counter= 0;
  Node<int, int>* node = postOrderNodeList[counter];
  while (counter<postOrderNodeList.size()-1){
    node = bst.postOrderNext(node);
    REQUIRE(node->key == postOrderNodeList[counter+1]->key);
    counter++;
  }
}
// int main(){
//
//     vector<Node<int,int>*> inOrderNodeList;
//     vector<Node<int,int>*> postOrderNodeList;
//     BST<int,int> bst;
//     cout <<"inserting...\n";
//     for (size_t i = 0; i<SIZE; i++){
//       int k = getRandom();
//       bst.insert(k,i);
//       cout<<k<<'\t';
//     }
//     cout<<"\n In Order------------------------------------------------------"<<endl;
//     bst.inOrderTraverse(bst.getRoot(), inOrderNodeList);
//     for (auto n: inOrderNodeList){
//       cout<<n->key<<'\t';
//     }
//     cout<<"\n In Order next------------------------------------------------------"<<endl;
//     Node<int, int>* node = inOrderNodeList[0];
//     while (node!=nullptr){
//       cout << node->key<<'\t';
//       node = bst.inOrderNext(node);
//     }
//     cout<<"\n Pre Order------------------------------------------------------"<<endl;
//     bst.preOrderTraverse(bst.getRoot(), preOrderNodeList);
//     for (auto n: preOrderNodeList){
//       cout<<n->key<<'\t';
//     }
//     cout<<"\n Pre Order next------------------------------------------------------"<<endl;
//     node = preOrderNodeList[0];
//     while (node!=nullptr){
//       cout << node->key<<'\t';
//       node = bst.preOrderNext(node);
//     }
//     cout<<"\n Post Order------------------------------------------------------"<<endl;
//     bst.postOrderTraverse(bst.getRoot(), postOrderNodeList);
//     for (auto n: postOrderNodeList){
//       cout<<n->key<<'\t';
//     }
//     cout<<"\n Post Order next------------------------------------------------------"<<endl;
//     node = postOrderNodeList[0];
//     while (node!=nullptr){
//       cout << node->key<<'\t';
//       node = bst.postOrderNext(node);
//     }
//     cout<<"\n done-----------------------------------------"<<endl;
//     if( bst.isBST(bst.getRoot())){
//       cout<<"is BST!"<<endl;
//     } else {
//       cout<<"isnt BST!"<<endl;
//     }
//
// }
