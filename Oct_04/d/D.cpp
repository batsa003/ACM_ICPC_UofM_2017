
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

int A[2020];
int LIS[2020]; // LIS[i] is the length of the Longest Increasing Subsequence starting at index i (including i-th num in the sequence)
int LDS[2020]; // LDS[i] is the length of the Longest Decreasing Subsequence starting at index i (inclusive i-th num in the sequence

// Now, in the answer, let i be the first car to enter. Then, cars pushed at the front should be decreasing by weight.
// Then, cars pushed at the beginning should be increasing by weight.
// Notice that these two are disjoint, and we want to put as much as possible in the front and the back.
// Noticing that weights are increasing, it is same as finding longest increasing subsequence.
// So, the answer is max( LIS[i] + LDS[i] -1).
int main()
{
    ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    int T;
    cin >> T;
    rep(hello,T){
        int N;
        cin >> N;
        clr(A);
        clr(LIS);
        clr(LDS);
        rep1(i,N) cin >> A[i];
        if(N == 0){
            cout << 0 << endl;
            continue;
        }
        rep1(i,N) LDS[i] = 1;
        rep1(i,N) LIS[i] = 1;
        for(int i = N-1; i >= 1; i--){
            for(int j = i+1; j <= N; j++){
                if(A[j] > A[i]) LIS[i] = max(LIS[i], 1 + LIS[j]); // LIS at i-th can be constructed by inserting A[i] in the front of the LIS(j) as long as A[j] > A[i]
                else LDS[i] = max(LDS[i], 1 + LDS[j]); // Similar reasoning for LDS.
            }
        }
        int ans = 1;
        rep1(i,N){
            ans = max(ans, LIS[i]+LDS[i] -1);
        }
        cout << ans << endl;
    }
}
