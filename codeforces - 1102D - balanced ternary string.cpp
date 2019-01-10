#include<bits/stdc++.h>
using namespace std;

const int sz = 3e5+5;

int n;
int segment;
int delzero, delone, deltwo;
int cntzero, cntone, cnttwo;

vector<int> zero, one, two;

string str;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> str;
    for(int i=0; i<n; i++)
    {
        if(str[i]=='0') zero.push_back(i);
        else if(str[i]=='1') one.push_back(i);
        else if(str[i]=='2') two.push_back(i);
    }
    segment = n/3;
    cntzero = zero.size();
    cntone = one.size();
    cnttwo = two.size();
    delzero = max(0, cntzero-segment);
    delone = max(0, cntone-segment);
    deltwo = max(0, cnttwo-segment);
    //delete two
    for(int i=0; i<two.size() && deltwo>0; i++)
    {
        if(cntzero<segment)
        {
            str[two[i]] = '0';
            deltwo--;
            cntzero++;
        }
        else if(cntone<segment)
        {
            str[two[i]] = '1';
            deltwo--;
            cntone++;
        }
    }
//    cout << "Deleted two" << endl;
    //delete one
    if(cntzero<segment)
    {
        for(int i=0; i<one.size() && delone>0 && cntzero!=segment; i++)
        {
            str[one[i]] = '0';
            delone--;
            cntzero++;
        }
    }
    if(cnttwo<segment)
    {
        for(int i=one.size()-1; i>=0 && delone>0 && cnttwo!=segment; i--)
        {
            str[one[i]] = '2';
            delone--;
            cnttwo++;
        }
    }
//    cout << "Deleted one" << endl;
    //delete zero
    for(int i=zero.size()-delzero; i<zero.size() && delzero>0; i++)
    {
        if(cntone<segment)
        {
            str[zero[i]] = '1';
            delzero--;
            cntone++;
        }
        else if(cnttwo<segment)
        {
            str[zero[i]] = '2';
            delzero--;
            cnttwo++;
        }
    }
//    cout << "Deleted zero" << endl;
    cout << str << '\n';
    return 0;
}
