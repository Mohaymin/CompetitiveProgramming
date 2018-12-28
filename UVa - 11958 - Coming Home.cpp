#include<bits/stdc++.h>
using namespace std;

int t, k, curh, curm;
int arh, arm, tme;
int reqtime;
int cnter;
int ans;
char ch;
int luoisLane, superMan;

int main()
{
    //freopen("_in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    vector<int> v;
    cin >> t;
    while(t--)
    {
        cin >> k;
        cin >> curh >> ch >> curm;
        luoisLane = curh*60+curm;

        ans = INT_MAX;
        while(k--)
        {
            cin >> arh >> ch >> arm >> tme;
            superMan = arh*60+arm;

            if(superMan<luoisLane)
            {
                superMan += 24*60;
            }
            ans = min(ans, superMan-luoisLane+tme);
        }
        cout << "Case " << ++cnter << ": " << ans << "\n";
    }
    return 0;
}
