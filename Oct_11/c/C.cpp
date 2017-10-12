
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
const int INF = 2e8;
const ll INFL = LLONG_MAX;
const ld pi = acos(-1);
// const int MOD = ;
typedef pair<int,int> pii;

int dist[1010];
vector<pii> G[1010];
int N,M;

int memo[1010];
// First of all, we need to calculate the shortest paths from all nodes to Node # 2 (house).
// Now, to calculate the # of ways to arrive, we can use memoization.
// Let ways[u] denote the number of ways to arrive at node 2 starting at node u.
// ways[2] = 1. From the problem description, 
// For all other node u, ways[u] is sum of ways[v] for all v with dist[v] < dist[u] (v has a shorter path).

void dijkstra(int src){
    rep1(i,N) dist[i] = INF;
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0,src});

    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto pr : G[u]){
            int v = pr.first;
            int next_dist = pr.second + dist[u];
            if(next_dist < dist[v]){
                dist[v] = next_dist;
                pq.push({next_dist,v});
            }
        }
    }
}

int solve(int from){
    if(memo[from] != -1) return memo[from];
    int ways = 0;
    for(auto p : G[from]){
        int to = p.first;
        if(dist[to] < dist[from]) ways += solve(to);
    }
    return memo[from] = ways;
}

int main()
{
    ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    while(true){
        cin >> N;
        if(N == 0) break;
        rep(i,1010) G[i].clear();
        cin >> M;
        rep(hello,M){
            int a,b,c;
            cin >> a >> b >> c;
            G[a].pb(mp(b,c));
            G[b].pb(mp(a,c));
        }
        dijkstra(2);
        rep(i,1010) memo[i] = -1;
        memo[2] = 1;
        cout << solve(1) << endl;
    }
}
