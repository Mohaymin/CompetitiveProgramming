#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, minStep, maxStep, ans;
    cin>>n>>m;
    maxStep=n;
    minStep=(n+1)/2;
    if(maxStep<m)
    ans=-1;
    else
    {
        while(minStep%m!=0&&minStep<=n)
        {
            minStep=minStep+m-minStep%m;
        }
        ans=minStep;
    }
    cout<<ans<<endl;
}
