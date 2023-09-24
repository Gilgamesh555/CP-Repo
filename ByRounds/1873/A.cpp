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
    int  n = 3;
 
    char v[n];
    int cnt = 0;
    for (int  i = 0; i < n; i++) {
        cin>>v[i];
        if (v[i] - 'a' != i) {
            cnt++;
        }
    }
 
    if (cnt > 2) {
        cout<<"NO\n";
    } else {
        cout<<"YES\n";
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