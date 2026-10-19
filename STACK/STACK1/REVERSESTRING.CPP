#include<iostream>
#include<vector>
#include <string>
#include<stack>
using namespace std;



template<class T>
class Mystack{
     vector<T> v;

void push(T x) {
 v.push_back(x);
 }

 // Remove top element
void pop() {
 if (v.empty()) {
     cout << "Stack is empty\n";
  }
 v.pop_back();
}

 T top(){
   int lastidx=v.size()-1;   
     return v[lastidx];
    }

// Check whether stack is empty
 bool empty() {
     return v.empty();
 }

 // Return size
 int size() {  
     return v.size();
    }
};

string reversestr(string str){
    stack<char> s;
    string ans; 
 for( int i=0;i<str.size();i++){
    s.push(str[i]);
        }
  while(!s.empty()){
    ans+=s.top();
    s.pop();
  }
return ans;
    }


    // Difference between string and char data type  --char sirf ek character store kar sakta hai — ek letter, ek digit, ek symbol.
// Single quotes (' ') use hote hain, double quotes nahi.
  
  int main(){
    string str = "vansh";
    cout <<reversestr(str);
    return 0;
}