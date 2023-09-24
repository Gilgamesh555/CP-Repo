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
    cin>>n>>k;
    
    int f[n];
    int a[n];
    vector<vector<int> > v;

    int sans = 0;
    for (int i = 0; i < n; i++) {
        cin>>f[i];
        if (f[i] <= k) {
            sans = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    vector<int> aux;

    for (int i = 0; i < n; i++) {
        aux.push_back(a[i]);
        if (i + 1 >= n) {
            v.push_back(aux);
            continue;
        }
        if (a[i] % a[i + 1] != 0) {
            v.push_back(aux);
            aux = vector<int>();
        }
    }

    int prev = 0;
    for (auto vec : v) {
        int aux = 0;
        int cnt = 0;
        int ans = 0;
        // for (auto y : vec) {
        //     cout<<y<<' ';
        // }
        // cout<<endl;
        for (int  i = 0, j = 0; i < vec.size() && j < vec.size();) {
            aux += f[j + prev];
            if (aux <= k) {
                cnt++;
                j++;
            } else {
                ans = max(ans, cnt);
                aux -= f[i + prev];
                i++;
                j = max(j + 1, i);
            }

            // cout<<aux<<' '<<i<<' '<<j<<' '<<ans<<' '<<cnt<<endl;
        }
        prev += vec.size();
        ans = max(ans, cnt);

        // cout<<ans<<endl;

        sans = max(sans, ans);
    }

    cout<<sans<<endl;

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