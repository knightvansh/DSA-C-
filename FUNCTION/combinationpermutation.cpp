#include<iostream>
using namespace std;
int fact(int x){
   int fact=1;
   for(int i=2;i<=x;i++){
      fact *= i;
   }
   return fact;
}


int main(){
   int n;
   cout<<"enter n:";
   cin>>n;
   int r;
   cout<<"enter r:";
   cin>>r;
   int nfact =fact(n);
   int rfact = fact(r);
   int nrfact = fact(n-r);
   int ncr = nfact/(rfact*nrfact);
   cout<<"ncr is:"<<ncr;
   for(int i=2;i<=n;i++){
      fact *= i;

   }
   
  cout<<fact;
}