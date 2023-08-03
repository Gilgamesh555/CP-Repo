#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
long long x,y;
 
void init()
{
    cin>>x;
    y = x<<1;
}
 
void solve()
{
    init();

    if (x % 2) {
        cout<<-1<<endl;
        return;
    }

    long long aux = y;
    int bitsCnt = 0;

    while(aux > 0) {
        aux = aux>>1;
        bitsCnt++;
    }

    bitsCnt--; 

    long long ansX = 0, ansY = 0;
    bool youNeedPreserve = false;

    while(bitsCnt >= 0) {
        long long auxX = (x >> bitsCnt) & 1, auxY = (y >> bitsCnt) & 1;
        
        if (auxX == 1 && auxY == 1) {
            if (youNeedPreserve) {
                cout<<-1<<endl;
                return;
            }
            ansX = (ansX << 1);
            ansY = (ansY << 1) + 1;
            youNeedPreserve = false;
        }

        if (auxX == 1 && auxY == 0) {
            if (!youNeedPreserve) {
                cout<<-1<<endl;
                return;
            }
            ansX = (ansX << 1);
            ansY = (ansY << 1) + 1;
            youNeedPreserve = true;
        }

        if (auxX == 0 && auxY == 0) {
            if (youNeedPreserve) {
                ansX = (ansX << 1) + 1;
                ansY = (ansY << 1) + 1;
            } else {
                ansX = (ansX << 1);
                ansY = (ansY << 1); 
            }
            youNeedPreserve = false;
        }

        if (auxX == 0 && auxY == 1) {
            if (youNeedPreserve) {
                ansX = (ansX << 1) + 1;
                ansY = (ansY << 1) + 1;
            } else {
                ansX = (ansX << 1);
                ansY = (ansY << 1);
            }
            youNeedPreserve = true;
        }

        bitsCnt--;
    }

    cout<<ansX<<' '<<ansY<<endl;

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