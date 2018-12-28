#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    queue<int> q;
    cin >> n >> m;
    int arr[m+1];
    int l, r;
    for(int i=1; i<=m; i++)
    {
        arr[i]=1;
    }
    for(int i=1; i<=n; i++)
    {
        cin >> l >> r;
        for(int j=l; j<=r; j++)
        {
            arr[j] = 0;
        }
    }
    for(int i=1; i<=m; i++)
    {
        if(arr[i]==1)
        {
            q.push(i);
        }
    }
    cout << q.size() << "\n";
    while(q.size()>1)
    {
        cout << q.front() << " ";
        q.pop();
    }
    if(q.size())
        cout << q.front();
    return 0;
}
