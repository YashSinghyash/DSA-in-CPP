#include <iostream>
using namespace std;

int factorial (int n){
    if (n==0){
        return 1;
    }

    else{
        return n * factorial(n-1);
    }
}
int main(){
    int c = factorial(5);
    cout << c;
}