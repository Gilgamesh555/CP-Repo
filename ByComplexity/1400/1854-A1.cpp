#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
int n;
int v[22];
 
void init()
{
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
}

pair<int,int> printDouble(int position) {
    return make_pair(position, position);
}

pair<int,int>  printChange(int posix, int posy) {
    return make_pair(posix, posy);
}
 
void solve()
{
    init();
    int posMax = 0;
    int max = -22;

    for (int i = 0; i < n; i++) {
        if (v[i] > max && v[i] != 0) {
            max = v[i];
            posMax = i;
        }
    }

    queue<pair<int,int>> results;
    bool isPositive = true;

    if (max > 0) {
        while (max < 20) {
            max += max;
            results.push(printDouble(posMax));
        }
    } else {
        if (max == -22) {
            cout<<0<<endl;
            return;
        }
        isPositive = false;
        while (max > -20) {
            max += max;
            results.push(printDouble(posMax));
        }
    }

    if (isPositive) {
        int prevPos = posMax;
        for (int i = 0; i < n; i++) {
            results.push(printChange(i, prevPos));
            results.push(printChange(i, prevPos));
            prevPos = i;
        }
    } else {
        int prevPos = posMax;
        for (int i = n - 1; i >= 0; i--) {
            results.push(printChange(i, prevPos));
            results.push(printChange(i, prevPos));
            prevPos = i;
        }
    }

    cout<<results.size()<<endl;

    while(!results.empty()) {
        pair<int,int> result = results.front();
        results.pop();
        cout<<result.first + 1<<" "<<result.second + 1<<endl;
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