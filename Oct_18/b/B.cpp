
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

vector<int> nums;
int ind = 0;

void traverse(int min_num, int max_num){
    if(ind == sz(nums)) return;
    if(nums[ind] <= min_num || nums[ind] >= max_num) return;
    int n =nums[ind];
    ind++;
    traverse(min_num, min(max_num,n));
//    cout << "for number n = " << n << " and index = " << ind << " Finished traversing left, ind = " << ind << endl;
    traverse(max(min_num,n), max_num);
 //   cout << "for number n = " << n << " and index = " << ind << " Finished traversing right, ind = " << ind << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    int b;
    int T = 0;
    while(cin >> b){
        T++;
        nums.clear();
        ind = 0;
        nums.pb(b);
        int a;
        while(cin >> a){
            if(a < 0) break;
            else nums.pb(a);
        }
        traverse(-INF,INF);
        if(ind == sz(nums)){
            cout << "Case " << T << ": yes" << endl;
        }else{
            cout << "Case " << T << ": no" << endl;
        }
    }
}
