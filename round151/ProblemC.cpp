#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;

const int MaxBound = 1e5 * 2 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";

string s,l,r;
int m;
int numbers[10][2];

int convertNumber(int number) {
    int newNumber = 0;

    while(number > 0){
        newNumber  += (number % 10);
        number /= 10;
    }

    return newNumber;
}


void init()
{
    cin>>s>>m>>l>>r;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 2; j++) {
            numbers[i][j] = -1;
        }
    }
}

void solve()
{
    init();

    for (int i = 0; i < s.length(); i++) {
        int naux = s[i] - '0';
        numbers[naux][0] = numbers[naux][0] == -1 ? i : numbers[naux][0];
        numbers[naux][1] = i;
    }

    bool ans = false;

    for (int i = 0; i < m; i++) {
        int ll = l[i] - '0', rr = r[i] - '0';

        

        for (int j = ll; j <= rr; j++) {
            if (numbers[j][0] != -1) {
                if (i + 1 < m) {
                    for (int k = l[i + 1] - '0'; k <= r[i + 1] - '0'; k++) {
                        if (numbers[k][0] == -1) {
                            ans = true;
                            break;
                        }
                        if (numbers[j][0] >= numbers[k][1]) {
                            ans = true;
                            break;
                        }
                    }
                }
            } else {
                ans = true;
                break;
            }
        }
        
        if (ans) {
            break;
        }
    }

    if (ans == true) {
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }
}

int main()
{
    int t;
    cin>>t;

    while(t--) 
    {
        solve();
    }
    
    return 0;
}