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
    int n,k;
    cin>>n;
    int c[n],sol[n],rem[n];
    for (int i = 0; i < n; i++) {
        cin>>c[i];
    }
    cin>>k;

    for (int i = n - 2; i>=0; i--) {
        c[i] = c[i + 1] <= c[i] ? c[i + 1] : c[i];
    }

    sol[0] = k / c[0];
    rem[0] = k % c[0];

    for (int i = 1; i < n; i++) {
        int tot = sol[i - 1];
        int remS = 0;

        if (c[i] - c[i - 1] > 0) {
            tot = min(sol[i - 1], rem[i - 1] / (c[i] - c[i - 1]));
            remS = (c[i] - c[i - 1]) * tot;
        }

        sol[i] = tot;
        sol[i - 1] = sol[i - 1] - sol[i];
        rem[i] = rem[i - 1] - remS;
    }

    int ans = 0;
    int vv[n];
    for (int i = n - 1; i >= 0; i--) { 
        ans = ans + sol[i];
        vv[i] = ans;
    }

    for (int i = 0; i < n; i++) { 
        cout<<vv[i]<<' ';
    }
    cout<<endl;

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