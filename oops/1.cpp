

#include <iostream>
#include <string>
using namespace std;


class Student {
private:
    float cgpa;

public:
    string name;

    //Setter
    void setCgpa(float newCgpa) {
        if(newCgpa < 0) {
            cout << "Invalid Data\n";
            return;
        }
    }



    int main(){


        Student s1;//object
        s1.name = "shradha";
        cout << s1.name << endl;

    }