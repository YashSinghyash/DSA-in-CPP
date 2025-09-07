#include <iostream>
using namespace std;

int main(){
    int he[] = {1,8,6,2,5,4,8,3,7};
    int si = 9; //size
    int Max_area = 0;
    int i = 0, j = si-1 ;
    while (i<j){
        Max_area = max(((j-i)*min(he[i],he[j])),Max_area);
        if(he[i]<he[j]){
            i++;
        }else{
            j--;
        }
    }
    cout << Max_area;
}