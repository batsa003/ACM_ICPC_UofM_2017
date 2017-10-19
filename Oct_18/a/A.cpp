
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

ll memo[10000000];
ll solve(int N){
    if(N == 1){
        return 1;
    }else if(N == 2){
        return 3;
    }else if(N == 3){
        return 5;
    }else if(memo[N] > 0){
        return memo[N];
    }else{
        if(N%2 == 1){
            return memo[N] = solve(N/2)*2+N;
        }else{
            return memo[N] = solve(N/2-1) + solve(N/2) + N;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    int testcase = 0;
    int N;
    while(cin >> N){
        testcase++;
        cout << "Case " << testcase << ": " << solve(N) << endl;
    }
}
