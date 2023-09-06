#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
pair<int,int> v[100002];
int n, m, vv[100002];

void init() 
{
    cin>>n>>m;
    for (int i = 0; i <= n; i++) {
        vv[i] = n + 1;
    }
    for (int i = 0; i < m; i++) {
        cin>>v[i].first>>v[i].second;
    }
}

 
void solve()
{
    init();

    long long ans = 0;

    for (int i = 0; i < m; i++) {
        int minVal = min(v[i].first, v[i].second);
        int maxVal = max(v[i].first, v[i].second);

        vv[minVal] = min(vv[minVal], maxVal);
    }

    int prevMin = n + 1;
    for (int i = n; i > 0; i--) {
        prevMin = min(prevMin, vv[i]);
        ans += (prevMin - i);
    }

    cout<<ans<<endl;

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