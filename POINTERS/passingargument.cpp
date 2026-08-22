#include<iostream>
using namespace std;
//pass by value
//void changeA(int param){

//param=20;
//cout<<param<<"\n";

//}
 //pass by refrence using pointer
 void changeA(int*ptr){
*ptr=20;
cout<<*ptr<<"\n";

 }


int main(){
    int a=10;
    changeA(&a);
    cout<<"a"<<"\n";
    return 0;
}
