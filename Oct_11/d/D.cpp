
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

int N,M;
vector<pair<int,int> > G[1010];
int D[1010];
// The problem is a direct application of Bellman Ford.

void bellman_ford(){
    rep(i,1010) D[i] = INF;
    D[0] = 0;
    rep1(k,N-1){
        rep(u,N){
            for(auto p : G[u]){
                int v = p.first;
                int c = p.second;
                D[v] = min(D[v], D[u] +c);
            }
        }
    }
    rep(u,N){
        for(auto p : G[u]){
            int v = p.first;
            int c = p.second;
            if(D[v] > D[u] + c){
                cout << "possible" << endl;
                goto DONE;
            }
        }
    }
    cout << "not possible" << endl; 
    DONE:
    int a = 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    int T;
    cin >> T;
    rep(hello,T){
        cin >> N >> M;
        rep(i,1010) G[i].clear();
        rep(i,M){
            int a,b,c;
            cin >> a >> b >> c;
            G[a].pb(mp(b,c));
        }
        bellman_ford();
    }
}
