#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
int n;
long long v[MaxBound];
 
void init()
{
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
}
 
void solve()
{
    init();
    long long maxSum = 0;
    long long aux = 0;

    for (int i = 0; i < n; i+=2) {
        if (v[i] > 0) {
            aux += v[i];
        }
    }

    maxSum = max(maxSum, aux);

    aux = 0;
    for (int i = 1; i < n; i+=2) {
        if (v[i] > 0) {
            aux += v[i];
        }
    }

    maxSum = max(maxSum, aux);

    if (maxSum == 0) {
        maxSum = v[0];
        for (int i = 1; i < n; i++) {
            maxSum = max(maxSum, v[i]);
        }
    }

    cout<<maxSum<<endl;

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