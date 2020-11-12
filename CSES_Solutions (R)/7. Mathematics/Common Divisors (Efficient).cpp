/*
 *     User: Rudr Tiwari (HumbleDynamics18 / dkodar)
 *     Problem: 
 */

#include <bits/stdc++.h>
using namespace std;
void solve();

#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define RFOR(i,a,b) for(int i = a; i >= b; --i)
#define gcx getchar_unlocked
#define pcx putchar_unlocked
#define ll long long

const int MAX_N = 1e6 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

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
	int n;
	cin >> n;
	int arr[n];

	FOR(i,0,n)
		cin >> arr[i];

	int _count[MAX_N] = {0};

	int maximum = 0;
	for(int v: arr){

		maximum = max(maximum, v);
		for (int i = 1; i*i <= v; i++){
			if (v%i == 0){
				_count[i] += 1;
				if (i != v/i)
					_count[v/i] += 1;
			}
		}
	}

	RFOR(i, maximum, 0){
		if (_count[i] > 1){
			cout << i;
			break;
		}
	}

	return;
}