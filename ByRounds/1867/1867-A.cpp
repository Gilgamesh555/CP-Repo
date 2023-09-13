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

int n;
pair<int, int> a[50005];

void init()
{
    cin>>n;

    for (int i = 0; i < n; i++) {
        cin>>a[i].first;
        a[i].second = i;
    }

    sort(a, a + n);
}
 
void solve()
{
    init();

    int b[n + 1];

    for (int i = 0, aux = n; i < n; i++, aux--) {
        b[a[i].second] = aux;
    }

    for (int i = 0; i < n; i++) {
        cout<<b[i]<<' ';
    }

    cout<<endl;

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