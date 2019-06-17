#include "BST.h"
#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../catch2.hpp"
#define SIZE 100
TEST_CASE("bst"){
  BST<int, int> bst1;
  BST<int, int> bst2;
  vector<int> numbers;
  for (int i = 0; i<SIZE; i++){
    numbers.push_back(i);
  }
  random_shuffle ( numbers.begin(), numbers.end() );
  for (int i = 0; i<SIZE; i ++){
    bst1.insert(numbers[i],numbers[i]);
  }
  cout<<endl;
  random_shuffle ( numbers.begin(), numbers.end() );
  cout<<"bst1 pre order:"<<endl;
  bst1.preOrderTraverse();
  for (int i = 0; i<SIZE; i ++){
    bst2.insert(numbers[i],numbers[i]);
  }
  cout<<endl;
  cout<<"bst2 pre order:"<<endl;
  bst2.preOrderTraverse();
  bst1.makeLeftTree();
  bst2.makeLeftTree();
  ArrayStack<int> reversionStack  = bst2.getStackForReversion();
  bst1.revert(reversionStack);
  cout <<"after transformation, bst1 pre order:"<<endl;
  bst1.preOrderTraverse();

}
