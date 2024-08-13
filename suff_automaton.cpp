#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<list>
#include<cstring>
#include<cstdint>
#include<sstream>
#include<bitset>
#include<string_view>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

// #define pb push_back
#define all(p) begin(p),end(p)
#define rep(ind,sz) for(int (ind) = 0; (ind) < (sz); (ind)++)
#define vi vector<int>
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<ll,ll>
#define pss pair<string,string>
#define ve vector
#define mp make_pair
#define PI 3.14159265358979323846
#define vs ve<string>
#define int long long
#define double long double

using namespace __gnu_pbds;
using namespace std;

template <class T>
istream& operator >> (istream& in, pair<T, T>& v) { in >> v.first >> v.second; return in; }
template <class T>
istream& operator >> (istream& in, vector<T>& v) { for (auto& e : v) { in >> e; } return in; }

template <class T>
ostream& operator << (ostream& out, const pair<T, T>& v) { out << v.first << " " << v.second; return out; }
template <class T>
ostream& operator << (ostream& out, const vector<T>& v) { for (auto& e : v) { out << e << " "; } out << "\n"; return out; }

void fast() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
}

void precalc() {
}

const int AL = 26;
 
struct node{
    int nxt[AL];
    int link, len;
    node(){
        memset(nxt, -1, sizeof(nxt));
        link = -1;
        len = 0;
    }
    int& operator [](int x){
        return nxt[x];
    }
};
 
vector<node> aut;
int last;
 
void init(){
    aut.clear();
    aut.push_back(node());
    last = 0;
}

constexpr int N = 4e5;
int cnt[N];
vi ts[N];

void extend(int c){
    assert(0 <= c && c < AL);
    int cur = aut.size();
    aut.push_back(node());
    aut[cur].len = aut[last].len + 1;
    ts[aut[cur].len].push_back(cur);
    int p = last;
    while (p != -1 && aut[p][c] == -1){
        aut[p][c] = cur;
        p = aut[p].link;
    }
    if (p == -1){
        aut[cur].link = 0;
    }
    else{
        int q = aut[p][c];
        if (aut[p].len + 1 == aut[q].len){
            aut[cur].link = q;
        }
        else{
            int nw = aut.size();
            aut.push_back(aut[q]);
            aut[nw].len = aut[p].len + 1;
            ts[aut[nw].len].push_back(nw);
            while (p != -1 && aut[p][c] == q){
                aut[p][c] = nw;
                p = aut[p].link;
            }
            aut[q].link = aut[cur].link = nw;
        }
    }
    last = cur;
}

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    init();
    rep(i, a.size()) {
        extend(a[i] - 'a');
        if (a[i] == '0') cnt[last] = 1;
    }
    int ans = 0, x = 0;
    int pos = 0, len = 0;
    rep(i, b.size()) {
        int j = b[i] - 'a';
        while (x > 0 && aut[x][j] == -1) {
            x = aut[x].link;
            len = aut[x].len;
        }
        if (aut[x][j] != -1) {
            x = aut[x][j];
            len++;
        }
        if (len > ans) {
            ans = len;
            pos = i - len + 1;
        }
    }
    cout << b.substr(pos, ans) << "\n";
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast(); 
    precalc();
    int t = 1;
    // cin >> t;
    rep(i, t) {
#ifdef LOCAL
        cout << "test case #" << i + 1 << ":\n";
#endif
        solve();
    }
    return 0;
}