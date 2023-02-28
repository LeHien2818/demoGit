
#include <bits/stdc++.h>

using namespace std;

bool check(string a, string b) {
    for(int i = 0; i < a.size() / 2; i++)
        swap(a[i], a[a.size() - 1 - i]);
    return a == b;
}

int main() {
    int m;
    cin >> m;
    string arr[m];
    for(int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < m; i++)
        for(int j = 0; j < i; j++) {
        string str1 = arr[i];
        string str2 = arr[j];
        if(check(str1, str2)) {
            int x = str1.size();
            cout << x << " " << str1[x / 2] << endl;
            return 0;
        }
    }


}
