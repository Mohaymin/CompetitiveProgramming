#include<bits/stdc++.h>
using namespace std;

int n;
int sum;
bool ans;
string input;
map<char, int> frequency;
set<char> allChars;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> input;

    for(int i=0; i<input.size(); i++)
    {
        allChars.insert(input[i]);
        frequency[input[i]]++;
    }

    ans = false;
    for(set<char>::iterator it = allChars.begin();  it!= allChars.end(); it++)
    {
        if(frequency[*it] > 1)
        {
            ans = true;
            //break;
        }
//        if(frequency[*it] == 1)
//        {
//            sum++;
//        }
    }

    if(ans)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    cout << "\n";
    return 0;
}
