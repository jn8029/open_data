<!-- g++ test-main.o testPriorityQueue.cpp -o tests && tests -r console
g++ -std=c++14 *.cpp  -->

<!-- mac
g++ ../test-main.o testSLStack.cpp -std=c++11 -o tests && ./tests -->

## Array-Based Data Structures
## arrayList

```arrayList``` is a array based list data structure that implements:

| Public Function      | big-O         |
| :-: |:-:|
| get(i)     | O(1)|
| set(i,x)     | O(1)      |  
| add(i,x) | O(n)      |   
| remove(i) | O(n)      |

The O(n) of the ```add``` and ```remove``` stems from element shifting. i.e. when ```add(i,x)``` is called, every element from index i to the last element in the list will be shifted backward by one position; when remove(i) is called, every element from index i+1 to the last element in the list will be shifted forward by one position. It can be improved with a circular array, which is implemented in [betterArrayList](#betterArrayList)

The resizing of the array runs at O(1) (amortized)

| Private Function      | big-O         |
| :-: |:-:|
| grow()|O(1)|
| shrink()|O(1)|


## listStack
```listStack``` is a list-based data structure that implements ```push``` and ```pop``` functions on a LIFO(last-in-first-out) basis.

| Public Function      | big-O         |
| :-: |:-:|
| push(x)     | O(1)|
| pop()     | O(1)      |  

O(1) is achieved despite that ```listStack``` inherits from ```arrayList``` because of the LIFO nature of the ```listStack```. When ```push(x)``` is called, it is always added to the back of the list, and when ```pop()``` is called, it is always taking the last element of the list. Therefore the expensive element-shifting operations are completely avoided.

## arrayQueue

```arrayQueue``` is a circular-array based data structure that implements functions ```add``` and ```remove``` on a FIFO(first-in-first-out) basis.

With a circular array, the expensive element shifting operations are avoided and therefore O(1) is achieved for both functions.

| Public Function      | big-O         |
| :-: |:-:|
| push(x)     | O(1)|
| pop()     | O(1)      |  

## betterArrayList
```arrayList``` is another array based list data structure that implements:

| Public Function      | big-O         |
| :-: |:-:|
| get(i)     | O(1)|
| set(i,x)     | O(1)      |  
| add(i,x) | O(n)      |   
| remove(i) | O(n)      |

The asymptotic runtime is actually the same as ```arrayList``` but with the implementation of circular array, the expensive element shifting operations would at worst run for n/2 elements.

## ListDeque
```listDeque``` is a list-based data structure that implements functions listed below.

| Public Function      | big-O         |
| :-: |:-:|
| pushFront(i)     | O(n)|
| pushBack(i,x)     | O(n)      |  
| popFront(i,x) | O(n)      |   
| popBack(i) | O(n)      |

The asymptotic runtime is the same across the 4 functions: O(n) because of the element shifting operations. It can be improved by using doubly-linked lists, or by using circular array while keeping records of head and tail indices.

# Linked-List-Based Data Structures

## SLStack
```SLStack``` is a singly-linked-list-based data structure that implements ```push``` and ```pop``` functions on a LIFO(last-in-first-out) basis.

| Public Function      | big-O         |
| :-: |:-:|
| push(x)     | O(1)|
| pop()     | O(1)      |  

The asymptotic runtime of singly linked list based stack is the same as that implemented with an array based list. When adding an element, it is always added to the head of the linked list; when removing an element, the head element is removed.

## SLQueue

```SLQueue``` is a singly-linked-list based data structure that implements functions ```push``` and ```pop``` on a FIFO(first-in-first-out) basis.

The asymptotic runtime of singly linked list based queue is the same as that implemented with a circular array based list. When adding an element, it is always added to the tail of the linked list; when removing an element, the head element is removed.

| Public Function      | big-O         |
| :-: |:-:|
| push(x)     | O(1)|
| pop()     | O(1)      |  

## DLList

```DLList``` is a doubly linked list. Compared with a singly linked list, each node in the ```DLList``` stores 2 pointers to the previous and next node. It makes adding and removing element efficient, assuming we already have the element at hand. If a search is needed before ```add``` or ```remove``` is called, a O(n) get operation is needed to traverse the list and find the node at nth location.

| Public Function      | big-O         |
| :-: |:-:|
| add(i, x)     | O(n)|
| remove(i)     | O(n)      |  
| addBefore(Node, x)     | O(1)|
| removeNode(Node)     | O(1)      |  
