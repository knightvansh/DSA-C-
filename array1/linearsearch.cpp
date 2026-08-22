#include<iostream>
    using namespace std;
    int main()
 {                   
int n;
cout<<"enter size of array";
cin>>n;
int arr[n];
//input
 for(int i=0;i<=n-1;i++)
 {
    cin>>arr[i];
 }
 int x;
 cout<<"enter the elements you want to search";
 cin>>x;
 //search
 for(int i=0;i<=n-1;i++)
 {
    if(arr[i]==x)
    cout<<"present";
 }

 }