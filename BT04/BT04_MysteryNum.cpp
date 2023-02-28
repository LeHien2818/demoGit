#include<bits/stdc++.h>

using namespace std;

int dem[10005];

int main()
{
    int n;
    cin >> n;

    int a[n],b[n+1];
    int maxa=-10005;

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        dem[a[i]]++;
        if(maxa<a[i])
        {
            maxa=a[i];
        }

    }
    for(int j=0;j<n+1;j++)
    {
        cin >> b[j];
        dem[b[j]]--;
    }
    for(int i=0;i<=maxa;i++)
    {
        if(dem[i]<0)
        {
            cout<<i;
        }

    }
    return 0;

}
