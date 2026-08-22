#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
 vector<int> vec;
vec.push_back(20);
vec.push_back(10);
vec.push_back(50);
//  for(int i=0;i<vec.size();i++){
//     cout<<vec[i];
//vor(vector<int>::iterator it=vec.begin();
for (auto it=vec.begin();it!=vec.end();it++){
 cout<<*it<<" ";
}
cout<<endl;
vec.insert(vec.begin()+2,30);
 for(auto it=vec.begin();it!=vec.end();it++){
 cout<<*it<<" ";
 }
 cout<<endl;
 vec.pop_back();
 for(auto it=vec.begin();it!=vec.end();it++){
 cout<<*it<<" ";
}
cout<<endl;
vec.erase(vec.begin());
for(auto it=vec.begin();it!=vec.end();it++){
    for(auto it=vec.begin();it!=vec.end();it++){
 cout<<*it<<" ";
}
}




