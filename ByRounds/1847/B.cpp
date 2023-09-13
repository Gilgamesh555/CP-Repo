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
int a[MaxBound];

void init()
{
    cin>>n;
    for (int i = 0; i < n; i++)cin>>a[i];
}

void solve()
{
    init();
    int ansBit = a[0];
    for (int i = 1; i < n; i++) {
        ansBit = (ansBit & a[i]);
    }

    if (ansBit > 0) {
        cout<<1<<endl;
        return;
    }

    int ans = 0;
    ansBit = a[0];
    for (int i = 1; i < n; i++) {
        if (ansBit == 0) {
            ansBit = 0;
            ans++;
        }
        ansBit = (ansBit & a[i]);
    }

    if (ans == 0) {
        cout<<1<<endl;
    } else {
        cout<<ans<<endl;
    }
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