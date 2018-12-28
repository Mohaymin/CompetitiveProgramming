#include<bits/stdc++.h>
using namespace std;

typedef double dd;

dd a, b, c;
dd s, sun, vio, ros, tri;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while(cin >> a >> b >> c)
    {
        s = (a+b+c)/2;
        tri = (s-a)*(s-b)*(s-c);
        ros = sqrt(tri/s);
        vio = tri-ros;
        sun = a*b*c/(4*tri);
        sun -= tri;
        cout << setprecision(4) << sun << " ";
        cout << setprecision(4) << vio << " ";
        cout << setprecision(4) << ros << "\n";
    }
    return 0;
}
