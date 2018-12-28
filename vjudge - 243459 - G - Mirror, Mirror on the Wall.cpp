#include<bits/stdc++.h>
using namespace std;

string table = "bdiopqvwx";
map<char, char> mirrorOf;
string input;

bool isValid(string str)
{
    for(int i=0; i<str.size(); i++)
    {
        if(binary_search(table.begin(), table.end(), str[i]))
        {
            continue;
        }
        return false;
    }
    return true;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    mirrorOf['b'] = 'd';
    mirrorOf['d'] = 'b';
    mirrorOf['p'] = 'q';
    mirrorOf['q'] = 'p';
    mirrorOf['i'] = 'i';
    mirrorOf['o'] = 'o';
    mirrorOf['v'] = 'v';
    mirrorOf['w'] = 'w';
    mirrorOf['x'] = 'x';

    while(cin >> input)
    {
        if(input=="#")
            return 0;
        if(!isValid(input))
        {
            cout << "INVALID";
        }
        else
        {
            for(int i=input.size()-1; i>=0; i--)
            {
                cout << mirrorOf[input[i]];
            }
        }
        cout << "\n";
    }
}
