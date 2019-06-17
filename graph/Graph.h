#ifndef GRAPHAL_H
#define GRAPHAL_H
#include <iostream>
#include <vector>

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
    std::cout<<"19 line."<<std::endl;
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
private:
std::vector<std::vector<int>> container;
int n;
int m = 0;

};


#endif
