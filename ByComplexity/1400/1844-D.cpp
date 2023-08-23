#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
long long n, visited[100002];

void generateString(int x) {
    for (int i = 0; i < n; i++) {
        cout<<(char)((i % x) + 'a');
    }

    cout<<endl;

    return;
}
 
void init()
{
    cin>>n;
    for (int i = 0; i < 100002; i++) {
        visited[i] = 0;
    }
}
 
void solve()
{
    init();

    if (n == 1) {
        cout<<'a'<<endl;
        return;
    }

    if (n == 2) {
        cout<<"ab"<<endl;
        return;
    }
    
    for (int i = 2; i <= (int)sqrt(n); i++) {
        if (n % i == 0) {
            if (i <  100002) {
                visited[i] = 1;
            }

            if (i <  100002) {
                visited[n / i] = 1;
            }
        }
    }

    for (int i = 2; i < 100002; i++) {
        if (!visited[i]) {
            generateString(i);
            break;
        }
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