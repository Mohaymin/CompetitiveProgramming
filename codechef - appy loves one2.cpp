#include<bits/stdc++.h>
using namespace std;

const int sz = 100010;

int arr[sz];

int lim;
int dummy;
int k, n, q;
int rightShift;

string query;

vector<int> v;
//vector<vector<int>> varr;

int lcs(int rightShift)
{

    int cnt = 0;
    int ans = -1;
    int start;
    if(rightShift%n==0)
    {
        start = 0;
    }
    else
    {
        start = n - (rightShift%n);
    }
    int i=start;
    do
    {
        if(arr[i]==1)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        ans = max(ans, cnt);
        i = (i+1)%n;
    } while(i!=start);
    if(ans > k)
    {
        ans = k;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q >> k;

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    for(int i=0; i<n; i++)
    {
        v.push_back(lcs(i));
    }
    cin >> query;
    for(int i=0; i<q; i++)
    {
        if(query[i] == '!')
        {
            rightShift++;
        }
        else
        {
            cout << v[rightShift%n] << "\n";
        }
    }
    return 0;
}
