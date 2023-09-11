#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";

pair<ll,ll> v[MaxBound];
int n, k, a, b;
 
void init ()
{
    cin>>n>>k>>a>>b;
    for (int i = 0; i < n; i++) {
        cin>>v[i].first>>v[i].second;
    }
}

ll getPrice(int x, int y) {
    return abs(v[x].first - v[y].first) + abs(v[x].second - v[y].second);
}

ll mininumCost() {
    ll minimFirst = inf, minimSec = inf;

    for (int i = 0; i < k; i++) {
        minimFirst = min(minimFirst, getPrice(a - 1, i));
        minimSec = min(minimSec, getPrice(b - 1, i));
    }

    return minimFirst + minimSec;
}
 
void solve()
{
    init();

    ll cost = getPrice(a - 1, b - 1);

    cost = min(cost, mininumCost());

    cout<<cost<<endl;


    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
    
    return 0;
}