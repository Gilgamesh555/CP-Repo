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
    int n = 10;
    int a[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1) {
                a[i][j] = 1;
                continue;
            }
            if (i == 1 || i == n - 2) {
                if (j == 0 || j == n - 1) {
                     a[i][j] = 1;
                    continue;
                }
 
                a[i][j] = 2;
                continue;
            }
            if (i == 2 || i == n - 3) {
                if (j == 0 || j == n - 1) {
                     a[i][j] = 1;
                    continue;
                }
 
                if (j == 1 || j == n - 2) {
                     a[i][j] = 2;
                    continue;
                }
 
                a[i][j] = 3;
                continue;
            }
 
            if (i == 3 || i == n - 4) {
                if (j == 0 || j == n - 1) {
                     a[i][j] = 1;
                    continue;
                }
 
                if (j == 1 || j == n - 2) {
                     a[i][j] = 2;
                    continue;
                }
 
                if (j == 2 || j == n - 3) {
                     a[i][j] = 3;
                    continue;
                }
 
                a[i][j] = 4;
                continue;
            }
 
            if (i == 4 || i == n - 5) {
                if (j == 0 || j == n - 1) {
                     a[i][j] = 1;
                    continue;
                }
 
                if (j == 1 || j == n - 2) {
                     a[i][j] = 2;
                    continue;
                }
 
                if (j == 2 || j == n - 3) {
                     a[i][j] = 3;
                    continue;
                }
 
                if (j == 3 || j == n - 4) {
                    a[i][j] = 4;
                    continue;
                }
 
                a[i][j] = 5;
                continue;
            }
        }
    }
 
    int ans = 0;
    for(int i = 0; i < n; i++) {
        string s;
        cin>>s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'X') {
                ans += a[i][j];
            }
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