#include<iostream>
#include<vector>
using namespace std;
struct node{

public:
int data;
node*next;

public:
node(int data1,node*next1){
    data =data1;
    next=next1;
}

// public:
// node(int data1){
//     data =data1;
//     next=nullptr;
// }

};
int main(){
  vector<int> arr={2,5,8,7};
  node* y = new node(arr[0], nullptr);
  cout<< y->data;
  delete y;
}

