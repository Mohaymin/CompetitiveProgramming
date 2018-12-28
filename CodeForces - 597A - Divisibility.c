#include<stdio.h>
#include<math.h>
long long calc(long long x, long long y, long long k, int z)
{
    return (y/k - x/k + z);
}
int main()
{
    long long k, a, b;
    long long result;
    scanf("%lld%lld%lld", &k, &a, &b);
    if(a<0 && b<0) result = calc(-b-1,-a,k,0);
    else if(a<=0 && b>=0) result = calc(a,b,k,1);
    else if(a>=0 && b>=0) result = calc(a-1,b,k,0);
    printf("%lld", result);
    return 0;
}
