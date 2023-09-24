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
    int n;
    ll x;
    cin>>n>>x;
    ll a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
 
    sort(a, a + n);
 
    b[0] = a[0];
    for (int i = 1; i < n; i++) {
        b[i] = a[i];
        a[i] += a[i - 1];
    }
 
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ll aux = x - (((i + 1) * b[i]) - a[i]);
        // cout<<aux<<' '<<i<<' '<<b[i]<<endl;
        if (aux >= 0) {
            ans = b[i] + (aux / (i + 1));
            break;
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