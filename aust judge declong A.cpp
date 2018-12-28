#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    long long n, lim;
    while(cin >> n)
    {
        if(n==0)
            return 0;
        lim = sqrt(n);
        if(lim*lim == n)
        {
            cout << "yes";
        }
        else
        {
            cout << "no";
        }
        cout << "\n";
    }
}
