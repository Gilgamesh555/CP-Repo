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
    string s;
    cin>>s;
    vector<int> bs;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') {
            bs.push_back(i);
        }
    }

    int ansRight = 0, ansLeft = 0, ans = 0;
    int minX = 1000000009;
    for (int i = 0; i < bs.size(); i++) {
        int leftPos = bs[i] - 1;
        int leftcnt = bs[i] - (i - 1 >= 0 ? bs[i - 1] + 1 : 0);

        int rightPos = bs[i] + 1;
        int rightcnt = (i + 1 < bs.size() ? bs[i + 1] - 1 : s.size() - 1) - bs[i];

        if (i != 0) {
            ans += rightcnt;
        } else {
            ans += leftcnt;
            ans += rightcnt;
        }

        // cout<<ans<<endl;

        minX = min(minX, min(leftcnt, rightcnt));
    }

    if (minX == 1000000009) {
        minX = 0;
    }
    
    cout<<(ans - minX)<<endl;

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