
#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
int n, m, a[1002][1002];
int sol[1002][1002];
 
void init()
{
    cin>>n>>m;
}

void generateMNonPrime() {
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sol[i][j] = i * m + j + 1;
        }
    }
}

void generatePrimeButNNonPrime() {
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sol[i][j] = j * n + i + 1;
        }
    }
}

void generatePrimeButNPrime() {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            for(int j = 0; j < m; j++) {
                sol[i][j] = ((n / 2) + ((i + 1) / 2)) * m + j + 1;
            }
        } else {
            for(int j = 0; j < m; j++) {
                sol[i][j] = (i / 2) * m + j + 1;
            }
        }
        
    }
}

bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}
 
void solve()
{
    init();
    
    if (!isPrime(m)) {
        generateMNonPrime();
    } else {
        if (isPrime(n)) {
            generatePrimeButNPrime();
        } else {
            generatePrimeButNNonPrime();
        }
    }

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout<<sol[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    
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