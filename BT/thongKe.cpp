#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n + 1];
    double tong = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        tong += arr[i];
    }
    int mina = arr[0];
    int maxa = arr[0];
    for(int i = 0; i < n; i++){
        if(maxa < arr[i]){
            maxa = arr[i];
        }
        if(mina> arr[i]){
            mina = arr[i];
        }
    }
    cout << tong / n << " " << maxa <<" " << mina;
}
