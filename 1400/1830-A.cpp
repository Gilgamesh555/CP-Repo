
#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
int n, visited[MaxBound];
queue< pair<int,int> > points;
 
void init()
{
    cin>>n;
    points = queue<pair<int,int>>();
    for (int i = 0; i < n - 1; i++) {
        int x,y;
        cin>>x>>y;
        points.push(make_pair(x, y));
    }
    for (int i = 0; i < n; i++) {
        visited[i + 1] = 0;
    }
}
 
void solve()
{
    init();

    visited[1] = 1;
    int sol = 1;
    queue< pair<int,int> > tempPoints;

    while(!points.empty()) {
        int x = points.front().first, y = points.front().second;
        //cout<<x<<' '<<y<<endl;
        if (visited[x] || visited[y]) {
            visited[x] = visited[y] = 1;
        } else {
            tempPoints.push(make_pair(x, y));
        }

        points.pop();

        if (points.empty()) {
            if (tempPoints.empty()) {
                continue;
            }
            points = tempPoints;
            tempPoints = queue<pair<int,int>>();
            sol++;
        }
    }

    cout<<sol<<endl;
    
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