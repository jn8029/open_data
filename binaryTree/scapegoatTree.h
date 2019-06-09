
#ifndef SGT_H
#define SGT_H
#include <iostream>
#include <cmath>
#include <vector>
template <typename K, typename V>
struct Node {
  K key;
  V value;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
};

template <typename K, typename V>
class SGT{
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
      count ++;max_count++;
    } else if (found->key < key){
      Node<K,V>* newNode = createNewNode(key, value);
      newNode->parent = found;
      found->right = newNode;
      count ++;max_count++;
      if (depthExceeded(newNode))balance(newNode);



    } else if (found->key > key){
      Node<K,V>* newNode = createNewNode(key, value);
      newNode->parent = found;
      found->left = newNode;
      count ++;max_count++;
      if (depthExceeded(newNode))balance(newNode);
    } else {
      found->value = value;
      return;
    }

  }
  bool remove(K key){
    Node<K,V>* found = searchNode(key);
    Node<K,V>* found_parent = nullptr;
    if (found==nullptr || (found->key)!=key){
      return false;
    } else {
      // found_parent = found->parent;

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

      // if(found_parent)balance(found_parent);
      count--;
      if (count<alpha*max_count){
        std::cout<<"removal triggered rebuilt"<<std::endl;
        rebuild(getRoot());
        max_count = count;
      }
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
  int size(Node<K,V>* node){
    if (node == nullptr){
      return 0;
    }
    return 1 + size(node->left) + size(node->right);
  }
  Node<K,V>* getRoot(){
    return root;
  }
  int depth(Node<K,V>* node){
    int answer = 0;
    while (node != root){
      node = node->parent;
      answer ++;
    }
    return answer;
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
  bool depthExceeded(Node<K,V>* node){
    std::cout<<"node val"<<node->value<<std::endl;
    std::cout<<"node depth"<<depth(node)<<std::endl;

    std::cout<<"log("<<count<<")/log(1/"<< alpha << ")="<<log(count)/log(1/alpha)<<std::endl;
    if (depth(node)>(log(count)/log(1/alpha))){
      std::cout<<"rebult triggered"<<std::endl;
      return true;
    }
    return false;
  }
  bool treeHeightBalanced(){
    return height(getRoot()) <= (log(count)/log(1/alpha));
  }
  bool weightBalanced(Node<K,V>* node){
    if (node==nullptr){
      return true;
    }
    int left_size = size(node->left);
    int right_size = size(node->right);
    int subtree_size = left_size + right_size +1;
    if (left_size>alpha*subtree_size || right_size > alpha*subtree_size){
      return false;
    }
    return true;
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


private:
  void balance(Node<K,V>* node){
      while (node!=nullptr){
        if (!weightBalanced(node)){
          std::cout << node->value << "is unbalanced"<<std::endl;
          rebuild(node);
          break;
        }
        node = node->parent;
      }
  }
  void rebuild(Node<K,V>* node){
    if (node==nullptr){
      return;
    }
    int treeSize = size(node);
    std::cout<<"rebult size = "<<treeSize<<std::endl;
    Node<K,V>* nodeParent = node->parent;
    std::vector<Node<K,V>*> nodeList(treeSize);
    flatten(node, nodeList, 0);
    Node<K,V>* newRoot = buildTree(nodeList, 0, treeSize-1);
    if (nodeParent == nullptr){
      newRoot->parent = nullptr;
      root = newRoot;
    } else if (nodeParent->left == node){
      newRoot->parent = nodeParent;
      newRoot->parent->left = newRoot;
    } else {
      newRoot->parent = nodeParent;
      newRoot->parent->right = newRoot;
    }
  }
  int flatten(Node<K,V>* node, std::vector<Node<K,V>*> &nodeList, int index){
    if(node==nullptr){
      return index;
    } else {
      index = flatten(node->left, nodeList, index);
      nodeList[index] = node;
      index++;
      return flatten(node->right, nodeList, index);
    }
  }
  Node<K,V>* buildTree(std::vector<Node<K,V>*> &nodeList, int start, int end){
    if (end<start){
      return nullptr;
    }
    int mid = (start+end) /2;

    nodeList[mid]->left = buildTree(nodeList, start, mid-1);
    if ((nodeList[mid]->left) != nullptr){
      nodeList[mid]->left->parent = nodeList[mid];
    }
    nodeList[mid]->right = buildTree(nodeList, mid+1, end);
    if ((nodeList[mid]->right) != nullptr){
      nodeList[mid]->right->parent = nodeList[mid];
    }
    return nodeList[mid];
  }


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
      std::cout<<walker->value<<'\t';
      if (walker->right!=nullptr){
        inOrderTraverseHelper(walker->right);
      }
    }
  }
  Node<K,V>* createNewNode(K key, V value){
    Node<K,V>* newNode = new Node<K,V>;
    newNode->key = key;
    newNode->value = value;
    return newNode;
  }
  Node<K, V>* root = nullptr;
  int count = 0;
  int max_count = 0;
  double alpha = .5;
};

#endif
