#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from , char to , char helper){
    if (n == 0) return;

    towerOfHanoi(n-1,from,helper,to);

    cout << "Move " << n << "disk from " << from << " to" << to;

    towerOfHanoi(n-1,helper,to,from);
}

int main(){

    int n = 3;
    towerOfHanoi(n,'A','C','B');
    return 0;
}