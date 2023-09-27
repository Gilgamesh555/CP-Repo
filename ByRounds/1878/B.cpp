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

    int ans[n];

    ans[0] = 2;
    ans[1] = 3;

    int cnt = 4;

    for (int i = 2; i < n; i++) {
        while (cnt * 3 % (ans[i -1] + ans[i - 2]) == 0) {
            ++cnt;
        }

        ans[i] = cnt; 
        cnt++;   
    }    

    for (int i = 0; i < n; i++) {
        cout<<ans[i]<<' ';
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