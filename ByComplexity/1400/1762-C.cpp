#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
int n;
char v[MaxBound];
long long int prec[MaxBound];

void init() 
{
    cin>>n;

    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
}

void precalculate()
{
    long long int TEMPMOD = 998244353;

    prec[1] = 1;
    for (int i = 2; i < MaxBound; i++) {
        prec[i] = (2ll * prec[i - 1]) % TEMPMOD;
    }
}

 
void solve()
{
    init();

    long long int countRepetitive = 1;
    long long int ans = 1;
    long long int TEMPMOD = 998244353;

    for (long long int i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) {
            countRepetitive++;
            ans = (ans + prec[countRepetitive]) % TEMPMOD;
        } else {
            countRepetitive = 1;
            ans = (ans + 1ll) % TEMPMOD;
        }
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
    precalculate();
    while (t--) {
        solve();
    }
    
    return 0;
} 