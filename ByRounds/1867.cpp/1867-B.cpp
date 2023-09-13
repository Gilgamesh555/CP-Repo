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
string s;
 
void init()
{
    cin>>n>>s;
}
 
void solve()
{
    init();
 
    vector<int> v;
    vector<int> ans(n + 10, 0);
 
    if (n == 1) {
        cout<<"11\n";
        return;
    }
 
    int potency = 0, odds = 0;
 
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == s[n - i - 1]) {
            potency++;
        } else {
            odds++;
        }
    }
 
    v.push_back(odds);
 
    if (n % 2) {
        v.push_back(odds + 1);
    }
 
    for (int i = 0; i < v.size(); i++) {
        ans[v[i]] = 1;
        int aux = potency * 2;
        while (aux >= 2) {
            ans[aux + v[i]] = 1;
            aux -= 2; 
        }
    }
 
    for (int i = 0; i <= n; i++) {
        cout<<ans[i];
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