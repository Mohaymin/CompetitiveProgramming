#include<bits/stdc++.h>
using namespace std;

const int NMAX = (1e6)+10;
const int M = (1e9)+7;

long long arr[NMAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    /// calculate
    arr[1] = 1;
    long long X, Y;
    for(int i=2; i<NMAX; i++)
    {
        X = arr[i-1];
        Y = i;
        arr[i] = ((X+Y)%M + (X*Y)%M)%M;
    }
    /// calculation complete
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << arr[n] << '\n';
    }
    return 0;
}
