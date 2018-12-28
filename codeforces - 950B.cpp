#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    int ans = 0;
    int in, a, b;
    queue<int> qA, qB;

    cin >> n >> m;

    while(n--)
    {
        cin >> in;
        qA.push(in);
    }
    while(m--)
    {
        cin >> in;
        qB.push(in);
    }
    a = qA.front();
    b = qB.front();
    while(!qA.empty() && !qB.empty())
    {
        if(a==b)
        {
            ans++;
            qA.pop(), qB.pop();
            a = qA.front();
            b = qB.front();
        }
        else if (a>b)
        {
            qB.pop();
            b+=qB.front();
        }
        else
        {
            qA.pop();
            a+=qA.front();
        }
    }
    cout << ans << endl;
    return 0;
}
