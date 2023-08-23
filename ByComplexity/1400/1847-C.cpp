
#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
int n, a[MaxBound];
bool numbersRepeat[258];
 
void init()
{
    cin>>n;

    for (int i = 0; i < n ;i++) {
        cin>>a[i];
    }

    for (int i = 0; i < 258 ;i++) {
        numbersRepeat[i] = 0;
    }
}
 
void solve()
{
    init();
    
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 256; j++) {
            if (numbersRepeat[j]) {
                numbersRepeat[a[i] ^ j] = true;
            }
        }
    }

    for (int i = 256; i >= 0; i++) {
        if (numbersRepeat[i]) {
            cout<<numbersRepeat[i]<<endl;
            return;
        }
    }

    cout<<0<<endl;
    return;
}
 
int main()
{
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
    
    return 0;
}