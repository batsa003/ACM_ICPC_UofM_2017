
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

// The problem is asking for number of ways to choose primes (x,y) such that x + y <= N.
// For each prime x <= N, check the precompute the number of primes less than or equal to N-x.
const int MAX_N = 1000100;
int numPrimes[MAX_N]; // numPrimes[i] returns a number of primes <= i.
bool isNotPrime[MAX_N]; // IsNotPrime[i] is false if i is prime, true if it is not prime.
void sieve(){
    // Sieve.
    numPrimes[2] = false;
    for(int i = 2; i * i < MAX_N; i++){
        if(!isNotPrime[i]){
            for(int j = 2; j * i < MAX_N; j++){
                isNotPrime[j*i] = true;
            }
        }
    }
    // Fill numPrimes.
    for(int i = 2; i < MAX_N; i++){
        numPrimes[i] = numPrimes[i-1];
        if(!isNotPrime[i]) numPrimes[i]++;
    }
}
int main()
{
	ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
    sieve();
    int testcase = 0;
    while(true){
        testcase++;
        int N;
        cin >> N;
        if(N == 0) break;
        ll count = 0;
        for(int i = 2; i <= N; i++){
            if(!isNotPrime[i]){
                count += numPrimes[N-i];
                // (among number of primes less than or equal to N-i, i itself is included. So, subtract it.
                if(i <= N/2) count -= 1;
            }
        }
        // (i,j) and (j,i) is counted twice.
        count /= 2;
        cout << "Case " << testcase << ": " << count << endl;
    }
}
