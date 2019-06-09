/**
  Assignment 2, Question 5, BST.h
  Purpose: implement preOrderNumber, postOrderNumber and inOrderNumber that assigns individual sequencial numbers based on the traversal algorithms.
  @author Warren Cheng
  @version 2019.06.05
*/
#ifndef BST_H
#define BST_H
#include <iostream>
#include <vector>

template <typename K, typename V>
struct Node {
  K key;
  V value;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
  int inOrderNum;
  int preOrderNum;
  int postOrderNum;
};

template <typename K, typename V>
class BST{
public:
  V search(K key){
    Node<K,V>* found = searchNode(key);
    if (found==nullptr || (found->key)!=key){
      throw "search: key does not exists in the tree.";
    } else {
      return (found->value);
    }
  }
  void insert(K key, V value){
    Node<K,V>* found = searchNode(key);
    if (found==nullptr){
      Node<K,V>* newNode = createNewNode(key, value);
      root = newNode;
    } else if (found->key < key){
      Node<K,V>* newNode = createNewNode(key, value);
      newNode->parent = found;
      found->right = newNode;

    } else if (found->key > key){
      Node<K,V>* newNode = createNewNode(key, value);
      newNode->parent = found;
      found->left = newNode;

    } else {
      found->value = value;
      return;
    }
    count ++;
  }
  bool remove(K key){
    Node<K,V>* found = searchNode(key);
    Node<K,V>* found_parent = nullptr;
    if (found==nullptr || (found->key)!=key){
      return false;
    } else {
      if (found->left != nullptr && found->right != nullptr){
        Node<K,V>* largestInLeftChild = findLargest(found->left);
        K kHolder = largestInLeftChild->key;
        V vHolder = largestInLeftChild->value;
        largestInLeftChild->key = found->key;
        largestInLeftChild->value = found->value;
        found->key = kHolder;
        found->value = vHolder;
        splice(largestInLeftChild);
      } else {
        splice(found);
      }
      count--;
      return true;
    }
  }
  int size(){
    return count;
  }
  int height(Node<K,V>* node){
    if (node==nullptr){
      return -1;
    }
    if ((node->right == nullptr) && (node->left==nullptr)){
      return 0;
    }
    int left_height = height(node->left);
    int right_height = height(node->right);
    if (right_height>left_height){
      return right_height+1;
    } else {
      return left_height+1;
    }

  }
  Node<K,V>* getRoot(){
    return root;
  }

  void inOrderTraverse(Node<K,V>* node, std::vector<Node<K,V>*> &nodeList){
    if (node==nullptr){return;}
    if (node->left != nullptr){
      inOrderTraverse(node->left, nodeList);
    }
    nodeList.push_back(node);
    if (node->right!=nullptr){
      inOrderTraverse(node->right, nodeList);
    }
  }
  void inOrderNumber(){
    int i = 0;
    inOrderNumberHelper(getRoot(), i);
  }
  void inOrderNumberHelper(Node<K,V>* node, int &index){
    if (node==nullptr){return;}
    if (node->left != nullptr){
      inOrderNumberHelper(node->left, index);
    }
    node->inOrderNum = index;
    index++;
    if (node->right!=nullptr){
      inOrderNumberHelper(node->right, index);
    }
  }

  void preOrderTraverse(Node<K,V>* node, std::vector<Node<K,V>*> &nodeList){
    if (node==nullptr){
        return;
    }
    nodeList.push_back(node);
    preOrderTraverse(node->left, nodeList);
    preOrderTraverse(node->right, nodeList);
  }
  void preOrderNumber(){
    int i = 0;
    preOrderNumberHelper(getRoot(), i);
  }
  void preOrderNumberHelper(Node<K,V>* node, int &index){
    if (node==nullptr){
        return;
    }
    node->preOrderNum = index;
    index++;
    preOrderNumberHelper(node->left, index);
    preOrderNumberHelper(node->right, index);
  }

  void postOrderTraverse(Node<K,V>* node, std::vector<Node<K,V>*> &nodeList){
    if (node==nullptr){
        return;
    }
    postOrderTraverse(node->left, nodeList);
    postOrderTraverse(node->right, nodeList);
    nodeList.push_back(node);

  }
  void postOrderNumber(){
    int i =0;
    postOrderNumberHelper(getRoot(),i);
  }
  void postOrderNumberHelper(Node<K,V>* node, int& index){
    if (node==nullptr){
        return;
    }
    postOrderNumberHelper(node->left, index);
    postOrderNumberHelper(node->right, index);
    node->postOrderNum = index;
    index = index + 1;
  }


private:

  void splice(Node<K, V>* node){
    //input: target node to be removed, the node has to have 0 or 1 child.
    //result: the target node is spliced and its position is replaced by either its left or right child
    Node<K, V>* descendant;
    Node<K, V>* parent;
    //find the target node's single child, it may be nil.
    if (node->left != nullptr){
      descendant = node->left;
    } else {
      descendant = node->right;
    }
    //edge case: if target node itself is root, update root
    if (node==root){
      root = descendant;
      parent = nullptr;
    } else {
      parent = node->parent;
      //check if target node is left child or right child, splice the target node.
      if (parent->left == node){
        parent->left = descendant;
      } else {
        parent->right = descendant;
      }
    }
    //update the parent pointer of the child of the target node.
    if (descendant!=nullptr){
      descendant->parent = parent;
    }
  }
  Node<K, V>* findLargest(Node<K, V>* walker){
    while (walker->right != nullptr){
      walker = walker->right;
    }
    return walker;
  }
  Node<K,V>* createNewNode(K key, V value){
    Node<K,V>* newNode = new Node<K,V>;
    newNode->key = key;
    newNode->value = value;
    return newNode;
  }
  Node<K,V>* leftMostLeaf(Node<K,V>* node){
      while (node->left || node->right)
      {
          if(node->left) node=node->left;
          else node=node->right;
      }
      return node;
  }
  Node<K, V>* searchNode(K key){
    Node<K,V>* walker = root;
    Node<K,V>* prevWalker = nullptr;
    while (walker != nullptr){
      prevWalker = walker;
      if (walker->key==key){
        return walker;
      } else if (walker->key< key){
        walker = walker->right;
      } else {
        walker = walker->left;
      }
    }
    return prevWalker;
  }
  Node<K, V>* root = nullptr;
  int count = 0;
};

#endif
