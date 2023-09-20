#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
// __builtin_popcount -> counts the number of 1's in a posit number
// __lg -> returns the most largest bit 1's in a number
void solve()
{
    int m;
    string s1,s2,s3;
    cin>>m>>s1>>s2>>s3;

    int ans = 2002;

    for (int i = 0; i <= 9; i++) {
        int f = 2002, s = 2002, t = 2002, cnt = 1;
        for (int ii = 0; ii < m; ii++) {
            if (s1[ii] - '0' == i) {
                f = ii;
                for (int jj = 0; jj < m; jj++) {
                    if (s2[jj] - '0' == i) {
                        s = ii == jj ? m * cnt + jj : jj;
                        if (ii == jj) {
                            cnt++;
                        }
                        for (int kk = 0; kk < m; kk++) {
                            if (s3[kk] - '0' == i) {
                                t = kk == ii || kk == jj ? m * cnt + kk : kk;
                                // cout<<i<<' '<<ii<<' '<<jj<<' '<<kk<<' '<<f<<' '<<s<<' '<<t<<endl;
                                ans = min(ans, max(f, max(s, t)));
                            }
                            t = 2002;
                        }
                    }
                    cnt = 1;
                    s = 2002;
                }
            }
            f = 2002;
        }
    }

    if (ans == 2002) {
        cout<<-1<<endl;
        return;
    }

    cout<<ans<<endl;
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
    solve();
    
    return 0;
}