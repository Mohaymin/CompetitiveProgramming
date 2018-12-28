#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t, n, k;
    char ch = 'a';
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i=0; i<n; i++)
        {
            cout << (char)(ch+(i%k));
        }
        cout << "\n";
    }
    return 0;
}
