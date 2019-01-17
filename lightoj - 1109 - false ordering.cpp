#include<bits/stdc++.h>
using namespace std;

const int N = 1001;

int arr[N+10];
vector< pair<int, int> > v;

int getdivisorcount(int n)
{
    int sq = sqrt(n);
    int total = 0;
    for(int i=1; i<=sq; i++)
    {
        if(n%i==0)
        {
            total+=2;
        }
    }
    if(sq*sq==n)
        total--;
    if(total==0)
    {
        total = 2;
    }
    return total;
}

void init()
{
    arr[1] = 1;
    v.push_back(make_pair(1, -1));
    for(int i=2; i<N; i++)
    {
        arr[i] = getdivisorcount(i);
        v.push_back(make_pair(arr[i], -i));
    }
    sort(v.begin(), v.end());
}

int main()
{
    //freopen("_in.txt", "r", stdin);
    //freopen("_out.txt", "w", stdout);
    init();
    int t, n;
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
    {
        scanf("%d", &n);
        printf("Case %d: %d\n", i, (0-v[n-1].second));
    }
    return 0;
}
