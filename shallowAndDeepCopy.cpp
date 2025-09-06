#include <iostream>
#include <string>

using namespace std;

class Student{
public:
string name;
double *cgpaPtr;

Student(string name , double cgpa){
    this -> name = name;
    cgpaPtr = new double;
    *cgpaPtr = cgpa;
}

// Student (Student &obj){
//     this-> name = obj.name;
//     this-> cgpaPtr = obj.cgpaPtr;
// }
Student (Student &obj){
    this-> name = obj.name;
    cgpaPtr = new double;
    *cgpaPtr = *obj.cgpaPtr;
}


};


int main(){
    Student s1("yash", 9.9);
    Student s2(s1);
    *(s2.cgpaPtr) = 9.0;
    cout << *s1.cgpaPtr;



}

