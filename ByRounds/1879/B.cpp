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
    int n;
    cin>>n;
    int a[n],b[n];
 
    int minX = 1000000009;
    int minY = 1000000009;
 
    for (int i = 0; i <n ; i++) {
        cin>>a[i];
        minX=min(a[i], minX);
    }
 
    for (int i = 0; i <n ; i++) {
        cin>>b[i];
        minY=min(b[i], minY);
    }
 
    ll ansa = 0;
    for (int i = 0; i <n ; i++) {
        ansa += b[i] + minX;
    }
 
    ll ansb = 0;
    for (int i = 0; i < n ; i++) {
        ansb += a[i] + minY;
    }
 
    cout<<min(ansa, ansb)<<endl;
 
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