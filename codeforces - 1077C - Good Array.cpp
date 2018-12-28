#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int sz = 1e6+100;

int arr1[sz];
int arr2[sz];

int n, lim;

ll sum, mx, num1, num2;

bool mark[sz];

queue<ll> q;
mp<ll, int> contribute;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> arr1[i];
        arr2[i] = arr1[i];
        mx = max(mx, arr1[i]);
    }
    sort(arr2, arr2+n);
    for(int i=1; i<n; i++)
    {
        sum = arr2[i]+arr2[i-1];
        if(sum <= mx)
        {
            q.push(sum);
            mark[sum] = true;
        }
    }
    while(q.size()>=2)
    {
        num1 = q.front();
        q.pop();
        num2 = q.front();
        q.pop();
        sum = num1+num2;
        if(sum <= n)
        {
            q.push(sum);
        }
    }
    if(q.empty()!=true && q.front()<=mx)
    {
        mark[q.front()] = true;
        q.pop();
    }
    return 0;
}
