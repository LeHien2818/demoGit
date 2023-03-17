#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[5];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arrdem[arr[i]] ++;
    }
    int maxa = arrdem[1];
    int idMax = 0;
    for(int i = 2; i < 6; i++){
        if(maxa < arrdem[i])
        {
            idMax = i;
        }
    }
    cout << idMax;
    return 0;
}

