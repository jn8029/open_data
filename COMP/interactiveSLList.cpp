#include <iostream>
#include <string>
#include <iomanip>
#include "SLList.h"
#include <vector>
#include <iterator>
#include <map>
using namespace std;

void invalid_input(){
  cout <<"Invalid input, try again"<<endl;
}

int main(){
  string operation;
  SLList<int> list;
  cout << "Usage: [OPERATION] [ARGS]"<<endl;
  cout << "Operations:"<<endl;
  cout <<setw(25)<<left<< "get i"<<setw(20)<<left<<"get item at index i;"<<endl;
  cout <<setw(25)<<left<< "set i x"<<setw(20)<<left<<"set index i's value to x;"<<endl;
  cout <<setw(25)<<left<< "insert i x"<<setw(20)<<left<<"insert x at index i;"<<endl;
  cout <<setw(25)<<left<< "remove i"<<setw(20)<<left<<"remove item at index i;"<<endl;
  cout <<setw(25)<<left<< "size"<<setw(20)<<left<<"get the size of list;"<<endl;
  cout <<setw(25)<<left<< "swap i"<<setw(20)<<left<<"swap items on i and i+1;"<<endl;
  cout <<setw(25)<<left<< "print"<<setw(20)<<left<<"print the list content;"<<endl;
  cout <<setw(25)<<left<< "exit"<<setw(20)<<left<<"exit program;"<<endl;
  cout <<endl;
  while (1){
    getline(cin,operation);
    istringstream iss(operation);
    vector<string> results((istream_iterator<string>(iss)),istream_iterator<string>());
    if (results.size()==0){
      cout<<"Invalid input, try again."<<endl;
      continue;
    }
    if(results[0]=="get" && results.size()==2){
      try {
          int index = stoi(results[1]);
          cout << list.get(index)  << endl;
      } catch (const std::exception &e) {
          cout<<"Error! "<<e.what()<<endl;
      }
    } else if (results[0]=="set" && results.size()==3){
      try {
        int index = stoi(results[1]);
        int value = stoi(results[2]);
        list.set(index, value);
        cout <<value<< " is set at index "<<index<<"."<<endl;
        cout << "current list:"<<endl;
        list.print();
      }catch(const exception &e){
        cout<<"Error! "<<e.what()<<endl;
      }
    } else if (results[0]=="insert" && results.size()==3){
      try {
        int index = stoi(results[1]);
        int value = stoi(results[2]);
        list.insert(index, value);
        cout <<value<< " is insert at index "<<index<<"."<<endl;
        cout << "current list:"<<endl;
        list.print();
      } catch(const exception &e){
        cout<<"Error! "<<e.what()<<endl;
      }
    } else if (results[0]=="size" && results.size()==1){
      cout << list.size() << endl;
    } else if (results[0]=="print" && results.size()==1){
      list.print();
    } else if (results[0]=="remove" && results.size()==2){
      try {
        int index = stoi(results[1]);
        int removed = list.remove(index);
        cout <<"item " << removed <<" on index "<<index<<" is removed."<<endl;
        list.print();
      } catch(const exception &e){
        cout<<"Error! "<<e.what()<<endl;
      }
    } else if (results[0]=="swap" && results.size()==2){
      try {
        int index = stoi(results[1]);
        list.swap(index);
        cout<<"indices "<<index<<" and "<<index+1<<" are swapped."<<endl;
        list.print();
      } catch(const exception &e){
        cout<<"Error! "<<e.what()<<endl;
      }
    } else if(results[0]=="exit"){
      break;
    } else {
      cout<<"Invalid input, try again."<<endl;
    }
  }
}
