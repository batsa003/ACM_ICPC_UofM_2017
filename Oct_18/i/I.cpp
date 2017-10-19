
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
set<string> words;
int main()
{
    ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    int T = 0;
    while(cin >> N){
        words.clear();
        T++;
        rep(i,N){
            string s;
            cin >> s;
            sort(s.begin(),s.end());
            rep(j,sz(s)) if(s[j] >= 'a' && s[j] <= 'z') s[j] = 'A' + (s[j] - 'a');
            words.insert(s);
        }
        cin >> M;
        cout << "Case " << T << ":" << endl;
        rep(hello,M){
            string top,bottom;
            cin >> top >> bottom;
            sort(top.begin(),top.end());
            sort(bottom.begin(),bottom.end());
            rep(j,sz(top)) if(top[j] >= 'a' && top[j] <= 'z') top[j] = 'A' + (top[j] - 'a');
            rep(j,sz(bottom)) if(bottom[j] >= 'a' && bottom[j] <= 'z') bottom[j] = 'A' + (bottom[j] - 'a');

            queue<string> Q;
            Q.push(bottom);
            int done = 0;
            while(sz(Q)>0){
                string cur = Q.front();
                Q.pop();
                if(cur == top){
                    cout << "yes" << endl;
                    done = 1;
                    break;
                }
                rep(i,sz(cur)){
                    if(i > 0 && cur[i] == cur[i-1]) continue;
                    // delete i-th letter from cur
                    string v = "";
                    rep(j,i) v += cur[j];
                    for(int j = i+1; j < sz(cur); j++) v += cur[j];
                    if(words.find(v) != words.end()){
//                        cout << "Pushed v = " << v << endl;
                        Q.push(v);
                    }
                }
            }
            if(!done) cout << "no" << endl;
        }
    }
}
