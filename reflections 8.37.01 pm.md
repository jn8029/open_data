# 1


## Writing the inOrderNext, preOrderNext and postOrderNext Method

It is straightforward to implement inOrderNext and preOrderNext: just follow the definition and exhaustively consider all possible cases of the input node.

However I couldn't get my head around implementing postOrderNext so I did a bit of googling and found an "incorrect" implementation at https://www.geeksforgeeks.org/postorder-successor-node-binary-tree/

An excerpt of the incorrect part as shown below:
```
    // If given node is right child of its
    // parent or parent's right is empty, then  
    // parent is postorder successor.
    Node* parent = n->parent;
    if (parent->right == NULL || parent->right == n)
        return parent;

    // In all other cases, find the leftmost  
    // child in right substree of parent.
    Node* curr = parent->right;
    while (curr->left != NULL)
        curr = curr->left;

    return curr;
```
It claims that "in all other cases, find the left most child in right subtree of the parent". It is incorrect. In post-order traversal, the sequence of traversal is left->right->mid. Given the above implementation, if the parent's right submtree has no left subtree, the parent's right child will be returned. If the parent's right subtree actually has a right child, that right child should be returned. Therefore I implemented a helper function ```getLeftMostLeaf(node)``` to get the right node: it finds the left most leaf from the node's left subtree, if there's no left sub tree, it finds the left most leaf from the node's right subtree, if there's no right subtree, it returns the node itself. This is the correct implementation that follows the post-order traversal sequence.



## Testing
Testing is done by initiating a binary search tree with size 0 to 100 and then create an auxiliary vector to store all the nodes in in-order, pre-order and post-order sequence. It then use the three implemented method inOrderNext, preOrderNext, postOrderNext to check if the returned successor node matches the nodes in the auxiliary vector

part of the test result output:

test.cpp:62: PASSED:
  REQUIRE( node->key == postOrderNodeList[counter+1]->key )
with expansion:
  893 (0x37d) == 893 (0x37d)

test.cpp:62: PASSED:
  REQUIRE( node->key == postOrderNodeList[counter+1]->key )
with expansion:
  777 (0x309) == 777 (0x309)

test.cpp:62: PASSED:
  REQUIRE( node->key == postOrderNodeList[counter+1]->key )
with expansion:
  526 (0x20e) == 526 (0x20e)

===============================================================================
All tests passed (14041 assertions in 1 test case)

There are 14041 assertion tests, so I am not putting all the output here.

You can compile the tests with g++:

g++ ../test-main.o test.cpp -o tests && tests -s

I have placed the pre-compiled catch2 object in the root folder of this assignment.


# 2

## Writing the isBST method

If a binary tree is a binary search tree, at each node N of the tree, all the nodes in the left subtree have smaller keys than N's key, and all the nodes in the right subtree have larger keys than N's key.
Given this definition, we can test the binary tree recursively. I defined a ```isBST``` method that takes a pointer to a node as input and check

1. the left subtree isBST
2. the right subtree isBST
3. the left child has smaller key than the node's key
4. the right child has larger key than the node's key

if all 4 tests returned true, then the tree is indeed a BST.


## Testing

For convenience, I am using a BST that I implemented to test the method. For testing, binary search trees of sizes from 0 to 100 are created and then isBST is called to check that the BSTs are BSTs. A random node is then selected so that I can tweak the key of the left child /or right child/ or parent so that the BST is guaranteed to become a non BST. The isBST is then called to check that the resulted tree is not a BST anymore.

part of the test result output:
test.cpp:63: PASSED:
  REQUIRE( bst.isBST(bst.getRoot())==false )
with expansion:
  false == false


test.cpp:40: PASSED:
  REQUIRE( bst.isBST(bst.getRoot())==true )
with expansion:
  true == true

test.cpp:63: PASSED:
  REQUIRE( bst.isBST(bst.getRoot())==false )
with expansion:
  false == false

