#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;

const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";

int r,c;
int menu[101][101];
pair<bool, pair<int, int>> visited[10007];


int getMeals(int xx, int yy) {
    priority_queue<int,vector<int>,greater<int>> numbers;
    
    for (int i = 1; i <= r * c; i++) {
        visited[i].first = 0;
    }

    int ans = 1;
    int maxN = menu[xx][yy];

    numbers.push(menu[xx][yy]);

    while (!numbers.empty()) {
        int number = numbers.top();
        int x = visited[number].second.first;
        int y = visited[number].second.second;

        if (numbers.top() > maxN) {
            ans++;
            maxN = numbers.top();
        }

        if (numbers.top() < maxN) {
            numbers.pop();
            continue;
        }

        numbers.pop();
        
        if (x + 1 < r && !visited[menu[x + 1][y]].first) {
            visited[menu[x + 1][y]].first = 1;
            numbers.push(menu[x + 1][y]);
        }
        if (x - 1 >= 0 && !visited[menu[x - 1][y]].first) {
            visited[menu[x - 1][y]].first = 1;
            numbers.push(menu[x - 1][y]);
        }
        if (y + 1 < c && !visited[menu[x][y + 1]].first) {
            visited[menu[x][y + 1]].first = 1;
            numbers.push(menu[x][y + 1]);
        }
        if (y - 1 >= 0 && !visited[menu[x][y - 1]].first) {
            visited[menu[x][y - 1]].first = 1;
            numbers.push(menu[x][y - 1]);
        }    
    }

    //cout<<menu[xx][yy]<<'-'<<ans<<'-'<<maxN<<endl;

    return ans;
}

void init()
{
    cin>>r>>c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin>>menu[i][j];
            visited[menu[i][j]] = make_pair(0, make_pair(i, j));
        }
    }
}

void solve()
{
    init();

    int ans = 0;

    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            int tempAns = getMeals(x, y);
            //cout<<x<<' '<<y<<endl;
            ans = max(ans, tempAns);
        }
    }

    cout<<ans<<endl;
}

int main()
{
    solve();
    
    return 0;
}