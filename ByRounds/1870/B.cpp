#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;

// __builtin_popcount -> counts the number of 1's in a posit number
// __lg -> returns the most largest bit 1's in a number
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    for (int i = 0; i < m; i++) {
        cin>>b[i];
    }

    ll sumor = 0;
    for (int i = 0; i < m; i++) {
        sumor = sumor | b[i];
    }

    if (n % 2) {
        
        ll ans = 0;
        ll ansMin = 0;
        for (int i = 0; i < n; i++) {
            ansMin = ansMin ^ a[i];
        }
        for (int i = 0; i < n; i++) {
            a[i] = a[i] | sumor;
            ans = ans ^ a[i];
        }
        cout<<ansMin<<' '<<ans<<endl;
    } else {
        ll ans = 0;
        ll ansMin = 0;
        for (int i = 0; i < n; i++) {
            ans = ans ^ a[i];
        }
        for (int i = 0; i < n; i++) {
            a[i] = a[i] | sumor;
            ansMin = ansMin ^ a[i];
        }
        cout<<ansMin<<' '<<ans<<endl;
    }

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