===============================================================================
All tests passed (199 assertions in 1 test case)

There are 199 assertion tests, so I am not putting all the output here.

You can compile the tests with g++:

g++ ../test-main.o test.cpp -o tests && tests -s

# 4

## implementing hashTable with linear probing

I initially used an additional isNull variable in the Node struct to represent the null concept described in the textbook. But then I figured I could just initiate the array with nullptr so that it saves space.

I also encountered a bug when testing the resize function. I found that if I did not put a default value for the private int variables, doing arithmetic on them will result in weird behaviours. Once I put 0 for the private variables. It works.

```
int arraySize = 16;
int count = 0;
int nonNullCount=0;
```

It turns out I should not expect un-initialized int to be 0 and the expected behavior of accessing un-initialized memory location is "undefined".

## Testing
I used cout to output the location each item is eventually stored and check if they are correct. With an initial array size of 16 and hash function of K mod 13...

output:
item 1 is stored at index 1<br>
item 5 is stored at index 5<br>
item 21 is stored at index 8 -> 21 % 13 = 8<br>
item 26 is stored at index 0 -> 26 % 13 = 0<br>
item 39 is stored at index 2 -> 39 % 13 = 0, but 0 and 1 are occupied, so store at 2<br>
item 14 is stored at index 3 -> 14 % 13 = 1, but 0,1,2 are occupied, so store at 3<br>
item 15 is stored at index 4 -> 15 % 13 = 2, but 2,3 are occupied, so store at 4<br>
item 16 is stored at index 6 -> 16 % 13 = 3, but 3 4 5 are occupied, so store at 6<br>
resizing  -> now the array has 8 items > half of arraySize=16, resize for double<br>
new array size = 32<br>
item 17 is stored at index 7 -> 17 % 13 = 4, but 4-6 are occupied, store at 7<br>
item 18 is stored at index 9 -> 18 % 13 = 5, but 5-8 are occupied, store at 9<br>
item 19 is stored at index 10 -> 19 % 13 = 6, but 6-9 are occupied, store at 10<br>
item 20 is stored at index 11 -> 20 % 13 = 7, but 7-10 are occupied, store at 11<br>
item 111 is stored at index 12 -> 111 % 13 = 7, but 7-11 are occupied, store at 12<br>
item 145 is stored at index 13 -> 145 %13 = 2, but 2-12 are occupied, store at 13<br>
item 146 is stored at index 14 -> 146 % 13 = 3 but 3-13 are occupied , store at 14<br>



# 5

## implemenring inOrderNumber, preOrderNumber and postOrderNumber

The implementation is the same as preOrderTraversal, inOrderTraversal, postOrderTraversal. The only difference is the additional operation of storing the sequence index. Since the question asked us to implement inOrderNumber(), preOrderNumber() and postOrderNumber() without any the method to take any argument, I had to implement a helper function to help the 3 individual implementation.

## Testing

I used the traversal algorithms to store all the nodes in the respective sequences in the auxiliary vectors and compare the stored numbers with the node's index of the auxiliary vectors. I create BSTs of size 0 - 1000

part of the test result output:
test.cpp:43: PASSED:
  REQUIRE( i== postOrderNodeList[i]->postOrderNum )
with expansion:
  97 == 97

test.cpp:43: PASSED:
  REQUIRE( i== postOrderNodeList[i]->postOrderNum )
with expansion:
  98 == 98

test.cpp:43: PASSED:
  REQUIRE( i== postOrderNodeList[i]->postOrderNum )
with expansion:
  99 == 99

test.cpp:43: PASSED:
  REQUIRE( i== postOrderNodeList[i]->postOrderNum )
with expansion:
  100 == 100

===============================================================================
All tests passed (272565 assertions in 1 test case)

There are 272565 assertion tests, so I am not putting all the output here.

You can compile the tests with g++:

g++ ../test-main.o test.cpp -o tests && tests -s
