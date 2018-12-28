#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, m, x, y;
int mxans;
int lim;
ll ans;

int getValue(int i, int j)
{
    int mxans;
    //mxans = m*n;
    mxans = n*m-n-m+1;//row and column
    mxans -= min(m-j-1, n-i-1);//low right diagonal
    mxans -= min(i, m-j-1);//up right diagonal
    mxans -= min(i, j);//up left diagonal
    mxans -= min(j, n-i-1);//low left diagonal
    if(x!=i && y!=j)
    {
        if(fabs(x-i)!=fabs(y-j))
        {
            mxans--;
        }
    }
    return mxans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;

    int upleft, upright, lowleft, lowright;

    while(t--)
    {
        cin >> n >> m >> x >> y;

        x--, y--;//coordinate of king

        ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ans += getValue(i, j);
            }
        }
        ans -= getValue(x, y);//(x, y) is not a valid position

        upleft = min(x, y);
        upright = min(x, m-y-1);
        lowleft = min(y, n-x-1);
        lowright = min(m-y-1, n-x-1);

        ans += 2*upleft*lowright;
        ans += 2*upright*lowleft;
        ans += 2*x*(n-x-1);
        ans += 2*y*(n-y-1);

        cout << ans << "\n";
    }

    return 0;
}
