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
    int n;
    cin>>n;
 
    int s[n], c[n];
 
    for (int i = 0; i < n; i++) {
        cin>>s[i]>>c[i];
    }
 
    int ps = s[0];
    int pc = c[0];
 
    for (int i = 1; i < n; i++) {
        if (s[i] >= ps && c[i] >= pc) {
            cout<<-1<<endl;
            return;
        }
    }
 
    cout<<ps<<endl;
 
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