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
    int n,k;
    cin>>n>>k;

    int t[k * 2];

    string s;
    cin>>s;

    for (int i = 0; i < k * 2 ; i+=2) {
        cin>>t[i];
    }

    for (int i = 1; i < k * 2 ; i+=2) {
        cin>>t[i];
    }

    int q;
    cin>>q;
    int qr[q];

    for (int i = 0; i < q; i++) {
        cin>>qr[i];
    }

    sort(qr, qr + q);

    int ans[n + 2];

    for (int i = 0; i < n + 2; i++) {
        ans[i] = 0;
    }

    for (int i = 0, j = 0; i < q; i++) {
        while (qr[i] < t[j] || qr[i] > t[j + 1]) {
            j += 2;
        }

        int minX = min(qr[i], t[j] + t[j + 1] - qr[i]);
        int maxX = max(qr[i], t[j] + t[j + 1] - qr[i]);

        // cout<<qr[i]<<' '<<minX<<' '<<maxX<<endl;

        ans[minX]++;
        ans[maxX]++;
    }

    for (int i = 0; i < k * 2 ; i+=2) {
        for (int j = t[i], k = t[i + 1]; j <= k; j++, k--) {
            // cout<<k<<' '<<ans[k]<<endl;
            if (ans[k] % 2) {
                char aux = s[j - 1]; 
                s[j - 1] = s[k - 1];
                s[k - 1] = aux;
            }

            ans[k - 1] += ans[k];
        }
    }

    cout<<s<<endl;

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