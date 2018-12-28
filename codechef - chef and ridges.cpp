#include<bits/stdc++.h>
using namespace std;

const int sz = 30;

int fiboNum[sz];

void findFibo()
{
    fiboNum[1] = fiboNum[2] = 1;
    for(int i=3; i<sz; i++)
    {
        fiboNum[i] = fiboNum[i-1] + 2*fiboNum[i-2];
    }
}

int getGcd(int a, int b)
{
    if(b==0)
        return a;
    return getGcd(b, a%b);
}

int main()
{
    //freopen("_in.txt", "r", stdin);
    //freopen("_out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t, n, ans;
    int x, y, gcd;
    findFibo();
    cin >> t;
    while(t--)
    {
        cin >> n;
        x = fiboNum[n];
        y = 1<<n;
        gcd = getGcd(y, x);
        cout << x/gcd << " " << y/gcd;
        if(t!=0)
            cout << " ";
    }
    return 0;
}
