#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
int n, m, seats[100002], people[100002];
int cnt1,cnt2;
 
void init()
{
    cin>>n>>m;

    cnt1=cnt2=0;

    seats[0] = 0;
    for(int i = 1; i <= m; i++){
        seats[i] = 0;
    }

    for(int i = 0; i < n; i++){
        cin>>people[i];
        
        if (people[i] == -1) {
            cnt1++;
        }
        
        if (people[i] == -2) {
            cnt2++;
        }

        if (people[i] > 0) {
            seats[people[i]] = 1;
        }
    }

    for(int i = 1; i <= m; i++){
        seats[i] += seats[i - 1];
    }
}
 
void solve()
{
    init();

    int ans = 0;

    for(int i = 0; i < n; i++){ 
        if (people[i] > 0) {
            int leftSide = min(seats[people[i]] + cnt1, people[i]);
            int rightSide = min((seats[m] - seats[people[i]]) + cnt2, m - people[i]);
            //cout<<leftSide<<" "<<rightSide<<endl;
            ans = max(ans, leftSide + rightSide);
        }
    }

    ans = max(ans, min(m, cnt1 + seats[m]));
    ans = max(ans, min(m, cnt2 + seats[m]));

    cout<<ans<<endl;

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