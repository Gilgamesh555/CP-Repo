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

int cycles[100 * 2 + 2], visited[100 * 2 + 2];

int lastVisitedIsTheSame(int parent, int x, vector<vector<int>> edges) {
    if (visited[x]) {
        return cycles[x];
    }

    visited[x] = true;
    // cout<<x<<endl;
    for (auto val : edges[x]) {
        // cout<<val<<' '<<visited[val]<<endl;
        if (!visited[val]) {
            int aux = lastVisitedIsTheSame(parent, val, edges);
            // cout<<x<<" -> "<<aux<<' '<<val<<endl;
            if (aux != -1) {
                cycles[x] = aux + 1;
                return aux + 1;
            } else {
                return -1;
            }
        } else {
            if (val == parent){
                return 1;
            } else {
                return -1;
            }
        }
    }

    return -1;
}
 
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> edges(n * 2 + 2);
    map<string, int> names;

    for (int i = 0; i < 100 * 2 + 2; i++) {
        visited[i] = cycles[i] = 0;
    }

    int cnt = 1;
    for (int i = 0; i < n; i++) {
        
        string name, has, wants;
        cin>>name>>has>>wants;

        if (!names[has]) {
            names[has] = cnt++;
        }

        if (!names[wants]) {
            names[wants] = cnt++;
        }

        edges[names[has]].push_back(names[wants]);
        // cout<<names[has]<<' '<<names[wants]<<endl;
    }

    int ans = -1;

    for (int i = 1; i < cnt; i++) {
        int aux = lastVisitedIsTheSame(i, i, edges);
        // cout<<"RESULT -> "<<aux<<' '<<i<<endl;
        ans = max(ans, aux);

        for (int j = 1; j < cnt; j++) {
            visited[j] = 0;
        }
    }
    
    if (ans == -1) {
        cout<<"No trades possible\n"<<endl;
    } else {
        cout<<ans<<endl;
    }
    
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
    solve();
    
    return 0;
}