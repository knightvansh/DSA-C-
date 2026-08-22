#include<iostream>
using namespace std;
void search  (int mat[][4],int n,int m, int key){
int i=0;
int j=m-1;

 while(i<n && j>=0){
    if(mat[i][j]==key){
       cout<<"key is found at i ="<<i<<" "<<"and j="<<j<<endl;
       break;
    }
    else if(mat[i][j] < key){
           i++;
    }
    else{
        j--;
    }

 }
   cout<<"key not available"<<endl;
}


int main(){

int matrix[4][4]={
                {1,2,3,4},
                {5,6,7,8},
                {9,10,11,12},
                {13,14,15,16},

 };
  
    search(matrix,4,4,4);

 

 }