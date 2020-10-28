/*
 *     User: Rudr Tiwari (HumbleDynamics18 / dkodar)
 *     Problem: CSES Missing Number
 */

#include <bits/stdc++.h>
using namespace std;
void solve();

#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define RFOR(i,a,b) for(int i = a; i >= b; --i)
#define gcx getchar_unlocked
#define pcx putchar_unlocked
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
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
	ll n;
	cin >> n;

	int input;
	ll sum_of_given = 0;

	FOR(i, 0, n-1){

		cin >> input;
		sum_of_given += input;
	}

	ll sum = 0;

	sum = n*(n+1)/2;

	cout << sum - sum_of_given;	
}