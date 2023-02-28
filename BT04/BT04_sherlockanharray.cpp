#include <bits/stdc++.h>

using namespace std;

int main() {
    int buoc;
    cin >> buoc;
    while(buoc--) {
        int n;
        cin >> n;
        int arr1[n];
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr1[i];
            sum += arr1[i];
        } int arr2[n];
        arr2[0] = arr1[0];
        bool m = true;
        for(int i = 1; i < n; i++)
            arr2[i] = arr2[i - 1] + arr1[i];
        for(int i = 0; i < n; i++)
            if(arr2[i] - arr1[i] == 1.0 * (sum - arr1[i]) / 2) {
                m = 0;
                break;
            }
        if(m)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
