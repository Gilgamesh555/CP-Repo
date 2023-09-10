#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;

const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";

ll n,x,y;

void init() 
{
    cin>>n>>x>>y;
}

ll findGCD(long long x, long long y) {
    if (y == 0) return x;
    return findGCD(y, x % y);
}

ll findLCM(ll x, ll y) {
    return (x * y) / findGCD(x, y);
}

ll findSum(ll x, ll y) {
    ll aux1 = x * (x+1ll) / 2ll;
    ll aux2 = y * (y+1ll) / 2ll;

    return aux1 - aux2;
}

void solve()
{
    init();

    ll lcm = findLCM(x, y);
    ll maxPnts = n / x;
    ll minPnts = n / y;
    ll pntsLcm = n / lcm;

    cout<<lcm<<' '<<maxPnts<<' '<<minPnts<<' '<<pntsLcm<<endl;

    maxPnts = maxPnts - pntsLcm;
    minPnts = minPnts - pntsLcm;

    ll maxValues = findSum(n, n - maxPnts);
    ll minValues = findSum(minPnts, 0);

    cout<<maxValues - minValues<<endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t--) {
        solve();
    }
    
    return 0;
}