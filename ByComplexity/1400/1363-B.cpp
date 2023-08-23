#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;

const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";

string s;
int zeros[1003], ones[10003];

void init()
{
    cin>>s;
}

void solve()
{
    init();

    zeros[0] = 0;
    ones[0] = 0;

    for (int i = 0; i < s.size(); i++) {
        zeros[i + 1] = s[i] == '0' ? zeros[i] + 1 : zeros[i];
        ones[i + 1] = s[i] == '1' ? ones[i] + 1 : ones[i];
    }

    int ans = 100000;

    for (int i = 1; i <= s.size(); i++) {
        int minLeft = min(zeros[i] - zeros[0], ones[i] - ones[0]);
        int minRight = min(zeros[s.size()] - zeros[i], ones[s.size()] - ones[i]);

        cout<<minLeft<<' '<<minRight<<endl;

        ans = min(ans, minLeft + minRight);
    }

    cout<<ans<<endl;
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