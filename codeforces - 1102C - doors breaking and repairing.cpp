#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, x, y;
    int input, breakable, unbreakable, ans;
    breakable = unbreakable = 0;
    cin >> n >> x >> y;
    for(int i=0; i<n; i++)
    {
        cin >> input;
        if(input>x)
        {
            unbreakable++;
        }
        else
        {
            breakable++;
        }
    }
    if(x>y)
    {
        ans = n;
    }
    else
    {
        ans = (breakable+1)/2;
    }
    cout << ans << '\n';
    return 0;
}
