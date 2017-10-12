
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

vector<int> G[202];
int C[202];

bool dfs(int u, int col){ // start coloring the node u with color col. Return true if possible to color the tree.
    if(C[u] != -1){
        return C[u] == col; // if the color assigned conflights, return false.
    }else{
        C[u] = col; 
        for(int v : G[u]){
            if(!dfs(v, (col^1))) return false; // all neighbor should be able to color its subtree
                // if col == 1, col^1 = 0, and col == 0 -> col^1 = 1
        }
        return true;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    while(true){
        int N, M;
        cin >> N;
        if(N == 0) break;
        cin >> M;
        rep(i,202) G[i].clear();
        rep(i,202) C[i] = -1;
        rep(i,M){
            int a,b; cin >> a >> b;
            G[a].pb(b);
            G[b].pb(a);
        }
        if(dfs(0,0)){
            cout << "BICOLORABLE." << endl;
        }else{
            cout << "NOT BICOLORABLE." << endl;
        }
    }
}
