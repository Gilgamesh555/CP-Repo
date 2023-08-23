#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
int a,b;
 
void init()
{
    cin>>a>>b;
}
 
void solve()
{
    init();

    if (a == 1) {
        if (b == 2) {
            cout<<3<<endl;
        } else {
            cout<<2<<endl;
        }
    } else {
        cout<<1<<endl;
    }

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