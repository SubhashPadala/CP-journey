/*
 *     User: eu_18 
 *     Problem: Exponentiation
 */

#include <bits/stdc++.h>
using namespace std;
void solve();

#define ll long long
#define FOR(i,a,b) for(ll i = a; i < b; ++i)
#define RFOR(i,a,b) for(ll i = a; i >= b; --i)
#define gcx getchar_unlocked
#define pcx putchar_unlocked
const int mod = 1e9+7;
const int max = 1e6+1;

ll divisors[int(1e6+1)]={0};

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);



    int t=1;
    cin >> t;
    //cout<<0<<endl;
    for(ll i=1; i<int(1e6+1); i++)
    {
        int j=i;
        while(j<int(1e6+1))
        {
            divisors[j] = divisors[j]+1;
            j=j+i;
        }
        //cout<<divisors[i];
    }
    while(t--)
    {
        solve();
        //cout << "\n";
    }

    cerr << "time taken : " << (float)clock()/CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}


void solve()
{
    ll n;
    cin>>n;
    cout<<divisors[n]<<"\n";
}
