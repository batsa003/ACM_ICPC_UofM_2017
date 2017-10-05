
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

int X[100100];
// Binary Search on the answer m.
// For any given m, we want to use as few access point as possible to cover all of the houses.
// To cover the first house, place the access point as far as possible to the right (which may help us to cover more houses).
// Once you place it, we don't need to cover the houses that are covered by this router.
// Now, go the first house that wasn't covered by this router.
// Repeat.
// This way, if we use more than N router, our distance m was too small for ideal answer. Otherwise, m was too big  (kind of).
int main()
{
    // Notice we are using cout.precision(1)
    ios_base::sync_with_stdio(0); cout.precision(1); cout << fixed; cout.tie(0); cin.tie(0);
    int T;
    cin >> T;
    rep(hello,T){
        int N,M;
        cin >> N >> M;
        rep(i,M) cin >> X[i];
        sort(X,X+M);
        if(N>=M) {
            cout << "0.0" << endl;
            continue;
        }else{
            double low = 0.0;
            double high = 1000000.01;
            while(high-low > 1e-9){
                double mid = (high + low) / 2;
                double last = -1000001;
                int needed = 0;
                rep(i,M){
                    if(X[i] - last > mid){ // Need to put the router at X[i] + mid.
                        last = X[i] + mid;
                        needed++;
                    }else{
                        // Otherwise, this house is covered by the last router.
                    }
                }
                if(needed > N) low = mid;
                else high = mid;
            }
            cout << (high) << endl;
        }
    }
}
