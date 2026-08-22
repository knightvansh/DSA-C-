#include<iostream>
using namespace std;


char getmaxchar(){

  int arr[26]={0};
  for(int i=0;i<s.length();i++){
    char ch=s[i];
    int number=0;
    if(ch >='a'&& ch <='z'){

    }
  }
}

char toLowerCase(char ch){
    if(ch >='a'&&ch <='z')
      return ch;
  else{
    char temp=ch-'A'+'a';
    return temp;
     }
}

bool checkpallindrome(char a[],int n){
    int s=0;
    int e=n-1;
    while(s<=e)
    {
     if(toLowerCase(a[s])!= toLowerCase(a[e]))
     {
        return 0;
     }
     else
     {
        s++,e--;
     }
     return 1;
    }

}


char reverse(char str[],int n){
      int s=0;
      int e=n-1;
      while(s<e){
    swap(str[s++],str[e--]);
           }
  }

 int getLength(char str[]){
        int count=0;
        for(int i=0;str[i]!= '\0'   ;i++   ){
            count++;
        }
        return count;
    }


int  main()
{
// char str[20];
// cout<<"enter your name"<<endl;
// cin>>str;
// cout<<"my name is" ;
// cout<<str;

// cout<<"length of my name is:"<<getLength(str)<<endl;
// int len=getLength(str);

// reverse( str,len);
// cout<<"reverse :"<<str<<endl;

     
// cout<<"pallindrome check:"<<checkpallindrome(str,len)<<endl;

// cout<<"CHaracter is:"<<toLowerCase('C')<<endl;


}