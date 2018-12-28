#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll T, N;
ll id, baseSalary, transportation;
ll accomodation, tax, annual;

ll mxid, mnid;
ll mxincome, mnincome;

int main() {
    scanf("%lld", &T);
    while(T--){
        mxincome = numeric_limits<long long int>::min();
        mnincome = numeric_limits<long long int>::max();
        cin >> N;
        while(N--){
            scanf("%lld:%lld:%lld:%lld:%lld", &id, &baseSalary, &transportation, &accomodation, &tax);
            annual = baseSalary*12 + transportation*12 + accomodation - tax*12;
            if(annual > mxincome){
                mxincome = annual;
                mxid = id;
            }
            if(annual < mnincome){
                mnincome = annual;
                mnid = id;
            }
        }
        printf("%lld %lld %lld\n", mxid, mnid, mxincome-mnincome);
    }
    return 0;
}
