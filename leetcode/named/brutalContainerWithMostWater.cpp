#include <iostream>
using namespace std;

int main(){
    int he[] = {1,8,6,2,5,4,8,3,7};
    int si = 9; //size
    int Max_area = 0;
    for (int i = 0 ; i < si ; i++){
        for (int j = i+1 ; j < si ; j++){
            int area = min(he[i],he[j]) * (j-i) ;
            Max_area = max(area , Max_area);
        }
    }
    cout << Max_area;
}