#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
#define MODT 998244353
using namespace std;
typedef long long int ll;

// __builtin_popcount -> counts the number of 1's in a posit number
// __lg -> returns the most largest bit 1's in a number

const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";

ll prec[MaxBound], preccomb[MaxBound];

void precal() {
    prec[1] = 1;
    for (ll i = 2; i < MaxBound; i++) {
        prec[i] = (prec[i - 1] * i + MODT) % MODT;
    }
}

void precalComb() {
    preccomb[1] = 1;
    for (ll i = 2; i < MaxBound; i++) {
        preccomb[i] = i;
    }
}
 
void solve()
{
    string s;
    cin>>s;

    int n = s.size();
    vector<ll> pp;

    ll cnt = 1;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) {
            cnt++;
        } else {
            pp.push_back(cnt);
            cnt = 1;
        }
    }

    pp.push_back(cnt);

    ll ans = 1;
    ll anst = 0;
    for (int i = 0; i < pp.size(); i++) {

        ans = (ans * preccomb[pp[i]] + MODT) % MODT;
        anst += pp[i] - 1;
    }

    ans = (ans * prec[anst] + MODT) % MODT;

    if (ans <= 0) {
        ans = 1;
    }

    cout<<anst<<' '<<ans<<endl;

    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
    precal();
    precalComb();

    int t;
    cin>>t;
    while (t--) {
        solve();
    }
    
    return 0;
}