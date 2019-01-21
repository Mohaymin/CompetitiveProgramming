#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    double d;
    cin >> t;
    while(t--)
    {
        cin >> d;
        cout << fixed << setprecision(2) << d*1.15 << '\n';
    }
    return 0;
}
