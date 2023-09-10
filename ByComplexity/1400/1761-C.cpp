#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
int n;
char v[102][102];

void init() 
{
    cin>>n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>v[i][j];
        }
    }
}
 
void solve()
{
    init();
    vector<int> vec[n];

    for (int i = 0; i < n; i++) {
        vec[i] = vector<int>();
        vec[i].push_back(i + 1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[j][i] == '1') {
                vec[i].push_back(j + 1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout<<vec[i].size()<<' ';
        for (int j = 0; j < vec[i].size(); j++) {
            cout<<vec[i][j]<<' ';
        }
        cout<<endl;
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