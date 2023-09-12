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

int n;
ll v[MaxBound], sum, bits[33];

ll getFirstOneBit(ll x){
    return x & (-x);
}

void init()
{
    cin>>n;

    sum = 0;

    for (int i = 0; i < n; i++) {
        cin>>v[i];
        sum += v[i];
    }

    for (int i = 0; i <= 32; i++) {
        bits[i] = 0;
    }
}
 
void solve()
{
    init();

    ll avg = sum / n;

    if (sum % n) {
        cout<<"NO\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        ll diff = abs(v[i] - avg);
        ll fb = getFirstOneBit(diff);
        ll sb = fb + diff;

        if (diff == 0) continue;

        if (__builtin_popcount(sb)) {
            // cout<<"MM ->"<<diff<<' '<<sb<<' '<<fb<<endl;
            if (v[i] > avg) {
                bits[__lg(sb)]++;
                bits[__lg(fb)]--;
            } else {
                bits[__lg(sb)]--;
                bits[__lg(fb)]++;
            }
        } else {
            cout<<"NO\n";
            // cout<<i<<' '<<sb<<' '<<fb<<endl;
            return;
        }
    }

    for (int i = 0; i <= 32; i++) {
        if (bits[i]) {
            cout<<"NO\n";
            // cout<<i<<' '<<bits[i]<<endl;
            return;
        }
    }

    cout<<"YES\n";

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