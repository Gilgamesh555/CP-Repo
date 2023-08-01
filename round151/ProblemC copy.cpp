#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;

const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";

string s,l,r;
int m;
int numbers[10][2];


void init()
{
    cin>>s>>m>>l>>r;
}

void solve()
{
    init();
    
    int lastOne = -1;

    for (int i = 0; i < m; i++) {
        int ll = l[i] - '0', rr = r[i] - '0';
        int lastDigit = 0;
        for (int j = ll; j <= rr; j++) {
            int last = -1;
            for (int k = lastOne + 1; k < s.length(); k++) {
                if (s[k] - '0' == j) {
                    last = k;
                    break;
                }
            }

            if (last == -1) {
                cout<<"YES\n";
                return;
            }
            
            lastDigit = max(lastDigit, last);
        }
        lastOne = max(lastOne, lastDigit);
    }

    cout<<"NO\n";
}

int main()
{
    int t;
    cin>>t;

    while(t--) 
    {
        solve();
    }
    
    return 0;
}