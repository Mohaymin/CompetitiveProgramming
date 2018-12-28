#include<bits/stdc++.h>
using namespace std;

const int sz = 110;

char arr[sz][sz];

int ans;
int lim;
int cnt;
int len;
int t, n, m;
int limL, limR, limU, limD;

bool accepted;

string input;
queue<int> divisibles;

void goUp(int k, int i, int j);
void goDown(int k, int i, int j);
void goLeft(int k, int i, int j);
void goRight(int k, int i, int j);

int getAns(int n, int m)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(arr[i][j] != arr[i+1][j])
            {
                return -1;
            }
        }
    }
    return m+n;
}

void showArr(int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

int main()
{
    freopen("_in.txt", "r", stdin);
    freopen("_out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        ans = -1;
        cin >> input;
        len = input.size();
        if(len < 4)
        {
            cout << "Case " << ++cnt << ": " << ans << "\n";
            continue;
        }
        n = sqrt(len);
        for(int i=2; i<=n; i++)
        {
            if(len%i==0)
            {
                divisibles.push(i);
                divisibles.push(len/i);
            }
        }

        if(divisibles.empty())
        {
            cout << "Case " << ++cnt << ": " << ans << "\n";
            continue;
        }
        while(divisibles.empty() != true)
        {
            n = divisibles.front();
            divisibles.pop();
            m = divisibles.front();
            divisibles.pop();

            limL = limU = -1;
            limR = m;
            limD = n;
            goRight(0, 0, 0);
            ans = max(ans, getAns(n, m));

            if(m==n)
                continue;
            swap(n, m);
            limL = limU = -1;
            limR = m;
            limD = n;
            goRight(0, 0, 0);
            ans = max(ans, getAns(n, m));

        }
        cout << "Case " << ++cnt << ": " << ans << "\n";
    }
    return 0;
}


void goRight(int k, int i, int j)
{
    if(k >= len)
        return;
    while(j < limR)
    {
        arr[i][j] = input[k];
        j++;
        k++;
        if(k>=len)
            return;
    }
    limU++;
    goDown(k, i+1, j-1);
}

void goDown(int k, int i, int j)
{
    if(k>=len)
        return;
    while(i<limD)
    {
        arr[i][j] = input[k];
        i++;
        k++;
        if(k>=len)
            return;
    }
    limR--;
    goLeft(k, i-1, j-1);
}

void goLeft(int k, int i, int j)
{
    if(k>=len)
        return;
    while(j>limL)
    {
        arr[i][j] = input[k];
        j--;
        k++;
        if(k>=len)
            return;
    }
    limD--;
    goUp(k, i-1, j+1);
}

void goUp(int k, int i, int j)
{
    if(k>=len)
        return;
    while(i>limU)
    {
        arr[i][j] = input[k];
        i--;
        k++;
        if(k>=len)
            return;
    }
    limL++;
    goRight(k, i+1, j+1);
}
