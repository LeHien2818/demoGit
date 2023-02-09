#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n >= 0 && n % 5 == 0){
            cout << n / 5;
        }else{
                if(n == -1){
                cout << "Bye";
                break;
            }
            cout << -1;
        }

    }



}
