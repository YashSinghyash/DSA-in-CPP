#include <iostream>
using namespace std;

void change(int a){
    a = 20;
}

void changePassbyReference(int * a){
    *a = 20;
}


void changePassByReferenceAlias(int &b){
    b = 30;
}

int main(){

    int a = 10;
    change(a);//Pass by Value
    cout << a << endl;; //Pass by Value
    changePassbyReference(&a);//Pass by Pointer
    cout << a << endl;; //Pass by Pointer
    changePassByReferenceAlias(a); //Pass By Alias 
    cout << a << endl; //Pass by Alias


}