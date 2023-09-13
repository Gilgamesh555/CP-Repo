#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;

const int MaxBound = 1e5 * 2 + 2;
const int Bound1e5 = 1e5 + 2;
const int iinf = 1e9 + 7;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";

int n, k;
int a[101];

void init()
{
    cin>>n>>k;
    for (int i = 0; i < n; i++)cin>>a[i];
}

void solve()
{
    init();

    for (int i = 0; i < n - 1; i++) {
        a[i] = abs(a[i] - a[i + 1]);
    }

    sort(a, a + n - 1, [](int x, int y) -> bool {
        return x > y;
    });

    int ans = 0;
    for (int i = k - 1; i < n - 1; i++) {
        ans += a[i];
    }

    

    cout<<ans<<endl;
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