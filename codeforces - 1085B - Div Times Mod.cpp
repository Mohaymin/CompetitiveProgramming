#include<bits/stdc++.h>
using namespace std;

int n, k;
int x;
int dummy;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i=k-1; i>0; i--)
    {
        if(n%i==0)
        {
            dummy = n/i;
            x = dummy*k + i;
            break;
        }
    }
    cout << x << "\n";
    return 0;
}
