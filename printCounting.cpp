#include <iostream>
using namespace std;

void prico(int n){
    if (n == 0){
        cout << n;
        return;
    }
        cout << n << endl;
        prico(n-1);
}

int main(){
    cout << "Enter number to print counting from 0  ";
    int n;

    cin >> n;

    prico(n);

}