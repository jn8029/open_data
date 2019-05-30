
#ifndef AVLT_H
#define AVLT_H
#include <iostream>

template <typename K, typename V>
struct Node {
  K key;
  V value;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
};

template <typename K, typename V>
class AVLTree{
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
      balanceAfterInsertion(newNode);
    } else if (found->key > key){
      Node<K,V>* newNode = createNewNode(key, value);
      newNode->parent = found;
      found->left = newNode;
      balanceAfterInsertion(newNode);
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
      std::cout<<"node "<<found->value<<"is deleted"<<std::endl;
      balanceAfterDeletion(found);
      count--;
      return true;
    }
  }
  void inOrderTraverse(){
    inOrderTraverseHelper(root);
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
  void balanceAfterDeletion(Node<K,V>* node){
    while (node!=root && node!=nullptr){
      Node<K,V>* parent = node->parent;
      if (parent==nullptr) parent= root;
      if (!isBalanced(parent)){
        Node<K,V>* higherChild;
        if (height(parent->left)>height(parent->right)){
          higherChild = parent->left;
        } else {
          higherChild = parent->right;
        }
        Node<K,V>* higherGrandChild;
        if (height(higherChild->left)>height(higherChild->right)){
          higherGrandChild = higherChild->left;
        } else {
          higherGrandChild = higherChild->right;
        }


        if ((higherGrandChild == higherChild->right) == (higherChild == parent->right)){
            //single rotate
            rotate(higherChild);
        } else {
          rotate(higherGrandChild);
          rotate(higherGrandChild);
        }
      } else {

      }
      node = node->parent;

    }
  }
  void balanceAfterInsertion(Node<K,V>* node){
    while(node!=root){
      Node<K,V>* parent = node->parent;
      Node<K,V>* grandparent = parent->parent;
      if (!isBalanced(grandparent)){
        if ((node == parent->right) == (parent == grandparent->right)){
            //single rotate
            rotate(parent);
        } else {
          rotate(node);
          rotate(node);
        }
      }
      node = node->parent;
    }
  }
  void rotate(Node<K,V>* node){
    Node<K,V>* x = node;
    Node<K,V>* y = x->parent;
    Node<K,V>* z = y->parent;
    if (z == nullptr){
        root = x;
        x->parent = nullptr;
    } else {
      relink(z,x,y==(z->left));
    }
    if (x==(y->left)){
      relink(y,x->right,true);
      relink(x,y,false);
    } else {
      relink(y, x->left, false);
      relink(x, y , true);
    }
  }
  void relink(Node<K,V>* parent, Node<K,V>* child, bool make_left_child){
    if (make_left_child){
      parent->left = child;
    } else {
      parent->right = child;
    }
    if (child != nullptr){
        child->parent = parent;
    }
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
