#include<iostream>
using namespace std;
int binsearch(int*arr,int n,int key){
    int st=0,end=n-1;

while(st<=end){


    int mid=(st+end)/2;
    if(arr[mid]  ==key){
        return mid;//key found
    }else if(arr[mid]<key){//2nd half
        st=mid+1;
    }
    else{
        //1st half
        end=mid-1;
    }
}
return -1;




}

int main(){
int arr[]={2,4,6,8,10,12};
int n=sizeof(arr)/sizeof(int);
cout<<binsearch(arr,n,10);
return 0;

}