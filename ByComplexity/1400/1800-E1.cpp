#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
int salph[27], talph[27], n, k;
string s, t;
int cnt1,cnt2;
 
void init()
{
    cin>>n>>k;
    cin>>s>>t;

    for (int i = 0; i < 27; i++) {
        salph[i] = talph[i] = 0;
    }
}

bool checkAlphabetsAreTheSame() {
    for (int i = 0; i < 27; i++) {
        if (salph[i] != talph[i]) {
            return false;
        }
    }

    return true;
}

bool checkWordsAreTheSame() {
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            return false;
        }
    }

    return true;
}
 
void solve()
{
    init();

    for (int i = 0; i < n; i++) {
        salph[s[i] - 'a']++;
        talph[t[i] - 'a']++;
    }

    if (checkAlphabetsAreTheSame()) {
        if (n <= 5) {
            if (n <= 3) {
                if (checkWordsAreTheSame()) {
                    cout<<"YES\n";
                    return;
                } else {
                    cout<<"NO\n";
                    return;
                }
            }
            if (n == 4) {
                if (s[1] == t[1] && s[2] == t[2]) {
                    cout<<"YES\n";
                    return;
                } else {
                    cout<<"NO\n";
                    return;
                }
            }
            if (n == 5) {
                if (s[2] == t[2]) {
                    cout<<"YES\n";
                    return;
                } else {
                    cout<<"NO\n";
                    return;
                }
            }
        } else {
            cout<<"YES\n";
        }
    } else {
        cout<<"NO\n";
    }

    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t--) {
        solve();
    }
    
    return 0;
} 