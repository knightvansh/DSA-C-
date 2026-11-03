#include <bits/stdc++.h>
using namespace  std;


//Or natural number only //
 int sum( int n){
    if(n==1){
        return 1;
    }
    return n+sum(n-1);
}
int main(){
  sum(5);
  cout<<" sum of n  ="<<sum(5);
}