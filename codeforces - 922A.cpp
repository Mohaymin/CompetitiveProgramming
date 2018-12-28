#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, copies;
    cin >> x >> y;
    copies=y-1;
    if(y==0 || copies>x || (x-copies)%2!=0)
        puts("No");
    else if((y==1&&x!=0)|| (x-copies)<0)
        puts("No");
    else
        puts("Yes");
    return 0;
}
