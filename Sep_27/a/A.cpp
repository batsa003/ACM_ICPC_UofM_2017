
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

// Refer to the pseudocode of fast exponentiation.
ll pow(ll base, ll exp, ll mod){
    ll ans = 1;
    while(exp){
        if(exp%2 == 1) ans = (ans * base) % mod;
        exp /= 2;
        base = (base*base) % mod;
    }
    return ans;
}
int main()
{
	ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    int C;
    cin >> C;
    rep(hello,C){
        ll x, y, n;
        cin >> x >> y >> n;
        cout << pow(x,y,n) << endl;
    }
}
