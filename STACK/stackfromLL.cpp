#include<iostream>
#include<vector>
#include<list>
#include <string>

using namespace std;

// Create a stack using a list. 
template <class T>
// class Node{
//     T data;
//     Node* next;
// public:
//  Stack(){
//       head=NULL;
//  }
// }

  class Stack{
    list<T> ll;
    public:

    void push(T val){
        ll.push_front(val);
    }

    void pop(){
          ll.pop_front();
    }

   T top(){
    return ll.front();
   }

  bool isEmpty(){
    return ll.empty();
  }

};
  
  int main(){
    //STL stack
     stack<int> s ;
//It is known as the class template in the stack, which is used to implement a stack with any data type.
    ////  T ek placeholder hai kisi bhi type ke liye. Jab tum class ko use karoge, tab tum decide karoge T kya hoga:

    s.push(3);
    s.push(2);
    s.push(1);

    
    while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop()
    }
    cout<<endl;
    return 0;
}