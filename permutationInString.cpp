#include <iostream>
#include <string>
using namespace std;

bool isSame(int freq[] , int windFreq[]){
    for (int i = 0 ; i < 26 ; i++){
        if (freq[i] != windFreq[i]){
            return false;
        }
    }

    return true;
}

int main(){
    string s2 = "eidbaooo";
    string s1 = "ab";
    int freq[26]={0};

    for (int i = 0 ; i < s1.length(); i++){
        freq[s1[i]-'a']++;
    }
    
    int winSize = s1.length();
    for (int i = 0 ; i < s2.length();i++){
        int windIdx = 0 ; int idx = i;
        int windFreq[26] = {0};
        while (windIdx < winSize && idx < s2.length()){
            windFreq[s2[idx]-'a']++;
            windIdx++ ; idx++;
        }

        if (isSame(freq , windFreq)){
            cout << true;
            return 1;
        }
    }
    cout << false;
    return 0;
}