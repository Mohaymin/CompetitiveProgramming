#include<bits/stdc++.h>
using namespace std;

string input;
int N;

void reverseUpto(int n)
{
    int lim = n/2;
    for(int i=0; i<=lim; i++)
    {
        swap(input[i], input[n-i]);
    }
}


int main()
{
    cin >> N >> input;
    for(int i=1; i<=N; i++)
    {
        while(N%i != 0)
        {
            i++;
        }
        if(i<=N)
        {
            reverseUpto(N/i-1);
            cout << input << endl;
        }
    }
    cout << input << "\n";
    return 0;
}
