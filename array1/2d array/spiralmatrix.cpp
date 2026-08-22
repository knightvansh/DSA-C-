  #include<iostream>
  using namespace std;
// void spiralMatrix(int mat[][4],int m,int n){
//     int sr = 0, er = m-1;
//     int sc=0  ,ec=n-1;
// while (sr<=er && sc<=ec)
// {
    
//   //top
//   for(int j=sc;j<=ec;j++){
//   cout<<mat[sr][j]<<" ";
//   }
//   //right
//   for(int i=sr+1;i<=er;i++){
//   cout<<mat[i][ec]<<" ";
//   }
//   //bottom
//  for(int j=ec-1;j>=sc;j--){
//   cout<<mat[er][j]<<" ";
//   }
//   //left
// for(int i=er-1;i>sr;i--){
//   cout<<mat[i][sc]<<" ";
//   }
//   sr++;sc++;
// er--;ec--;

// }

// }
void diagonalsum(int mat[][4],int n){
  int sum=0;
  for(int i=0;i<n;i++){
      sum+=mat[i][i];//pd
  }
 else if(i !=n-i-1){
    sum+=mat[i][n-i-1];
  }
}


int main(){

int matrix[4][4]={
                    {1,2,3,4},
                       {5,6,7,8},
               {9,10,11,12},
               {13,14,15,16},

 };
  // spiralMatrix(matrix,4,4);
    diagonalsum(matrix,4);

 return 0;

 }