#include <iostream>
using namespace std;

void printDigits(int n){
    while (n!=0){
        
        cout << n%10 << " ";
        n = n/10;
    }
}
int main(){
    int n = 1123;
    printDigits(n);
    cout << endl;
    cout << int(log10(n))+1;
    return 0;




    
}