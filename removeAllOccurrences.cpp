#include <iostream>
#include <string>

using namespace std;

int main(){

    string str = "abccdeabc";
    string part = "abc";
    while (str.length()>0 && str.find(part)<str.length()){
        str.erase(str.find(part),part.length());
    }

    cout << str;
    return 0;
}