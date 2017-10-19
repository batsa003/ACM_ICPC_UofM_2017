
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

int N;
int A[20];
ll dp[20][40];

ll dfs(int ind, int cursum){
    if(ind == N) return 1;
    ll ans = 0;
    rep(m,A[ind]) ans += dp[ind+1][cursum-m];
    ans += dfs(ind+1, cursum-A[ind]);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    while(true){
        cin >> N;
        if(N == 0) break;
        clr(A);
        clr(dp);
        int totalRating = 0;
        rep(i,N) cin >> A[i];
        rep(i,N) totalRating += A[i];
        dp[N][0] = 1;
        for(int n = N-1; n >= 0; n--){
            for(int s = 0; s <= 30; s++){
                // starting at index n, sum is s.
                rep(m,s+1){
                    dp[n][s] += dp[n+1][s-m];
                }
            }
        }
        ll ans = 0;
        rep(s,totalRating) ans += dp[0][s];
        ans += dfs(0,totalRating);
        cout << ans << endl;
    }
}
