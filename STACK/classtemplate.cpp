#include<iostream>
#include<vector>
#include <string>
#include<stack>
using namespace std;
template<class T>
class stack{
     vector<T> v;

    void push(T x) {
        v.push_back(x);
    }

    // Remove top element
    void pop() {
        if (v.empty()) {
            cout << "Stack is empty\n";
            return 
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


    // Difference between string and char data type  --char sirf ek character store kar sakta hai — ek letter, ek digit, ek symbol.
// Single quotes (' ') use hote hain, double quotes nahi.
  
  int main(){
     stack <T> s ;
    //   It is known as the class template in the stack, which is used to implement a stack with any data type.
    //  T ek placeholder hai kisi bhi type ke liye. Jab tum class ko use karoge, tab tum decide karoge T kya hoga:

    s.push("a");
    s.push("b");
    s.push("C");
    
    cout<<s.top();
   
    return 0;
}