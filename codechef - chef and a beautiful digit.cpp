#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string in, ans;
    char d;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> in >> d;
        for(char c: in)
        {
            if(c>d)
            {
                ans += d;
            }
            else
            {
                ans += c;
            }
        }
        for(int i=0; i<ans.size(); i++)
        {
            for(int j=i+1; j<ans.size(); j++)
            {
                if(ans[i]>ans[j])
                {
                    ans[i] = d;
                }
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans << '\n';
        ans.clear();
    }
    return 0;
}
