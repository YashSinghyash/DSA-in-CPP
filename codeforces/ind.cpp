class Solution {
public:
    string toBinary(int n) {
        if (n == 0)
            return "0";
        string s = "";
        while (n > 0) {
            s += char('0' + (n & 1));
            n >>= 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    int minimumFlips(int n) {
        string og = toBinary(n);
        string rg = og;
        if (n==0) return 0;
        reverse(rg.begin(), rg.end());
        int count = 0;
        for (int i = 0 ; i < og.size() ; i++){
            if (og[i]!=rg[i])count++;
        }
        return count;
    }
};

class Solution {
public:
    int numberWavi(int number) {
        string num = to_string(number);
        if (num.length() < 3)
            return 0;
        int ans = 0;
        for (int i = 1; i < num.length() - 1; i++) {
            int prev = num[i - 1] - '0';
            int curr = num[i] - '0';
            int next = num[i + 1] - '0';

            if (curr > prev && curr > next) ans++; 
            if (curr < prev && curr < next) ans++;
        }
        return ans;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int i = num1; i <= num2; i++) {
            ans += numberWavi(i);
        }
        return ans;
    }
};

class Solution {
public:
    int numberWavi(int number) {
        string num = to_string(number);
        if (num.length() < 3)
            return 0;
        int ans = 0;
        for (int i = 1; i < num.length() - 1; i++) {
            int prev = num[i - 1] - '0';
            int curr = num[i] - '0';
            int next = num[i + 1] - '0';

            if (curr > prev && curr > next) ans++; 
            if (curr < prev && curr < next) ans++;
        }
        return ans;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int i = num1; i <= num2; i++) {
            ans += numberWavi(i);
        }
        return ans;
    }
};