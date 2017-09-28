
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define rep1(i, n) for (int (i) = 1; (i) <= (n); (i) ++)
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define db(x) {cout << #x << " = " << (x) << endl;}
#define dba(a, x, y) {cout<<#a<<" :";FOR(i123,x,y)cout<<setw(4)<<(a)[i123];cout<<endl;}
#define clr(x) memset(x,0,sizeof(x));
#define mp make_pair
#define pb push_back
#define sz(x) int((x).size())
typedef long long ll;
typedef long double ld;
const int INF = INT_MAX;
const ll INFL = LLONG_MAX;
const ld pi = acos(-1);
// const int MOD = ;
ll M;

// Given n, calculate the number of ways to choose (a, ak, ak^2, ak^3) such that ak^3<=n
ll numWays(ll n){
    ll count = 0;
    for(ll k = 2; k * k * k <= n; k++){
        // for a fixed k, a can be 1, 2, ... , n/(k^3).
        count += n / (k * k * k);
        // To avoid the overflow, when count is big enough, just return.
        if(count >= 1e15) return count;
    }
    return count;
}

int main()
{
	ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    cin >> M;
    ll low = 0;
    ll high = INFL/2;
    // For any i <= low, numWays(i) < M.
    // For any i >= high, numWays(i) >= M.
    while(low + 1 < high){
        ll mid = (high+low)/2;
        if(numWays(mid) < M) low = mid;
        else high = mid;
    }
    // After the loop, low + 1 = high.
    // Now, the smallest index high such that numWays(high) >= M. Check if it is actually equal to M.
    if(numWays(high) == M){
        cout << high << endl;
    }else{
        cout << -1 << endl;
    }
}
