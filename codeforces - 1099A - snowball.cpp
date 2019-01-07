#include<bits/stdc++.h>
using namespace std;

int arsum(int a, int b)
{
    return ((b-a+1)*(a+b)+1)/2;
}

int main()
{
    int w, h, u1, d1, u2, d2;
    cin >> w >> h >> u1 >> d1 >> u2 >> d2;
    if(d1<d2)
    {
        swap(d1, d2);
        swap(u1, u2);
    }
    int weight = w;
    weight += arsum(d1, h);
    weight -= u1;
    if(weight<0)
    {
        weight = 0;
    }
    weight += arsum(d2, d1-1);
    weight -= u2;
    if(weight<0)
    {
        weight = 0;
    }
    weight += arsum(0, d2-1);
    cout << weight;
    return 0;
}
