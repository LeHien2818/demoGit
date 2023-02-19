#include <bits/stdc++.h>

using namespace std;
bool check(int n)
{
    int dem = 0;
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n > 2)
    {
        for(int i = 2; i < n; i++)
        {
            if(n % i == 0)
            {
                dem ++;
            }
        }
    }
    if(dem != 0)
    {
        return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    if(check(n))
    {
        cout << "YES";
    }else
    {
        cout << "NO";
    }
    return 0;
}
