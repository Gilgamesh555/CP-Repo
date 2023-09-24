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
    int k,n;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> pos;

    for (int  i = 0; i < n; i++) {
        if (s[i] == 'B') {
            pos.push_back(i);
        }
    }

    int p = -1;
    int ans = 0;
    for (int i = 0; i < pos.size(); i++) {
        if (p < pos[i]) {
            p = pos[i] + k - 1;
            ans++;
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