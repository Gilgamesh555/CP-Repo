#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;

// __builtin_popcount -> counts the number of 1's in a posit number
// __lg -> returns the most largest bit 1's in a number
 
const int MaxBound = 1e5 * 1 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
void solve()
{
    int n,m;
    cin>>n>>m;
    int a[n + 2];

    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }

    for (int i = 0; i < m ; i++) {
        string s1,s2;
        cin>>s1>>s2;
        s1 = s1.substr(1);
        s2 = s2.substr(1);
        int ss1 = stoi(s1), ss2 = stoi(s2);

        for (int i = 1; i <= n; i++) {
            if (ss1 == a[i]) {
                ss1 = i;
                break;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (ss2 == a[i]) {
                ss2 = i;
                break;
            }
        }

        if (ss1 > ss2) {
            int aux = a[ss2];
            for (int i = ss2; i < ss1; i++) {
                a[ss2] = a[ss2 + 1];
            }
            a[ss1] = aux;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout<<"T"<<a[i]<<' ';
    }
    cout<<endl;
    
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
    solve();
    
    return 0;
}