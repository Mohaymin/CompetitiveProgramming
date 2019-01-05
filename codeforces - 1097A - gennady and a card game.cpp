#include<bits/stdc++.h>
using namespace std;

int main()
{
    string hand, table;
    cin >> hand;
    bool ans = false;
    for(int i=0; i<5; i++)
    {
        cin >> table;
        if(hand[0]==table[0] || hand[1]==table[1])
        {
            ans = true;
            break;
        }
    }
    if(ans)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    cout << '\n';
    return 0;
}
