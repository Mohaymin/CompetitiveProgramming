#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> mypair;

const int sz = 5e3+10;

bool visited[sz][sz];

int dist[sz][sz];
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};

bool isvalid(int x, int y)
{
    if(x<0 || y<0) return false;
    if(x>5000 || y>5000) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, q;
    int x, y;
    int x1, y1;
    queue<mypair> greynodes;
    cin >> n >> q;
    for(int i=0; i<n; i++)
    {
        cin >> x >> y;
        visited[x][y] = true;
        greynodes.push(make_pair(x, y));
    }
    //bfs
    //cout << "doing bfs" << endl;
    while(greynodes.empty()!=true)
    {
        x = greynodes.front().first, y = greynodes.front().second;
        //cout << x << ' ' << y << endl;
        greynodes.pop();
        for(int i=0; i<8; i++)
        {
            x1 = x+dx[i];
            y1 = y+dy[i];
            if(!isvalid(x1, y1))
                continue;
            if(visited[x1][y1])
                continue;
            //cout << "||||" << x1 << ' ' << y1 << endl;
            visited[x1][y1] = true;
            dist[x1][y1] = dist[x][y]+1;
            greynodes.push(make_pair(x1, y1));
        }
    }
    //done
    //cout << "BFS done" << endl;
    for(int i=0; i<q; i++)
    {
        cin >> x >> y;
        cout << dist[x][y] << '\n';
    }
    return 0;
}
