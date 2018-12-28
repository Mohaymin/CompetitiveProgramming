#include<bits/stdc++.h>
using namespace std;

//typedef long long LL;

bool isProbabilityZero(int pos1, int pos2, int ques)
{
    if(ques==0 && pos1!=pos2)
        return true;
    if(fabs(pos1-pos2)>ques)
        return true;
    return false;
}

bool isProbabilityOne(int pos1, int pos2, int ques)
{
    if(ques==0 && pos1==pos2)
        return true;
    return false;
}
/*
int permute(int n)
{
    int res=1;
    for(int i=1; i<=n; i++)
        res=res*i;
    return res;
}
double find_probability(int distance, int ques)
{
    double ans = (double)ncr(distance, ques)*(double)ncr()
}
*/

int ncr(int n, int r)
{
    if(r==0) return 1;
    if(n==r) return 1;
    if(r==1) return n;
    return ncr(n-1, r)+ncr(n-1, r-1);
}

int main()
{
    double ans;
    string s1, s2;
    int pos1, pos2, ques;
    pos1=pos2=ques=0;
    cin>>s1>>s2;
    //cout<<endl<<s1<<" "<<s2<<endl;
    for(int i=0; i<s1.size(); i++)
    {
        if(s1[i]=='+')
            pos1++;
        else
            pos1--;
    }
    for(int i=0; i<s2.size(); i++)
    {
        if(s2[i]=='+')
            pos2++;
        else if(s2[i]=='-')
            pos2--;
        else
            ques++;
    }
    //cout<<pos1<<" "<<pos2<<" "<<ques<<endl;
    if(isProbabilityZero(pos1, pos2, ques))
        ans=(double)0.0;
    else if(isProbabilityOne(pos1, pos2, ques))
        ans=(double)1.0;
    else
    {
        ans=ncr(ques, (abs(pos1-pos2)+ques)/2)*1.0;
        ans/=(1<<ques);
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
    return 0;
}
