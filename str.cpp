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

vi prf(const string &s) {
    int n = s.size();
    vi p(n);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

vi zf(const string &s) {
    int n = s.size();
    vi z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(z[i - l], r - i);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;

        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve() {
    string a;
    cin >> a;
    vi p = prf(a);
 
    int na = a.size();
    int aut[na + 1][26]{};
    rep(i, na + 1) {
        rep(j, 26) {
            char c = j + 'A';
            if (i < na && a[i] == c) {
                aut[i][j] = i + 1;
            } else if (i == 0) {
                aut[i][j] = 0;
            } else {
                aut[i][j] = aut[p[i - 1]][j];
            }
        }
    }
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