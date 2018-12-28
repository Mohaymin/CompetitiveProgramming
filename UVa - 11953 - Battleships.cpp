#include<bits/stdc++.h>
using namespace std;

const int sz = 110;

char grid[sz][sz];
bool visited[sz][sz];

int t, n;
int cnt, ans;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};


int dfs(int i, int j)
{
    int dum;
    if(i<0 || j<0)
    {
        return 0;
    }
    if(i>=n || j>=n)
    {
        return 0;
    }
    if(visited[i][j])
    {
        return 0;
    }
    if(grid[i][j] == '.')
    {
        return 0;
    }
    visited[i][j] = true;
    for(int k=0; k<4; k++)
    {
        dum = dfs(i+dx[k], j+dy[k]);
    }
    return 1;
}

int main()
{
    freopen("_in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> grid[i][j];
                visited[i][j] = false;
            }
        }

        ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='x')
                    ans += dfs(i, j);
            }
        }
        cout << "Case " << ++cnt << ": " << ans << "\n";
    }
    return 0;
}
