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
    int n,k;
    cin>>n>>k;
    int a[n];
    vector<pair<int,int> > bounds(k + 2, make_pair(-1 , -1));

    for (int i = 0; i < n; i++) {
        cin>>a[i];
        if (bounds[a[i]].first == -1) {
            bounds[a[i]].first = i;
        }
        bounds[a[i]].second = i;
    }

    for (int i = 1, lb = 0, rb = n - 1; i <= k; i++) {
        if (bounds[i].first == -1) {
            cout<<0<<' ';
            continue;
        }

        while (a[lb] < i && bounds[i].first > lb) {
            lb++;
        }

        while (a[rb] < i && bounds[i].second < rb) {
            rb--;
        }

        int anslb = min(lb, bounds[i].first);
        int ansrb = max(rb, bounds[i].second);

        if (lb > rb) {
            cout<<0<<' ';
            continue;
        }

        int d = rb - lb + 1;
        cout<<(d+d)<<' ';
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