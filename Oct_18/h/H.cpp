
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

// The system is judging incorrectly. Use the h.in, h.judge to check your answer.
int N1,N2;
int R1[20];
int R2[20];

void write(ll p, ll q){
    bool first = 1;
    while(true){
        if(first){
            cout << p/q;
            first = 0;
        }
        else{
            cout << " " << p/q;
        }
        if(p%q == 0) {
            break;
        }else{
            ll r = p%q;
            p = q;
            q = r;
        }
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    int T = 0;
    while(cin >> N1){
        T++;
        cin >> N2;
        clr(R1);
        clr(R2);
        rep(i,N1) cin >> R1[i];
        rep(i,N2) cin >> R2[i];

        ll p1 = 0;
        ll q1 = 1;
        for(int i = N1 - 1; i > 0; i--){
            p1 += q1 * R1[i];
            swap(p1,q1);
            ll g = __gcd(p1,q1);
            p1 /= g;
            q1 /= g;
        }
        p1 += R1[0] * q1;
        ll gcd = __gcd(p1,q1);
        p1 /= gcd;
        q1 /= gcd;

        ll p2 = 0;
        ll q2 = 1;
        for(int i = N2 - 1; i > 0; i--){
            p2 += q2 * R2[i];
            swap(p2,q2);
            ll g = __gcd(p2,q2);
            p2 /= g;
            q2 /= g;
        }
        p2 += R2[0] * q2;
        gcd = __gcd(p2,q2);
        p2 /= gcd;
        q2 /= gcd;
        cout << "Case " << T << ":" << endl;
        write(p1*q2 + p2*q1,q1*q2);
        write(p1*q2 - p2*q1,q1*q2);
        write(p1*p2,q1*q2);
        write(p1*q2,p2*q1);

    }
}
