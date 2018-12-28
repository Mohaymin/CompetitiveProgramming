///ACCEPTED!
#include<bits/stdc++.h>
#define lim 100010
using namespace std;

int arr[lim];

int main()
{
    int N, Ai;
    int i;
    string c="Conan", a="Agasa";
    bool ConanWins;

    cin >> N;

    int in;

    for(i=0; i<N; i++)
    {
        cin >> in;
        arr[in]++;
    }

    for(i=lim-1, ConanWins=false; i>=0; i--)
    {
        if(arr[i]%2==1) ConanWins=true;
    }

    if(ConanWins) cout << c << endl;
    else cout << a << endl;
    return 0;
}
