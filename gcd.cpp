#include <iostream>
using namespace std;


int gcd(int a , int b){
    if (b==a){
        return a;
    }
    if (b==0) return a;
    if (a==0) return b;
    if (a > b){
        return gcd (a%b,b);
    }

    else if (a<b){
       return gcd (a,b%a);
    }


}

int main(){
    int gcda = gcd(20,28);
    cout << gcda;
}