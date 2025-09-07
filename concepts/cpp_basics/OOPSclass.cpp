#include <iostream>
#include <string>

using namespace std;

class Teacher{
private:
    int salary;


public:
    string name;
    string dept;

    void setSalary(int sal){
        salary = sal;
    }

    void getSalary(){
        cout << salary;
    }



};


int main(){
    Teacher t1;
    t1.name = "Yash";

    t1.setSalary(1500000);
    t1.getSalary();

}