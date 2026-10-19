

#include <iostream>
#include <string>
using namespace std;


class student{
 
public:
    string  name,
    string education ,
    float cgpa,

   //   methods  inside a public class //
    void percentage{
        cout<<(cgpa*10)<<"% "<<endl;
    }

};







int main(){
    student s;
    s.name="vansh";
    cout<<name<<endl;
}