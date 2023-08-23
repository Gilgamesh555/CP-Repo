#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;

const int MaxBound = 1e5 * 2 + 2;
const int Bound1e5 = 1e5 + 2;
const int iinf = 1e9 + 7;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";

int n;
int a[Bound1e5];

void init()
{
    cin>>n;
    for (int i = 0; i < n; i++)cin>>a[i];
}

void solve()
{
    init();

    map<int, int> m;
    int stillOpen = 0;
    int ans = 0;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            if (m[a[i]] == 1) {
                m[a[i]]--;
                stillOpen--;

                if (stillOpen == 0) {
                    ans++;
                    q.push(i + 1);
                }
                
            }else {
                cout<<-1<<endl;
                return;
            }
        } else {
            if (m[a[i]] > 0) {
                cout<<-1<<endl;
                return;
            }
            m[a[i]]++;
            stillOpen++;
        }
    }

    if (ans > 0 && stillOpen == 0) {
        cout<<ans<<endl;

        int prev = 0;
        while(!q.empty()) {
            int curr = q.front();

            cout<<curr - prev<<" ";

            prev = curr;
            q.pop();
        }
        cout<<endl;
    } else {
        cout<<-1<<endl;
    }
}

int main()
{
    // int t;
    // cin>>t;

    // while (t--) {
    //     solve();
    // }

    solve();
    
    return 0;
}