#include <bits/stdc++.h>

using namespace std;

int main(){
 cout << "nhap x1, y1, x2, y2";
 int x1, y1, x2, y2;
 cin >> x1 >> y1 >> x2 >> y2;
 double res = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
 cout << res;

}
