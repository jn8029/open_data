<!-- g++ test-main.o arrayQueue.cpp -o tests && tests -r console
g++ -std=c++14 *.cpp  -->
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

The asymptotic runtime is the same across the 4 functions: O(n) because of the element shifting operations. It can be improved by using doubly-linked lists.
