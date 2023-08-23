#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;

const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";

int x;

void init()
{
    cin>>x;
}

void solve()
{
    init();

    int ans = x % 11;

    if (ans * 111 <= x) {
        cout<<"YES\n";
        return;
    }

    cout<<"NO\n";
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