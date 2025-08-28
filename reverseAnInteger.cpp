#include <iostream>
using namespace std;

int main(){
    int n = 1234;
    int rev = 0;
    while (n!=0){
        int dig = n%10;
        rev = (rev *10) + dig;
        n = n/10;
    }

    cout << rev;

}