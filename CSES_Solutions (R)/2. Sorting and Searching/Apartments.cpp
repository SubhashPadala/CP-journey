/*
 *     User: Rudr Tiwari (HumbleDynamics18 / dkodar)
 *     Problem: Apartments
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
	int n,m,k;
	cin >> n; cin >> m; cin >> k;

	vector<int> demand;
	FOR(i, 0, n){
		int temp;
		cin >> temp;
		demand.push_back(temp);
	}

	vector<int> free;
	FOR(i, 0, m){
		int temp;
		cin >> temp;
		free.push_back(temp);
	}

	sort(demand.begin(), demand.end()); sort(free.begin(), free.end());

	int ans = 0;

	while (!demand.empty() and !free.empty()){

		if (free.back()-k <= demand.back() and demand.back() <= free.back()+k){

			ans += 1;
			demand.pop_back();
			free.pop_back();
		}

		else if (demand.back() > free.back()+k)
			demand.pop_back();

		else
			free.pop_back();
	}

	cout << ans;
}