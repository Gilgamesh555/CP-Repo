#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
// __builtin_popcount -> counts the number of 1's in a posit number
// __lg -> returns the most largest bit 1's in a number
 
void solve()
{
    map<string, int> players;

    players["tourist"] = 3858;
    players["ksun48"] = 3679;
    players["Benq"] = 3658;
    players["Um_nik"] = 3648;
    players["apiad"] = 3638;
    players["Stonefeang"] = 3630;
    players["ecnerwala"] = 3613;
    players["mnbvmar"] = 3555;
    players["newbiedmy"] = 3516;
    players["semiexp"] = 3481;

    string s;

    cin>>s;

    cout<<players[s]<<endl;
    
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
    solve();
    
    return 0;
}