
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

// This problem was really tricky to implement.
// First of all, we should sort the segments by the left endpoint. Here, you can use pair from C++.
// Sorting pair sorts it by the first element.
// Then, iterate through the intervals from left to right.
// Keep track of the leftmost index that hasn't been covered. Initially it is minUncovered=0
// Now, for each interval that covers minUncovered, we want to choose the one that has largest R[i]. (Greedy choice).
// If the current interval can't cover it, the remaining intervals can't cover it since the intervals are sorted by the left endpoint.
// Therefore, update minUncovered to the longest R[i] of the interval covering minUncovered.

pair<int,int> segments[100100];
int main()
{
    ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    int T;
    cin >> T;
    rep(hello,T){ // # using macro here. It is same as for(hello i = 0; i <= T; i++)
        if(hello != 0) cout <<endl;
        clr(segments); // # using macro here. Just resets the elements of segments.
        int M;
        cin >> M;
        int N = 0;
        while(true){
            int a,b;
            cin >> a >> b;
            if(a == 0 && b == 0) break;
            N++;
            segments[N-1] = mp(a,b); // # make_pair(a,b)
        }
        if(N == 0){
            cout << 0 << endl;
            continue;
        }
        sort(segments,segments+N);
        int minUncovered = 0;
        int curmax = -1; // Largest of the R[i]s of the L[i] <= minUncovered
        int curmaxIndex = -1; // Index i of the largest (L[i],R[i]) above.
        vector<int> ans; // indices of the intervals for the solution
        int done = 0; // indicates whether we've found the solution.
        rep(i,N){
            int li = segments[i].first;
            int ri = segments[i].second;
            if(li <= minUncovered){ // if the i-th interval covers unCovered
                if(ri > curmax){ // keep track of the largest R[i] of those intervals
                    curmax = ri;
                    curmaxIndex = i;
                }
            }else{
                // Otherwise, there's no other interval to cover minUncovered from now on.
                if(curmax == -1 || curmax < minUncovered){ // No interval covering, or this interval is not long enough.
                    // No solution.
                    break;
                }else{
                    // Now, choose the curmaxIndex-th interval to cover minUncovered
                    ans.pb(curmaxIndex);
                    minUncovered = curmax;
                    curmax = -1;
                    curmaxIndex = -1;
                    i--; // Check this interval again to see if it covers the updated minUncovered.
                }
            }
            if(curmax >= M || minUncovered >= M){
                ans.pb(curmaxIndex);
                done = 1;
                break;
            }
        }
        if(done){
            cout << sz(ans) << endl;
            rep(i,sz(ans)){
                int ind = ans[i];
                cout << segments[ind].first << " " << segments[ind].second << endl;
            }
        }else{
            cout << 0 << endl;
        }
    }
}
