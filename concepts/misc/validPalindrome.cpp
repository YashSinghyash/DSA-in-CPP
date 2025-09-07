#include <iostream>
#include <string>
using namespace std;

bool checkAlphaNumeric(char a){
    if ((a >='0' && a <='9') ||(tolower(a)>='a' && tolower(a)<='z') ){
        return true;
    }

    return false;
}

int main(){
    string s = "racec ar";
    int st = 0 ; 
    int end = s.length()-1;
    while (st < end){
        if (!checkAlphaNumeric(s[st])) {st++ ; continue;}
        if (!checkAlphaNumeric(s[end])) {end-- ; continue;}

        if (tolower(s[st])!=tolower(s[end]) ){
            cout << "False";
            return 0;
        }

        st++;
        end--;
    }
    cout <<"True";
    return 1;
}