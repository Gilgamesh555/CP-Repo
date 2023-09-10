#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200002
using namespace std;
typedef long long int ll;
 
const int MaxBound = 1e5 * 4 + 2;
const ll inf = 1e17;
const string PI = "3141592653589793238462643383279";
 
ll v1[MaxBound], v0[MaxBound], v[100000 + 2], checked[MaxBound];
string s;
int n,q;
 
ll build(ll vv[], int pos, int bl, int br, char oper)
{
    if (bl > br) {
        return 0ll;
    }
 
    if (bl == br) {
        if (s[bl - 1] == oper) {
            vv[pos] = v[bl];
            // cout<<pos<<' '<<bl<<" 1 "<<vv[pos]<<endl;
            return vv[pos];
        }else {
            vv[pos] = 0ll;
            // cout<<pos<<' '<<bl<<" 0 "<<vv[pos]<<endl;
            return vv[pos];
        }
    }
 
    int bm = (bl + br) / 2;
 
    vv[pos] = build(vv, pos * 2, bl, bm, oper) ^ build(vv, pos * 2 + 1, bm + 1, br, oper);
    // cout<<pos<<' '<<vv[pos]<<endl;
 
    return vv[pos];
}
 
void init() 
{
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>v[i];
    }
 
    for (int i = 0; i < MaxBound; i++) {
        checked[i] = 0;
    }
 
    cin>>s;
 
    build(v1, 1, 1, n, '1');
    build(v0, 1, 1, n, '0');
 
    cin>>q;
}

void swapValues(ll& x, ll& y) {
    ll aux = x;
    x = y;
    y = aux;
}
 
void propagate(ll vv[], int pos,int bl,int br, ll inverse[]) {
    if (checked[pos] % 2ll == 1ll) {
        checked[pos] = 0;

        if (pos * 2 < 4 * n) {
            checked[pos * 2]++;
            swapValues(vv[pos * 2], inverse[pos * 2]);
        }

        if (pos * 2 + 1 < 4 * n) {
            checked[pos * 2 + 1]++;
            swapValues(vv[pos * 2 + 1], inverse[pos * 2 + 1]);
        }
    }
}
 
void reversePropagate(ll vv[], int pos) {
    if (pos <= 0) {
        return;
    }
    vv[pos] = vv[pos * 2] ^ vv[pos * 2 + 1];
    reversePropagate(vv, pos / 2);
}
 
void update(ll vv[], int pos, int bl, int br, int l, int r, ll inverse[])
{
    if (bl > br || l > r) {
        return;
    }

    propagate(vv, pos, bl, br, inverse);
 
    if (bl == l && br == r) {

        swapValues(vv[pos], inverse[pos]);

        reversePropagate(vv, pos / 2);
        reversePropagate(inverse, pos / 2);
        checked[pos]++;
    } else {
        int bm = (bl + br) / 2;
 
        update(vv, pos * 2, bl, bm, l, min(r, bm), inverse);
        update(vv, pos * 2 + 1, bm + 1, br, max(bm + 1, l), r, inverse);
    }
 
    return;
}

ll getRange(ll vv[], int pos, int bl, int br, int l, int r)
{
    if (l > r || bl > br) {
        return 0;
    }
 
    if (l == bl && r == br) {
        return vv[pos];
    } else {
        int bm = (bl + br) / 2;
        return getRange(vv, pos * 2, bl, bm, l, min(bm, r)) ^ getRange(vv, pos * 2 + 1, bm + 1, br, max(bm+1, l), r);
    }
}
 
void solve()
{
    init();
 
    int type;
 
    while (q--) {
        cin>>type;
        if (type == 1) {
            int l,r;
            cin>>l>>r;
 
            update(v1, 1, 1, n, l, r, v0);

            // for (int i = 1; i <=9 ;i++) {
            //     cout<<v1[i]<<","<<checked[i]<<endl;
            // }
            // cout<<"===============\n";
        } else {
            int value;
            cin>>value;
            if (value == 0) {
                cout<<v0[1]<<" ";
            } else {
                cout<<v1[1]<<" ";
            }
        }
    }
 
    cout<<endl;
 
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
    
    return 0;
}