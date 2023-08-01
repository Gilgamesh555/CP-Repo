
#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
int n, a[2002];
int sol[2002];
 
void init()
{
    cin>>n;

    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
}
 
void solve()
{
    init();

    int numIndex = 0;
    int maxNumber = 0;

    for (int i = 1; i < n; i++) { 
        if (a[i] > maxNumber) {
            maxNumber = a[i];
            numIndex = i;
        }
    }

    if(numIndex == 0) {
        for (int i = 1; i < n; i++) { 
            cout<<a[i]<<' ';
        }
        cout<<endl;

        return;
    }

    if (numIndex == n - 1) {
        int maxLeftNumber = a[0];
        int leftBound = numIndex;
        int rightBound = numIndex;

        for (int i = numIndex - 1; i >= 1; i--) {
            if (a[i] > maxLeftNumber) {
                leftBound = i;
            } else {
                break;
            }
        }
        
        cout<<leftBound<<' '<<rightBound<<endl;

        for (int i = rightBound + 1; i < n; i++) {
            cout<<a[i]<<' ';
        }

        for (int i = rightBound; i >= leftBound; i--) {
            cout<<a[i]<<' ';
        }

        for (int i = 0; i < leftBound; i++) {
            cout<<a[i]<<' ';
        }

        cout<<endl;
    } else {
        int maxLeftNumber = a[0];
        int leftBound = numIndex - 1;
        int rightBound = numIndex - 1;

        for (int i = rightBound - 1; i >= 1; i--) {
            if (a[i] > maxLeftNumber) {
                leftBound = i;
            } else {
                break;
            }
        }

        for (int i = rightBound + 1; i < n; i++) {
            cout<<a[i]<<' ';
        }

        for (int i = rightBound; i >= leftBound; i--) {
            cout<<a[i]<<' ';
        }

        for (int i = 0; i < leftBound; i++) {
            cout<<a[i]<<' ';
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