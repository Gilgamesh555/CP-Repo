#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
int n;
pair<int,int> v[102];

void init() 
{
    cin>>n;

    for (int i = 0; i < n; i++) {
        cin>>v[i].first>>v[i].second;
    }
}
 
void solve()
{
    init();

    int minV = 10000;

    for (int i = 0; i < n; i++) {
        minV = min(minV, v[i].first + (v[i].second - 1) / 2);
    }

    cout<<max(minV, 1)<<endl;

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