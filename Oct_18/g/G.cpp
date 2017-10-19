
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

ll C[33][33];
int main()
{
    ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    rep(i,33) C[i][0] = 1;
    C[1][1] = 1;
    for(int n = 2; n < 33; n++){
        for(int k = 1; k <= n; k++){
            if(k == n) C[n][k] = 1;
            else{
                C[n][k] = C[n-1][k] + C[n-1][k-1];
            }
        }
    }
    int N;
    cin >> N;
    rep(hello,N){
        int n,m;
        cin >> n >> m;
        cout << C[n][n-m+1] << " " << C[n][n-m+1]*(n-m+1)/n << endl;
    }
}
