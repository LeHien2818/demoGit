#include<bits/stdc++.h>
using namespace std;

int countEven(int *arr, int n){
    int dem = 0;
    for(int i = 0; i < n; i++)
        if(*(a+i) % 2 == 0)
            dem++;
    return dem;
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0;i < n; i++)
        cin >> *(arr + i);
    cout << countEven(a, n);
    return 0;
}
