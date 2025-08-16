#include <iostream>
using namespace std;

int main(){
    int inte[]={11,12,-1,20,-50};
    int small = INT_MAX;
    for (int i ; i <5 ; i++){
        if (inte[i] < small){
            small = inte[i];
        }
    }
    cout << small;
    return 0;
}