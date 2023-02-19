#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, nbfore;
    cin >> nbfore >> n;
    cout << nbfore << " ";
    while(n >= 0 ){
        if(n!= nbfore){
            cout << n << " ";
        }
            nbfore = n;
            cin >> n;
    }
    cout << n;
}

