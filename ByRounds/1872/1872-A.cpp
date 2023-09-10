#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
int a,b,c;

void init() 
{
    cin>>a>>b>>c;
}
 
void solve()
{
    init();
    int difference = abs(a - b);
    int hasResid = difference % 2 != 0;

    difference = (difference / 2) + hasResid;
    //cout<<"difference =>"<<difference<<endl;
    cout<<(difference / c) + (difference % c != 0)<<endl;

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