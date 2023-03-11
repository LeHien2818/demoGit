#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
int a[10][10];

 vector<pair<int,int> > luu;
bool check(int i,int j)
{
    for(int k=0;k<luu.size();k++)
        if(luu[k].x==i || luu[k].y==j || (luu[k].x-i==luu[k].y-j)) return false;
    return true;
}
void dequy(int u,int v)
{
    if(luu.size()==5) return;
    for(int i=u+1;i<=5;i++)
    for(int j=1;j<=5;j++)
    if (check(i,j)==1)
        {
            luu.push_back({i,j});
            a[i][j]=1;
            dequy(i,j);
            if(luu.size()==5) return ;
            luu.pop_back();
            a[i][j]=0;
        }
}
int main()
{
    luu.push_back({1,1});
    a[1][1]=1;
    dequy(1,1);
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
            cout<<a[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}
