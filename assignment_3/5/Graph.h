#ifndef GRAPHAL_H
#define GRAPHAL_H
#include <iostream>
#include <vector>
#include "Stack.h"
#include "Queue.h"
typedef struct {
int source;
int dest;
} Edge;

class Graph{
public:
Graph(int n):n(n){
  std::cout<<n<<"init!!!!"<<std::endl;
  container.reserve(n);
}
bool addEdge(Edge e){
  if (e.source < n && e.dest < n && !hasEdge(e)){

    container[e.source].push_back(e.dest);
    m++;
    return true;
  } else if (!hasEdge(e)) {
    std::cout<<"addEdge: the edge contains out-of-range vertices."<<std::endl;
  } else {
    std::cout<<"addEdge: the edge already exists in the graph"<<std::endl;
  }
  return false;
}
bool removeEdge(Edge e){
  if (e.source >= n || e.dest >= n ){
    std::cout<<"removeEdge: the edge contains out-of-range vertices"<<std::endl;
    return false;
  }
  for (int i = 0; i < container[e.source].size(); i++){
    if (container[e.source][i] == e.dest){
      container[e.source].erase(container[e.source].begin()+i);
      return true;
    }
  }
  return false;
}
bool hasEdge(Edge e){
  if (e.source >= n || e.dest >= n || m==0 ){
    return false;
  }
  for (int dest: container[e.source]){
    if (e.dest == dest){
      return true;
    }
  }
  return false;
}
std::vector<int> outEdge(int i){

  if (i<n){
    return container[i];
  }
  std::cout<<"outEdge "<<i<<" out of bound."<<std::endl;
  std::vector<int> nil;
  return nil;
}
std::vector<int> inEdge(int target){
  std::vector<int> result;
  for (size_t i =0 ; i < n; i ++){
    for (size_t j = 0; j< container[i].size(); j++){
      if (j == target) result.push_back(i);
    }
  }
  return result;

}
  int getEdgeCount(){
    return m;
  }
  void BFS(int i){
    std::vector<int> visited(n,0);
    ArrayQueue<int> q;
    q.enqueue(i);
    while(q.size()!=0){
      int traverse = q.dequeue();
      if (visited[traverse] == 0){
        visited[traverse] = 1;
        std::cout<<char(97+traverse)<<", ";
        std::vector<int> neighbors = outEdge(traverse);
        for (auto j: neighbors){
          q.enqueue(j);
        }
      }
    }
  }
  void DFS(int i){
    ArrayStack<int> stack;
    std::vector<int> visited(n, 0);
    stack.push(i);
    while (stack.size()!=0){
      int traverse = stack.pop();
      if (visited[traverse] ==0){
        visited[traverse] = 1;
        std::cout<<char(97+traverse)<<", ";
        std::vector<int> neighbors = outEdge(traverse);
        for (auto j: neighbors){

          stack.push(j);
        }
      }
    }
    std::cout<<std::endl;

  }
private:
std::vector<std::vector<int>> container;
int n;
int m = 0;

};


#endif
