#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
ll n,a,b;
 
void init()
{
    cin>>n>>a>>b;
}
 
void solve()
{
    ll temp = 1;
    
    while(temp <= n) {
        ll aux = n - temp;
        
        if (aux % b == 0) {
            cout<<'Yes\n';
            return;
        }

        temp = temp * a;
    }

    cout<<'No\n';
    return;
}
 
int main()
{
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
    
    return 0;
}