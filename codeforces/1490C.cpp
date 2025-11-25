#include <iostream>
#include <cmath>
using namespace std;

bool isSumOfTwoCubes(long long n) {
    if (n <= 1) return false;  

    long long a = 1;
    long long b = cbrt((long double)n); 
    while ((b + 1) * (b + 1) * (b + 1) <= n) b++;
    while (b * b * b > n && b > 0) b--;

    while (a <= b) {
        long long aa = a * a * a;
        long long bb = b * b * b;
        long long s = aa + bb;

        if (s == n) return true;
        if (s > n) b--;
        else a++;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (isSumOfTwoCubes(n)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
