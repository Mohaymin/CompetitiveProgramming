#include<bits/stdc++.h>
using namespace std;

int diffs[110];


int main()
{
    int ans=0;
    int n, data;
    cin >> n;
    double sum, gap, req;
    sum=0;
    for(int i=0; i<n; i++)
    {
        cin >> data;
        sum += data;
        diffs[i] = 5-data;
    }
    req = 4.5*n;
    gap = req - sum;
    sort(diffs, diffs+n, greater<int>());
    for(int i=0; i<n && gap > 0; i++)
    {
        gap -= diffs[i];
        ans++;
    }
    cout << ans << "\n";
    return 0;
}

/**
int main()
{
    int n, ans;
    double in, sum, req;
    double minGrade = 4.5;
    cin >> n;
    sum = 0;
    for(int i=0; i<n; i++)
    {
        cin >> in;
        sum += in;
    }
    req = minGrade*n;
    if(sum > req)
    {
        ans = 0;
    }
    else
    {
        ans = ceil(req-sum);
    }
    cout << ans;
    return 0;
}
*/
