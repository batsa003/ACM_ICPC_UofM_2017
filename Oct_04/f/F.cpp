
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

// Read about bitmask dp here.
// https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/tutorial/
// dp[S] denotes the minimum distance achieved by pairing the elements in S.
// dp[S] is the maximum of {dp[S'] + dist(i,j)} for all (i,j) pairs in S and S' = S \{i,j}. (exclude i,j).

double dist[20][20];
double X[20], Y[20];
double DP[66000];

void print(int mask){
    bitset<16> bits(mask);
    cout << bits << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cout.precision(2); cout << fixed; cout.tie(0); cin.tie(0);
    int testcase = 0;
    while(true){
        testcase++;
        int N;
        cin >> N;
        if(N == 0) break;
        clr(X);
        clr(Y);
        clr(dist);
        rep(i,2*N) {
            string name; cin >> name;
            cin >> X[i] >> Y[i];
        }

        rep(i,2*N) rep(j,2*N) dist[i][j] = sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]));

        rep(i,66000) DP[i] = INF;
        DP[0] = 0;
        rep(mask,1<<(2*N)){ // mask & (1 << i) means i-th  guy is in the set.
            rep(i,2*N) rep(j,2*N) if(i!=j){
                if((mask & (1 << i)) && (mask & (1 << j))){ // if i,j are in the set,
                    int newmask = mask ^ (1 << i) ^ (1 << j); // set i-th, and j-th bit to 0. newmask is S'.
                    DP[mask] = min(DP[mask], DP[newmask] + dist[i][j]);
                }
            }
        }
        cout << "Case " << testcase << ": " << DP[(1<<(2*N))-1] << endl;
    }
}
