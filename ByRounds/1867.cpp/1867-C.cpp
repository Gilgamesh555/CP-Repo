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

int n;
int a[MaxBound], visited[MaxBound];
int maxN;

void init()
{
    cin>>n;
    for (int i = 0; i < MaxBound; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        if (a[i] < MaxBound) {
            visited[a[i]] = 1;
        }
    }
}
 
void solve()
{
    init();

    int answer = 0;
    for (int i = 0; i < MaxBound; i++) {
        if (!visited[i]) {
            answer = i;
            break;
        }
    }
    
    while (answer != -1) {
        int response;
        cout<<answer<<endl;
        cin>>response;

        answer = response;

        if (answer == -1) {
            return;
        }

        if (answer == -2) {
            cout<<"SOMETHINGS WRONG\n";
            return;
        }
    }

    cout.flush();
    
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
    
    return 0;
}