#include <iostream>
using namespace std;

int main(){
    int a[] = {1,1,2,2,3,3,4,4,5};
    int siz = sizeof(a)/sizeof(a[0]);
    int st = 0 ;
    int end = siz-1;
    while (st <= end){
        int m = st + (end-st)/2;

        if (m==0 && a[m]!=a[m+1]){
            cout << a[0];
            return 0;
        }
        if (m==siz-1 && a[siz-1]!=a[m-1]){
            cout << a[siz-1];
            return 0;
        }
        else if (m!= 0 && m < siz-1 && a[m-1]!=a[m] && a[m]!=a[m+1]){
            cout << a[m];
            return 0;
        }

        else if (m%2==0){
            if (a[m+1]==a[m]){
                st = m+2;
            }
            else{
                end = m;
            }
        }
        else {
            if (a[m-1]==a[m]){
                st = m+1;
            } else {
                end = m -1;
            }
        }
    }


    }

