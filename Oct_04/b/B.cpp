
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

// Use long long to avoid overflow!
ll totalMale[10000];
ll totalFemale[10000];
// If we have M males and F females, we have (M + F) males and F + 1 females next year. (+1 female comes from the immortal bee )
int main()
{
    ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    totalMale[0] = 0;
    totalFemale[0] = 1;
    rep1(i,50){ // when you simulate it, you'll notice that after 47 years, two numbers exceed 2^32.
        totalMale[i] = totalMale[i-1] + totalFemale[i-1];
        totalFemale[i] = totalMale[i-1] + 1;
    }
    while(true){
        int N;
        cin >> N;
        if(N == -1) break;
        cout << totalMale[N] << " " << totalMale[N] + totalFemale[N] << endl;
    }
}
