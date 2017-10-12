
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
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

// The problem is asking to find the minimum spanning tree among the keys where
// each key can be regarded as node, and the edge weights are the number of rolls needed to change keys.
// For each pair of key, it should be easy to calculate the number of rolls needed.
// The answer is MST + min edge weight from 0000 to one of the keys.
// The following is a template for Kruskal's algorithm

vector<piii> E; // List of edges. Contains an edge weight and a pair of vertices.
int L[505]; // Contains the link for Disjoint set union. DON'T forget to initialize the L[x] = x for all x.

//-------------------------------- To learn more about union-find, check stanford Stanford CS97SI, Data structures slide.
int find(int x){
        return x == L[x] ? x : L[x] = find(L[x]);
}

void unite(int x, int y){
    L[find(x)] = find(y);
}

int isSame(int x, int y){
    return find(x) == find(y);
}

//---------------------------------
int kruskal(){
    rep(i,505) L[i] = i;
    sort(E.begin(), E.end());
    int cost = 0;
    rep(i,sz(E)){
        auto e = E[i];
        int u = e.second.first;
        int v = e.second.second;
        int c = e.first;
        if(!isSame(u, v)){
            cost += c;
            unite(u,v);
        }
        // We could terminate once we unite every node, but it is fast enough for the time constraint.
    }
    return cost;
}
////////////////////////////////////////

string A[505];
int main()
{
    ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    int T;
    cin >> T;
    rep(hello,T){
        int N;
        cin >> N;
        rep(i,505) A[i] = "";
        E.clear();
        rep(i,N) {
            cin >> A[i];
        }
        int minCostTo0 = 40;
        rep(i,N){
            rep(j,N){
                if(i != j){
                    int cost = 0;
                    rep(k,4){
                        int dist = 9;
                        int c1 = A[i][k] - '0';
                        int c2 = A[j][k] - '0';
                        dist = min(dist, max(c1,c2) -min(c1,c2));
                        dist = min(dist, min(c1,c2)+10-max(c1,c2));
                        cost += dist;
                    }
                    E.pb(mp(cost,mp(i,j)));
                }
            }
            int cost = 0;
            rep(k,4){
                int c1 = A[i][k] - '0';
                cost += min(c1, 10-c1);
            }
            minCostTo0 = min(minCostTo0, cost);
        }
        cout << kruskal() + minCostTo0 << endl;
    }
}
