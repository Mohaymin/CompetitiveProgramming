/// YET TO BE SOLVED
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 32

vector<ll> table[sz];
vector<ll> row, column;
ll x, y;
ll test;
ll num, N;
ll rowPos, colPos;
ll ans;
bool found;

ll getRow(ll num)
{
    ll i;
    for(i=1; i<sz; i++)
    {
        if(table[i][1] == num)
        {
            return i;
        }
        else if(table[i][1] > num)
        {
            return i-1;
        }
    }
}

ll getCol(ll n, ll num)
{
    found = false;
    for(ll i=1; i<table[n].size(); i++)
    {
        if(table[n][i] == num)
        {
            found = true;
            return i;
        }
        else if(table[n][i] > num)
        {
            found = false;
            return i;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    row.push_back(0);
    column.push_back(0);
    for(ll x=0; x<sz-1; x++)
    {
        row.push_back(1<<x);
        column.push_back(1<<x);
    }
    for(ll i=0; i<sz; i++)
    {
        for(ll j=0; j<sz; j++)
        {
            table[i].push_back(row[i]+column[j]);
        }
    }
    cin >> test;
    while(test--)
    {
        cin >> N;
        if(N==1)
        {
            cout << "1\n";
            continue;
        }
        rowPos = getRow(N);
        colPos = getCol(rowPos, N);
//        cout << "ROW: " << rowPos << "\tCOL: " << colPos << endl;
        if(found)
        {
            if(rowPos == colPos)
            {
                ans = min(
                          fabs(N - table[rowPos][colPos-1]),
                          fabs(table[rowPos][colPos+1] - N)
                      );
            }
            else
            {
                ans = 0;
            }
        }
        else
        {
            ans = min(
                      fabs(N - table[rowPos][colPos-1]),
                      fabs(table[rowPos][colPos] - N)
                  );
        }
        cout << ans << "\n";
    }
    return 0;
}
