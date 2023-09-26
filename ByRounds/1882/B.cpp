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
 
    vector< vector<int> > v;
 
    for (int i = 0; i < n; i++) {
        int l;
        cin>>l;
        vector<int> aux (l);
        for (int j = 0; j < l; j++) {
            int x;
            cin>>x;
            aux.push_back(x);
        }
        v.push_back(aux);
    }
 
    int ans = 0;
    for (int i = 1; i <= 50; i++) {
        int numbers[52];
        for (int j = 0; j < 52; j++) {
            numbers[j] = 0;
        }
 
        bool appT = false;
        for (auto vv : v) {
            bool appears = false;
            for (auto number : vv) {
                if (number == i) {
                    appears = true;
                    appT = true;
                    break;
                }
            }
 
            if (appears) {
                continue;
            }
 
            for (auto number : vv) {
                numbers[number] = 1;
            }
        }
 
        int cnt = 0;
        for (int i = 1; i <= 50; i++) {
            cnt += numbers[i];
        }
 
        if (!appT) {
            cnt = 0;
        }
 
        // cout<<i<<' '<<cnt<<endl;
 
        ans = max(ans, cnt);
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