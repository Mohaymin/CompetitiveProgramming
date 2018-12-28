#include<bits/stdc++.h>
using namespace std;

int n, cnt, sum, input, given, hastogive;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while(cin >> n)
    {
        if(n==0)
            return 0;
        sum = given = hastogive = 0;
        while(n--)
        {
            cin >> input;
            if(input==0)
            {
                given++;
            }
            else
            {
                hastogive++;
            }
        }
        cout << "Case " << ++cnt << ": ";
        cout << hastogive-given << "\n";
    }
    return 0;
}
