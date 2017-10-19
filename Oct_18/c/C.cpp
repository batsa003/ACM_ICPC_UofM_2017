
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
pair<int,int> A[1000100];
pair<int,int> B[1000100];
int main()
{
    ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    int T = 0;
    while(cin >> N){
        T++;
        clr(A);
        clr(B);
        rep(i,N) cin >> A[i].first;
        rep(i,N) cin >> B[i].first;
        rep(i,N) A[i].second = i;
        rep(i,N) B[i].second = i;
        sort(A,A+N);
        sort(B,B+N);
        int agree = 1;
        cout << "Case "  << T << ": ";
        for(int i = N-1; i >= 0; i--){
            if(A[i].second != B[i].second){
                agree = 0;
                cout << (N-i) << endl;
                break;
            }
        }
        if(agree) cout << "agree" << endl;
    }
}
