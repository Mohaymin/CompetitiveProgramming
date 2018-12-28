#include<bits/stdc++.h>
using namespace std;

string n;
int t, sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        sum = 0;
        for(int i=0; i<n.size(); i++)
        {
            sum += n[i]-'0';
        }
        cout << sum << "\n";
    }
    return 0;
}
