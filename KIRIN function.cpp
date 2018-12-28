#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


long long m = (long long)pow(2, 64);
int cnt;
ll a, b, c, n;
int test;

ll x(ll p) {
    if(p <= 1)
        return 1;
        //return 1%m;
    return (((b%m)*(x(p-1)%m))%m + ((c%m)*(x(p-2)%m)%m)%m)%m;
    //return b*x(p-1)+c*x(p-2);
}

ll f(ll p){
    if(p <= 1)
        return 1;
        //return 1%m;
    return (((a%m)*(f(p-1)%m))%m + ((b%m)*(f(p-2)%m))%m + x(p)%m)%m;
    //return a*f(p-1)+b*f(p-2)+x(p);
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> test;
    while(test--)
    {
        scanf("%lld%lld%lld%lld", &a, &b, &c, &n);
        printf("Case %d: %lld\n", ++cnt, f(n));
    }
    return 0;
}
