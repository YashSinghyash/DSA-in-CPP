#include <iostream>
using namespace std;

bool isPrime(int n){
    for (int i = 2 ; i* i <= n ; i++){
        if (n%i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    int a = 23;
    bool ans = isPrime(a);

    if (ans){
        cout << "Prime";
    }
    else {
        cout << "Not Prime";
    }



    return 0;
}