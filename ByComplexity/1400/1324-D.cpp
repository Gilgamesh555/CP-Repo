#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;

const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";

int n;
int a[MaxBound], b[MaxBound], c[MaxBound];

void init()
{
    cin>>n;

    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    for (int i = 0; i < n; i++) {
        cin>>b[i];

        c[i] = a[i] - b[i];
    }
}

void solve()
{
    sort(c, c + n);

    ll ans = 0;

    for (int i = 0, j = n - 1; i < n; i++) {
        while (j > 0 && c[i] + c[j] > 0) {
            j--;
        }

        if (j <= i) {
            ans += (n - i - 1);
        } else {
            ans += (j - i);
        }
    }

    cout<<ans<<endl;
}

int main()
{
    solve();
    
    
    return 0;
}