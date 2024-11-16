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
// #define int long long
#define double long double

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

vi prf(const string& s) {
    int n = s.size();
    vi pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}

vi zf(const string& s) {
    int n = s.size();
    vi z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n && s[z[i] + i] == s[z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

void precalc() {
}

constexpr int N = 2e5;

struct trie {
    map<char, int> go[N];
    int p[N];
    int slink[N];
    int dlink[N];
    char pchar[N];
    struct node {
        map<char, int> c;
        int num = 0;
        int v = 0;
    };
    ve<node> t;

    trie() {
        rep(i, N) {
            slink[i] = -1;
            dlink[i] = -1;
        }
        t.reserve(N);
        t.push_back({});
    }

    void add(int x, const string& s, int i, int num) {
        if (i == s.size()) {
            t[x].v = 1;
            t[x].num = num;
            return;
        }

        if (t[x].c.count(s[i]) == 0) {
            int nxt = t.size();
            t[x].c[s[i]] = nxt;
            t.push_back({});
            pchar[nxt] = s[i];
            p[nxt] = x;
        }

        add(t[x].c[s[i]], s, i + 1, num);
    }

    int get_slink(int x) {
        int& s = slink[x];
        if (s != -1) return s;
        if (x == 0 || p[x] == 0) {
            s = 0;
        } else {
            s = get_go(get_slink(p[x]), pchar[x]);
        }
        return s;
    }

    int get_go(int x, char c) {
        if (go[x].count(c)) {
            return go[x][c];
        } else if (t[x].c.count(c)) {
            return go[x][c] = t[x].c[c];
        } else if (x == 0) {
            return go[x][c] = 0;
        } else {
            return go[x][c] = get_go(get_slink(x), c);
        }
    }

    int get_dlink(int x) {
        if (dlink[x] != -1) return dlink[x];
        if (x == 0) {
            return dlink[x] = 0;
        }
        int s = get_slink(x);
        if (t[s].v) {
            return dlink[x] = s;
        } else {
            return dlink[x] = get_dlink(s);
        }
    }
};

void solve() {
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