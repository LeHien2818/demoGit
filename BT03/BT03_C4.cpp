#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#define endl '\n'
#define pb push_back

int row, col;
int temp[100][100], ans[100][100];
char mine[100][100];

void solve()
{
    cin >> row >> col;
    for (int i = 1; i <= row; i++){
        for (int j = 1; j <= col; j++){
            cin >> mine[i][j];
            if (mine[i][j] == '*')
                temp[i][j] = 1;
            else temp[i][j] = 0;
        }
    }

    for (int i = 1; i <= row; i++){
        for (int j = 1; j <= col; j++){
            if (mine[i][j] == '.'){
                ans[i][j] = temp[i - 1][j - 1] + temp[i - 1][j] + temp[i - 1][j + 1] + temp[i][j - 1] + temp[i][j + 1] + temp[i + 1][j - 1] + temp[i + 1][j] + temp[i + 1][j + 1];
            }
            if (mine[i][j] == '*')  cout << '*' << ' ';
            else cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    solve();
}

