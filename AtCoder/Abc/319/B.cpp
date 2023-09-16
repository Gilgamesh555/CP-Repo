#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
// __builtin_popcount -> counts the number of 1's in a posit number
// __lg -> returns the most largest bit 1's in a number
 
void solve()
{
    int n;
    cin>>n;

    for (int i = 0; i <= n; i++) {
        bool thereIsSolution = false;
        for (int j = 1; j <= 9; j++) {
            if (n%j == 0 && i % (n / j) == 0) {
                thereIsSolution = true;
                cout<<j;
                break;
            }
        }
        if (!thereIsSolution) {
            cout<<'-';
        }
    }
    cout<<endl;
    
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
    solve();
    
    return 0;
}