#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
#define MODT 998244353
using namespace std;
typedef long long int ll;

// __builtin_popcount -> counts the number of 1's in a posit number
// __lg -> returns the most largest bit 1's in a number

const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
void solve()
{
    int n;
    cin>>n;

    ll a[n],pref[n];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        if (i % 2 == 0) {
            ans += max(0ll,a[i]);
        }
    }

    pref[0] = 0;
    for (int i = 1; i < n; i++) {
        if (i % 2) {
            pref[i] = pref[i - 1] + max(0ll, a[i]);
        } else {
            pref[i] = pref[i - 1];
        }
    }

    ll cnt = ans;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            // cout<<i<<' '<<ans + (a[i] < 0 ? a[i] : 0) + (pref[n - 1] - pref[i])<<endl;
            ans = max(ans, cnt + (a[i] < 0 ? a[i] : 0) + (pref[n - 1] - pref[i]));
        } else {
            // cout<<i<<' '<<ans + (pref[n - 1] - pref[i])<<endl;
            ans = max(ans, cnt + (pref[n - 1] - pref[i]));
        }
    }

    cout<<ans<<endl;

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