
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

//Solution: http://codeforces.com/blog/entry/51652

// Main Idea: if the gcd > 1, then the answer is 0.
// Otherwise, the only possible gcd should be 2, so every number should become even.
// Now, iterating from left ro right, for every number:
//      If it is odd, we need to do the operation on this number (once or twice depending on the parity of the next number).
//      If it is even, we don't need any operation for this index/number.
int A[100100];
int N;

int main()
{
	ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    cin >> N;
    // rep(i,N) is short for for(int i = 0; i < N; i++)
    rep(i,N) cin >> A[i];
    int g = A[0];
    rep(i,N){
        g = __gcd(g, A[i]);
    }
    cout << "YES" << endl;
    if(g >= 2){
        cout << 0 << endl;
    }else{
        int ans = 0;
        rep(i,N){
            // Odd number.
            if(A[i] % 2 == 1){
                // Check if it has a next number. 
                if(i + 1 < N){
                    // If next number is odd, 1 operation.
                    if(A[i+1] % 2 == 1){
                        ans += 1;
                    }else{
                        ans += 2;
                    }
                }else{
                    // If it is the last number, 2 operations needed.
                    ans += 2;
                }
                i += 1;
            }
        }
        cout << ans << endl;
    }
}
