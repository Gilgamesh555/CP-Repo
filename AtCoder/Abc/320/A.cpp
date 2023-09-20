#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
// __builtin_popcount -> counts the number of 1's in a posit number
// __lg -> returns the most largest bit 1's in a number
int getPower(int x, int y, int result) {
    if (y == 0) {
        return result;
    }
    return getPower(x, --y, result * x);
} 


void solve()
{
    int a,b;
    cin>>a>>b;

    cout<<getPower(a, b, 1) + getPower(b, a, 1)<<endl;
    
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
    solve();
    
    return 0;
}