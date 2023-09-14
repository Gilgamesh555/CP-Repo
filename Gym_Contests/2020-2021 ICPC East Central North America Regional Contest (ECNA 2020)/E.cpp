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

int changeCharacter(char x) {
    if (x >= 'A' && x <= 'Z') {
        return x - 'A';
    }

    if (x >= '0' && x <= '9') {
        return x - '0' + 26;
    }

    return 36;
}

int transforNumber(int x) {
    if (x <= 25) {
        return x + 'A';
    }

    if (x <= 35) {
        return (x - 26) + '0';
    }

    return ' ';
}
 
void solve()
{
    int n;
    
    cin>>n;
    ll m[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>m[i][j];
        }
    }

    string s, phrase = "";
    while (cin>>s) {
        phrase += s + ' ';
    }

    phrase = phrase.substr(0, phrase.size() - 1);

    int length = phrase.size();
    if (phrase.size() % n) {
        length = (phrase.size() / n + 1) * n;
    }

    int a[length + 2], b[length + 2];

    for (int i = phrase.size(); i < length; i++) {
        phrase += changeCharacter(' ');
    }

    for (int i = 0; i < phrase.size(); i++) {
        a[i] = changeCharacter(phrase[i]);
    }

    for (int i = 0; i < length; i+=n) {
        for (int j = 0; j < n; j++) {
            ll sum = 0;
            for (int k = 0; k < n; k++) {
                // cout<<m[j][k]<<' '<<a[i + k]<<endl;
                sum += (m[j][k] * a[i + k]);
            }
            sum = sum % 37;
            b[i + j] = sum;
            // cout<<(i + j)<<' '<<b[i + j]<<endl;
        }
    }

    string ans = "";
    for (int i = 0; i < length; i++) {
        ans += transforNumber(b[i]);
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