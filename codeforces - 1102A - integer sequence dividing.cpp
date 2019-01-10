#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans;
    cin >> n;
    if(n%2==0)
    {
        if((n/2)%2==0)
        {
            ans = 0;
        }
        else
        {
            ans = 1;
        }
    }
    else
    {
        if((n/2)%2==0)
        {
            ans = 1;
        }
        else
        {
            ans = 0;
        }
    }
    cout << ans << '\n';
    return 0;
}
