#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
int n;
 
void init()
{
    cin>>n;
}
 
void solve()
{
    init();

    if(n == 1) {
        cout<<1<<endl;
        return;
    }

    if (n == 2) {
        cout<<1<<' '<<2<<endl;
        return;
    }

    int ans[n];

    for (int i = 0; i < n; i++) {
        ans[i] = 0;
    }

    ans[n/2] = 1;
    ans[0] = 2;
    ans[n - 1] = 3;
    
    for (int i = 1, cnt = 4; i < n -1; i++) {
        if (ans[i] == 0) {
            ans[i] = cnt;
            cnt++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout<<ans[i]<<' ';
    }
    cout<<endl;

    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t--) {
        solve();
    }
    
    return 0;
} 