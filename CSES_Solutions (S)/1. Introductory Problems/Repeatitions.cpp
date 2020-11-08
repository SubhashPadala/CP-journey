/*
 *     User: eu_18 
 *     Problem: 
 */

#include <bits/stdc++.h>
using namespace std;
void solve();

#define ll long long
#define FOR(i,a,b) for(ll i = a; i < b; ++i)
#define RFOR(i,a,b) for(ll i = a; i >= b; --i)
#define max_n int(1e6)


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int t=1;
    //cin >> t;
    while(t--)
    {
        solve();
        cout << "\n";
    }

    cerr << "time taken : " << (float)clock()/CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}


void solve()
{
    char last = '\0';
    string input;
    cin>>input;
    int count=0, maximum =0;
    for(auto c: input)
    {
        if(c!=last)
        {
            maximum = max(count, maximum);
            count = 0;
        }
        else count++;
        last = c;
    }
    cout<<max(count, maximum)+1;
    return;
}
