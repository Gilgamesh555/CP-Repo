#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
int v[102], n;
 
void init ()
{
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
}

void propagate(int bl, int br)
{
    int xorsum = 0;

    for (int i = bl; i < br; i++) {
        xorsum = xorsum ^ v[i];
    }

    // cout<<"xorsum -> "<<xorsum<<endl;

    for (int i = bl; i < br; i++) { 
        v[i] = xorsum;
    }
}

bool checkValues() {
    for (int i = 0; i < n; i++) {
        if (v[i] != 0) {
            // cout<<"v[i] -> "<<v[i]<<endl;
            return false;
        }
    }

    return true;
}
 
void solve()
{
    init();

    int cnt = 0;

    if (!checkValues()){
        cnt++;
        propagate(0, n);
    }

    if (!checkValues()) {
        cnt++;
        if (n % 2 == 0) {
            propagate(0, n);
        } else {
            cnt += 2;
            propagate(0, n - 1);
            propagate(n - 2, n);
            propagate(n - 2, n);
        }
    }

    cout<<cnt<<endl;
    if (cnt >= 1) {
        cout<<1<<' '<<n<<endl;

        if (cnt == 2) {
            cout<<1<<' '<<n<<endl;
        }

        if (cnt >= 3) {
            cout<<1<<' '<<n - 1<<endl;
            cout<<n - 1<<' '<<n<<endl;
            cout<<n - 1<<' '<<n<<endl;
        }
    }

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