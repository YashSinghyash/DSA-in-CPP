#include <iostream>
#include <string>
using namespace std;

int main(){
    char chars[] = {'a','a','b','b','c','c','c'};
    int idx = 0;
    int n = sizeof(chars)/sizeof(chars[0]);
    for (int i = 0; i < n ; i++){
        char ch = chars[i];
        int count = 0;
        while (i < n && chars[i] == ch ){
            count++ ; i++;
        }

        if (count == 1){
            chars[idx++] = ch;
        }

        if (count > 1){
            chars[idx++] = ch;
            string no = to_string(count);
            for (char dig : no){
                chars[idx++] = dig;
            }
        }
        i--;
    }

    cout<< idx;
}