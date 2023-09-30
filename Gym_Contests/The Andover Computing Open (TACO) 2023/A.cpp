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
 
void solve()
{
    string s;
    string ans = "";

    cin>>s;

    int cntZero = 0;
    int cntOne = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            cntZero++;
        } else {
            if (cntZero) {
                cntZero--;
            } else {
                ans += '1';
            }
        }
    }

    for (int i = 0; i < cntZero; i++) {
        ans += '0';
    }

    cout<<ans.size()<<endl;
    cout<<ans<<endl;

    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    // freopen("output.txt", "w", stdout);

    solve();

    // int t;
    // cin>>t;
    // while (t--) {
    //     solve();
    // }
    
    return 0;
}