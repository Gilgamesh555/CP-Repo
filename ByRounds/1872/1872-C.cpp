#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;

const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";

ll l,r;

void init() 
{
    cin>>l>>r;
}

void solve()
{
    init();

    ll oril = l;

    while (l % 2ll != 0 || l <= 2ll) {
        l++;
    }

    if (l <= r) {
        cout<<2<<' '<<(l - 2ll)<<endl;
    } else {
        l = oril;
        if (l == r) {
            for (ll i = 2; i <= (ll)sqrt(l); i++){
                if (l % i == 0) {
                    cout<<i<<' '<<(l - i)<<endl;
                    return;
                }
            }
            cout<<-1<<endl;
        } else {
            cout<<-1<<endl;
        }
    }

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