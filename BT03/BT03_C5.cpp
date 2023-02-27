#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    int arr[m][n];
    int dong = m, cot = n, p = 0, k = 1, i;
    while(k <= m*n){
        for(i = p; i < cot; i++){
            arr[p][i] = k;
            k++;

        }
        for(i = p + 1; i < dong; i++){
            arr[i][cot - 1] = k;
            k++;

        }
        if(p!=dong-1){
            for(i = cot - 2; i >= p; i--){
                arr[dong - 1][i] = k;
                k++;

            }

        }
        if(p!=cot-1){
                for(i = dong-2; i > p; i--)
                    arr[i][p] = k++;
            }
        p++; dong--; cot--;
    }
    for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}


