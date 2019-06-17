
#ifndef BST_H
#define BST_H
#include <iostream>
#include "arrayStack.h"
template <typename K, typename V>
struct Node {
  K key;
  V value;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
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
  void inOrderTraverse(){
    inOrderTraverseHelper(root);
    std::cout<<std::endl;
  }
  void preOrderTraverse(){
    preOrderTraverseHelper(root);
    std::cout<<std::endl;
  }
  int size(){
    return count;
  }
  Node<K,V>* getRoot(){
    return root;
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
  bool isBalanced(Node<K,V>* node){
    if (node==nullptr){
      return true;
    }

    int left_height = height(node->left);
    int right_height = height(node->right);

    int height_diff;
    if (left_height>right_height){
        height_diff = left_height - right_height;
    } else {
        height_diff = right_height - left_height;
    }

    if (height_diff <=1){

        return true;
    } else {

        return false;
    }
  }
  Node<K,V>* preOrderNext(Node<K,V>* node) {
    // mid->left->right
    //if node is nullptr, return nullptr
    if (node==nullptr){
      return nullptr;
    }
    if (node->left != nullptr) {
        //if node has left child, return
        return node->left;
    } else if (node->right != nullptr) {
        //if node has no left child, but has a right child, return
        return node->right;
    } else {
        //no left child or right child, climb up until no parent
        while (node->parent != nullptr) {
            if (node == node->parent->left) {
                // if node is a left child
                if (node->parent->right != nullptr) {
                    //return its sibling
                    return node->parent->right;
                } else {
                    //node is left child and no sibling, climb up
                    node = node->parent;
                }
            } else {
                // if node is a right child
                if (node->parent->parent == nullptr) {
                    //node has no grandparent, meaning no preorder next
                    return nullptr;
                } else if (node->parent == node->parent->parent->left) {
                    //node has grandparent and node's parent is a left child
                    if (node->parent->parent->right != nullptr) {
                        //node's grandparent has right child, its the answer
                        return node->parent->parent->right;
                    } else {
                        //node's grandparent has no right child,  climb up
                        node = node->parent;
                    }
                } else {
                    // node has grandparent and node's parent is a right child. then climb up
                    node = node->parent;
                }
            }
        }
        return nullptr;
    }
  }
  Node<K,V>* rotateLeft(Node<K,V>* node){
    
      Node<K,V>* new_root = node->right;
      if (root==node) {
        root = new_root;
        new_root->parent = nullptr;
      } else {
        relink(node->parent, new_root, node->parent->left==node);
      }
      relink(node, new_root->left, false);
      relink(new_root, node, true);
      return new_root;

  }
  Node<K,V>* rotateRight(Node<K,V>* node){

      Node<K,V>* new_root = node->left;
      if (node==root) {
        root = new_root;
        new_root->parent = nullptr;
      } else {
        relink(node->parent, new_root, node->parent->left==node);
      }
      relink(node, new_root->right, true);
      relink(new_root, node, false);
      return new_root;

  }
  void relink(Node<K,V>* parent, Node<K,V>* child, bool make_left_child){
    if (parent == nullptr){
      return;
    }
    if (make_left_child){
      parent->left = child;
    } else {
      parent->right = child;
    }
    if (child != nullptr){
        child->parent = parent;
    }
  }
  ArrayStack<int> getStackForReversion(){
    return stack;
  }
  void revert(ArrayStack<int> s){
      Node<K,V>* node;
      while(s.size()>0){
        node = searchNode(s.pop());
        rotateRight(node);
      }
  }
  void makeLeftTree(){
    int rotations = 0;
    Node<K,V>* new_root;
    do {
      rotations = 0;
      Node<K,V>* walk = root;
      while (walk){
        while (walk->right!=nullptr){
          walk = rotateLeft(walk);
          stack.push(walk->value);
          rotations++;
        }
        walk = preOrderNext(walk);
      }
    } while(rotations>0);
  }

private:
  ArrayStack<int> stack;
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
  Node<K, V>* findSmallest(Node<K, V>* walker){
    while (walker->left != nullptr){
      walker = walker->left;
    }
    return walker;
  }
  void inOrderTraverseHelper(Node<K,V>* walker){
    if (walker!=nullptr){
      if (walker->left != nullptr){
        inOrderTraverseHelper(walker->left);
      }
      std::cout << walker->key<<"\t";
      if (walker->right!=nullptr){
        inOrderTraverseHelper(walker->right);
      }
    }
  }
  void preOrderTraverseHelper(Node<K,V>* walker){
    if (walker!=nullptr){
      std::cout << walker->key<<"\t";
      if (walker->left != nullptr){
        preOrderTraverseHelper(walker->left);
      }

      if (walker->right!=nullptr){
        preOrderTraverseHelper(walker->right);
      }
    }
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
  Node<K,V>* createNewNode(K key, V value){
    Node<K,V>* newNode = new Node<K,V>;
    newNode->key = key;
    newNode->value = value;
    return newNode;
  }
  Node<K, V>* root = nullptr;
  int count = 0;
};

#endif
