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

int by_se(int pref[][33], int bb,int lb, int rb, int k)
{
    if (lb > rb) {
        return 0ll;
    }

    int mid = (lb + rb) / 2;

    ll val = 0;

    for(int j = 0; j < 33; j++) {
        if (pref[mid][j] - pref[bb - 1][j] >= mid - bb + 1) {
            val += (1 << j);
        }
    }

    // cout<<lb<<' '<<rb<<' '<<' '<<bb<<' '<<mid<<' '<<val<<endl;

    if (val >= k) {
        return max(mid, by_se(pref, bb, mid + 1, rb, k));
    }

    return by_se(pref, bb, lb, mid - 1, k);
}
 
void solve()
{
    int n;
    cin>>n;

    int pref[n + 2][33];
    int a[n + 2];

    for (int i = 0; i < 33; i++) {
        pref[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        int aux = a[i];

        for (int j = 0; j < 33; j++) { 
            pref[i][j] = pref[i-1][j] + (aux & 1);
            aux = aux >> 1;
        }
    }

    int q;
    cin>>q;
    int l,k;

    while(q--) {
        cin>>l>>k;

        int ans = by_se(pref, l, l, n, k);
        
        if (ans == 0) {
            cout<<-1<<' ';
        } else {
            cout<<ans<<' ';
        }
    }
    cout<<endl;

    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    // freopen("output.txt", "w", stdout);

    int t;
    cin>>t;
    while (t--) {
        solve();
    }
    
    return 0;
}