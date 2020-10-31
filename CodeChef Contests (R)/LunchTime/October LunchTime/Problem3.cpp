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

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    #endif

    int t=1;
    /*is Single Test case?*/cin >> t;
    while(t--)
    {
        solve();
        //cout << "\n";
    }

    cerr << "time taken : " << (float)clock()/CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}

int longest_subsequence(int arr[], int n)
{
    int answer = 0;
 
    int prev = 0;
 
    FOR(i, 0, n) {

        if (prev != arr[i]) {
            prev = arr[i];
            answer++;
        }
    }
 
    return answer;
}


void solve()
{	
	int N, Q;
	cin >> N; cin >> Q;

	int arr[N];
	FOR(i, 0, N)
		cin >> arr[i];

	FOR(i, 0, Q){

		int x, y;
		cin >> x; cin >> y;

		arr[x-1] = y;

		cout << longest_subsequence(arr, N) << "\n";
	}
}