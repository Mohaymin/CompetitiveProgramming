#include<bits/stdc++.h>
using namespace std;

int n;
string s, t;
int ans;
bool found;
int pos;
queue<int> positions;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s >> t;
    for(int i=0; i<n; i++)
    {
        if(s[i]==t[i])
        {
            continue;
        }
        found = false;
        for(int j=i+1; j<n; j++)
        {
            if(s[j]==t[i])
            {
                found = true;
                pos = j;
            }
        }
        if(found)
        {
            for(int j=pos-1; j>=i; j--)
            {
                swap(s[j], s[j+1]);
                positions.push(j+1);
                ans++;
            }
        }
        else
        {
            cout << "-1\n";
            return 0;
        }
    }
    cout << ans << "\n";
    while(positions.size()>1)
    {
        cout << positions.front() << " ";
        positions.pop();
    }
    if(positions.size()>0)
        cout << positions.front();
    return 0;
}
