#include <bits/stdc++.h>

using namespace std;

bool checkPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    if(checkPrime(n)) cout << 1;
    else cout << 0;
    for (int i = 2; i <= n; i++)
    {
        if(checkPrime(i)) cout << i << " ";
    }
    return 0;
}
