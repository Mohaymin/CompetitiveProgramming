#include<bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C, N, f;
    cin >> A >> B >> C >> N;
    int ans;
    if(C > A || C > B)
    {
        ans = -1;
    }
    else
    {
        f = N + C - A - B;
        if(f >= 1)
        {
            ans = f;
        }
        else
        {
            ans = -1;
        }
    }
    cout << ans;
    return 0;
}
