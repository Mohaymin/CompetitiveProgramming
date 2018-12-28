#include<bits/stdc++.h>
using namespace std;

#define sz 120
typedef pair<int, int> mypair;
char table[sz][sz];

char ch;
int n, m;
int length, height;
mypair coordinate, initPos;

mypair getPositionOfB()
{
    int x, y;
    for(x=0; x<n; x++)
    {
        for(y=0; y<m; y++)
        {
            if(table[x][y]=='B')
            {
                return make_pair(x+1, y+1);
            }
        }
    }
}

int getLength(mypair pos)
{
    int i;
    for(i=pos.second; i<m; i++)
    {
        if(table[pos.first][i] != 'B')
        {
            return i;
        }
    }
    return i;
}

int getHeight(mypair pos)
{
    int i;
    for(i=pos.first; i<n; i++)
    {
        if(table[i][pos.second] != 'B')
        {
            return i;
        }
    }
    return i;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        gets(table[i]);
    }

    initPos = getPositionOfB();
    height = getHeight(initPos);
    length = getLength(initPos);

    coordinate.second = (initPos.second+length)/2;
    coordinate.first = (initPos.first+height)/2;

    cout << coordinate.first << " " << coordinate.second << "\n";
    return 0;
}
