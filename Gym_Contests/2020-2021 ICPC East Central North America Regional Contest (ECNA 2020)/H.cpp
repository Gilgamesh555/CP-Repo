#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
// __builtin_popcount -> counts the number of 1's in a posit number
// __lg -> returns the most largest bit 1's in a number
 
void solve()
{
    int s, n;
    cin>>s>>n;
    priority_queue<int, vector<int>, greater<int> > peopleWithPaper, peopleWO;
 
 
    for (int i = 0; i < n; i++) {
        int pos;
        char val;
        cin>>pos>>val;
        if (val == 'y') {
            peopleWO.push(pos);
        } else {
            peopleWithPaper.push(pos);
        }
    }
 
    int time = 0;
    bool isUsingPaper = false;
 
    while(!peopleWithPaper.empty() || !peopleWO.empty()) {
        for (int i = 0; i < s; i++) {
            int selected = -1;
            if (!peopleWO.empty() && !peopleWithPaper.empty()) {
                if (peopleWO.top() <= peopleWithPaper.top() && !isUsingPaper) {
                    selected = peopleWO.top();
                    isUsingPaper = true;
                    peopleWO.pop();
                } else {
                    selected = peopleWithPaper.top();
                    peopleWithPaper.pop();
                }
            } else {
                if (!peopleWO.empty() && !isUsingPaper) {
                    selected = peopleWO.top();
                    peopleWO.pop();
                    isUsingPaper = true;
                }

                if (!peopleWithPaper.empty()) {
                    selected = peopleWithPaper.top();
                    peopleWithPaper.pop();
                }
            }

            if (selected == -1) {
                break;
            }
            
            if (selected != -1 && selected <= time) {
                cout<<"no\n";
                return;
            }
        }
        time++;
        isUsingPaper = false;
    }
 
    cout<<"yes\n";
    
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
    solve();
    
    return 0;
}