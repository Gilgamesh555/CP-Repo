#include <iostream>
#define MOD 6000000007
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
    ll n,k,x;
    cin>>n>>k>>x;

    if (k > x) {
        cout<<"NO\n";
        return;
    }

    ll p = n - k + 1;
    
    if (p <= 0) {
        cout<<"NO\n";
        return;
    }

    ll aux = (n  * (n + 1) / 2) - (p * (p - 1) / 2);

    if (aux >= x) {
        ll diff = aux - x;

        if (diff <= (p - 1) * k) {
            cout<<"YES\n";
            return;
        }
    }

    cout<<"NO\n";

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