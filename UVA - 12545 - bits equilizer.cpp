#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("_in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string s, t;
    int test;
    int ans, len, improper1, caseno = 0, makeone, q1, q2, swapped;
    cin >> test;
    while(test--)
    {
        cin >> s >> t;
        len = s.size();
        ans = improper1 = makeone = q1 = q2 = 0;
        for(int i=0; i<len; i++)
        {
            if(s[i]=='?')
            {
                if(t[i]=='1')
                {
                    q1++;
                }
                else
                {
                    q2++;
                }
            }
            else if(s[i]=='1' && t[i]=='0')
            {
                improper1++;
            }
            else if(s[i]=='0' && t[i]=='1')
            {
                makeone++;
            }
        }
        if(improper1>makeone+q1)
        {
            ans = -1;
        }
        else
        {
            ans = improper1; // swapped
            makeone = max(0, makeone-improper1); // remaining 0 that should be counted
            ans += q1 + q2 + makeone;
        }
        cout << "Case " << ++caseno << ": ";
        cout << ans << "\n";
    }
    return 0;
}
