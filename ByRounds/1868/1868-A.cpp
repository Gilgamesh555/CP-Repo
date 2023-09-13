#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";

int n, m;
int v[MaxBound];

void init ()
{
    cin>>n>>m;
}

void makeRow(int pos)
{
    for (int i = pos, val = 0; val < m; i++) {
        v[i % m] = val;
        val++;
    }

    for (int i = 0; i < m; i++) {
        cout<<v[i]<<' ';
    }
    cout<<endl;
}
 
void solve()
{
    init();

    if(m == 1) {
        cout<<0<<endl;
    } else {
        cout<<min(n + 1, m)<<endl;
    }

    for (int i = 0; i < n; i++) {
        makeRow(min(i + 1, m - 1));
    }

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