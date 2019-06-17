#ifndef MHEAP_H
#define MHEAP_H
#include <iostream>
#include <random>
struct Node{
  int v;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
};

class priorityQueueM {
public:
  bool add(int i){
    Node* node = new Node;
    node->v = i;
    root = merge(node, root);
    root->parent = nullptr;
    n++;
    return true;
  }
  int remove(){
    int toRemove = root->v;
    root = merge(root->left, root->right);
    if (root!=nullptr){
      root->parent = nullptr;
    }
    n--;
    return toRemove;
  }
private:

  bool getRandomBool(){
    const int range_from  = 0;
    const int range_to   = 1;
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distro(range_from, range_to);
    return distro(generator)==0;
  }
  Node* merge(Node* t1, Node* t2){
    if (t1==nullptr){
      return t2;
    }
    if (t2==nullptr){
      return t1;
    }
    if (t2->v < t1->v){
      return merge(t2, t1);
    }
    if (1){
      t1->left = merge(t1->left, t2);
      t1->left->parent = t1;
    } else {
      t1->right = merge(t1->right, t2);
      t1->right->parent = t1;
    }
    return t1;
  }

  int n = 0;
  Node* root = nullptr;
};

#endif
