#include <iostream>
#include <vector>
using namespace std;



int main(){
    vector <vector<int>> matrix = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    int sR = 0 ; int eR = matrix.size()-1;
    int target = 300;
    int R=0;
    bool rofound = false;

    while(sR <= eR){
        int mid = sR + (eR-sR)/2 ;
        if (matrix[mid][0]<=target && target<=matrix[mid][matrix[0].size()-1]){
            R = mid;
            rofound = true;
            break;
        }
        else if (matrix[mid][0]>target){
            eR = mid-1;
        }

        else {
            sR = mid+1;
        }
    }

    if(rofound){
        int sc = 0 ; int ec = matrix[0].size()-1;
        while (sc<=ec){
        int mi = sc + (ec-sc)/2;
        if (matrix[R][mi]==target){
            cout << true;
            return 0;
        }

        else if (matrix[R][mi]>target){
            ec = mi-1;

        }

        else {
            sc = mi+1;
        }
    }
    }

    

    cout << false;
    return -1;


}