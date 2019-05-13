#ifndef SKIPLIST_H
#define SKIPLIST_H
#include <iostream>
#include <limits>
#include <vector>
#include <time.h>
using namespace std;

typedef struct NodeT {
  vector<NodeT*> next;
  int value;
  int height;
  NodeT(int height, int value):value(value),height(height+1){
    next.resize(height, nullptr);
  };
} Node;

class skipList{
public:
  skipList(int maxHeight):maxHeight(maxHeight){
    int min = numeric_limits<int>::min();
    sentinel = makeNode(min, maxHeight);
  }
  int remove(int value){
    int height = currentHeight;
    Node* walker = sentinel;
    while (height>=0){
      while(walker->next[height] && walker->next[height]->value<value){
        walker = walker->next[height];
      }
      if (walker->next[height] && walker->next[height]->value==value){
        walker->next[height] = walker->next[height]->next[height];
      }
      height--;
    }
    elementCount--;
    return walker->value;
  }
  bool exists(int value){
    Node* found = findSmaller(value);
    if (found->next[0] && found->next[0]->value==value){
        return true;
    }
    return false;
  }
  void insert(int value){
    int height = currentHeight;
    vector<Node*> updates(maxHeight, sentinel);
    Node* walker = sentinel;
    while (height>=0){

      while(walker->next[height] && walker->next[height]->value<value){
        walker = walker->next[height];
      }
      updates[height] = walker;
      height--;
    }
    int randomHeight = getRandomHeight();
    Node* newNode = makeNode(value, randomHeight);
    for (size_t i =0 ; i<randomHeight; i++){
      newNode->next[i] = updates[i]->next[i];
      updates[i]->next[i] = newNode;
    }
    if (currentHeight < randomHeight){
      currentHeight = randomHeight;
    }
    elementCount++;
  }

  void print(){

    for (size_t i =0; i < currentHeight;i++){
        Node* walker = sentinel;

        for (size_t j =0; j<elementCount;j++){
          if (walker->next[i]){
            cout<<walker->next[i]->value <<'\t';
            walker = walker->next[i];
          }
        }
        cout<<endl;
    }
  }
  int size(){
    return elementCount;
  }
  Node* findSmaller(int value){
    int height = currentHeight;
    Node* walker = sentinel;
    while (height>=0){
      while(walker->next[height] && walker->next[height]->value<value){

        walker = walker->next[height];
      }
      height--;
    }
    return walker;
  }




private:
  Node* makeNode(int value, int height){
    return new Node(height, value);
  }

  int getRandomHeight(){
    double probability = 0.5;

    int v = 1;

    while ((((double)rand() / RAND_MAX)) < probability &&
           abs(v) < maxHeight) {

        v += 1;
    }
    return abs(v);
  }



  Node* sentinel;
  int maxHeight;
  int elementCount = 0;
  int currentHeight = 0;
};
#endif
