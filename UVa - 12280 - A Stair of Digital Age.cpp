#include<bits/stdc++.h>
using namespace std;

const int grlen = 18;
const int grheight = 7;

const int lpart = 8;
const int rpart = 9;

string dummystring;

char dummychar;
char grid[grheight][grlen];

int t, tcase;
int lpos, rpos;
int lweight, rweight;

int weightOf(char c)
{
    int num = (int) c;
    int weight = 0;
    while(num>0)
    {
        if((num&1)==1)
        {
            weight += 500;
        }
        else
        {
            weight += 250;
        }
        num = num >> 1;
    }
    return weight;
}

int getweight(int start)
{
    int lim = start+lpart;
    int weight = 0;
    for(int i=0; i<grheight; i++)
    {
        for(int j=start; j<lim; j++)
        {
            dummychar = grid[i][j];
            if(dummychar>='A' && dummychar<='Z')
            {
                weight += weightOf(dummychar);
            }
        }
    }
    return weight;
}

int getposleft()
{
    int i=4, j=3;
    if(grid[i][j]=='_')
        return i;
    i++;
    if(grid[i][j]=='_')
        return i;
    return ++i;
}

int getposright()
{
    int i=4, j=13;
    if(grid[i][j]=='_')
        return i;
    i++;
    if(grid[i][j]=='_')
        return i;
    return ++i;
}

bool isokay()
{
    if(lweight>rweight && lpos>rpos)
    {
        return true;
    }
    if(lweight==rweight && lpos==rpos)
    {
        return true;
    }
    if(lweight<rweight && lpos<rpos)
    {
        return true;
    }
    return false;
}

void rectifyfigure()
{
    return;
}

int main()
{
    freopen("_in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    cout << t << endl;
    while(t--)
    {
        for(int i=0; i<grheight; i++)
        {
            for(int j=0; j<grlen; j++)
            {
                cin >> grid[i][j];
            }
        }
        cin >> dummystring;
        // input is okay
        lweight = getweight(0);
        rweight = getweight(rpart+1);
        //cout << "GOT WEIGHT";
        lpos = getposleft();
        rpos = getposright();
        cout << "Case " << ++tcase << ":\n";
        if(isokay())
        {
            cout << "The figure is correct.";
            //code is okay till here
        }
        else
        {
            rectifyfigure();
            for(int i=0; i<grheight; i++)
            {
                for(int j=0; j<grlen; j++)
                {
                    cout << grid[i][j];
                }
                cout << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
