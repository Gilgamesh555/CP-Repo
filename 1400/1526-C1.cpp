#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
int n, a[2009], sum[2009];
pair<int,int> p[2009];
 
void init()
{
    cin>>n;

    for (int i = 0; i < n ;i++) {
        cin>>a[i];
        p[i] = make_pair(a[i], i);
    }
}
 
void solve()
{
    sort(p, p + n, [](auto x, auto y) -> bool {
        return x.first < x.second;
    });

    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = a[i] > 0 ? sum[i - 1] + a[i] : sum[i - 1];
    }

    int debt = 0;
    for (int i = 0; i < n; i++) {
        int lessValue = a[p[i].second];

        if (i > 0) {

        } else {
            
        }
    }

    return;
}
 
int main()
{
    // int t;
    // cin>>t;
    // while (t--) {
    //     solve();
    // }

    solve();
    
    return 0;
}