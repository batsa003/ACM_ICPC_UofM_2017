
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

int N,Q;
ll A[220];
ll DP[220][11][22];
// DP[n][m][d] denotes the number of ways to choose at most m numbers among first n numbers
// such that their sum is d(mod D). d can be 0, 1, 2, ..., D-1.
// If n-th number is not chosen, then DP[n-1][m][d]
// If n-th number is chosen, then, remaining m-1 numbers are chosen from first n-1 numbers
// with their sum equal to d-A[n] (mod D)
int main()
{
    ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    int testcase = 0;
    while(true){
        cin >> N >> Q;
        testcase++;
        if(N == 0 && Q == 0) break;
        clr(A);
        rep1(i,N) cin >> A[i];
        cout << "SET " << testcase << ":" << endl;
        rep1(q,Q){
            int M,D;
            cin >> D >> M;
            clr(DP);
            DP[0][0][0] = 1; 
            rep1(l,N) DP[l][0][0] = 1; // with m = 0, only d = 0 gives only 1 way to choose. (Choosing nothing).
            // Using bottom up approach. It is important to iterate from n first, then m, then d.
            // This makes dp(n,m,d) possible to compute because dp(n-1,m,d) and dp(n-1,m-1,tmp) will be already calculated
            for(int n = 1; n <= N; n++) {
                for(int m = 1; m <= M; m++) {
                    for(int d = 0; d < D; d++) {
                        ll tmp = (d-A[n])%D;
                        if(tmp < 0) tmp += D;
                        DP[n][m][d] += DP[n-1][m][d];
                        DP[n][m][d] += DP[n-1][m-1][tmp];
                    }
                }
            }
            cout << "QUERY " << q << ": " << DP[N][M][0] << endl;
        }
    }
}
