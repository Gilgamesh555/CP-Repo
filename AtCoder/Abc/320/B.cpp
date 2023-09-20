#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
// __builtin_popcount -> counts the number of 1's in a posit number
// __lg -> returns the most largest bit 1's in a number
void fillValues(int v[], string s) {
    for (int i = 0; i < 11; i++) {
        v[i] = -1;
    }

    for (int i = 0; i < s.length(); i++) {
        v[s[i] - '0'] = i;
    }
}

void solve()
{
    int m;
    string s1,s2,s3;
    int v1[11], v2[11], v3[11];
    cin>>s1>>s2>>s3;

    fillValues(v1, s1);
    fillValues(v2, s2);
    fillValues(v3, s3);

    for (int i = 0; i <= 9; i++) {
        cout<<v2[i]<<' ';
    }
    cout<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
    solve();
    
    return 0;
}