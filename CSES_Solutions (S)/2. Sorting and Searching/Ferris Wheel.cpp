/*
 *     User: eu18
 *     Problem: Ferris Wheel.cpp
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

    //#ifndef ONLINE_JUDGE
    //freopen("inputf.txt", "r", stdin);
    //freopen("outputf.txt", "w", stdout);
    //#endif

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
    map<ll, ll> weight_count;
    ll n, x, weight;
    cin>>n>>x;
    while(n--){
        cin>>weight;
        weight_count[weight]+=1;
    }
    auto i = weight_count.begin();
    auto j = weight_count.end();
    ll count=0;
    while((i->first<(j->first))){
        if((i->first)+(j->first)<=x){
            i->second--;
            j->second--;
            count++;
            if(i->second==0)i++;
            if(j->second==0)j--;
        }
        else{
            count+=j->second;
            j->second=0;
            j--;
        }
    }
    if(i->first==j->first){
            count+=(i->second%2==0)?(i->second/2):(i->second/2+1);
            i->second=0;
    }
    for(auto i=weight_count.begin(); i!=weight_count.end(); i++){
        weight+=i->second;
    } 
    weight+=i->second;
    cout<<weight;
    cout<<"count"<<count<<endl;
    return;
}