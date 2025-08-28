#include <iostream>
using namespace std;
pair <int,int> LinearSearch(int arr[][3],int r , int c, int key){
    for (int i = 0 ; i<r ; i++){
        for (int j = 0 ; j < c ; j++){
            if (arr[i][j] == key){
                return {i,j};
            }
        }
    }
}


int main(){


}
