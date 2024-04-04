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

constexpr int inf = 1e15;
constexpr int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vi q(n);
    cin >> q;
    ve<pii> a(m);
    cin >> a;
    sort(all(a), [](const pii& a, const pii& b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });
    ve<double> x;
    vi num;
    x.push_back(-inf);
    num.push_back(0);
    for (int i = 1; i < m; i++) {
        double xx = 0;
        while (true) {
            int j = num.back();
            xx = (double)(a[j].second - a[i].second) / (a[i].first - a[j].first);
            if (xx > x.back()) break;
            num.pop_back();
            x.pop_back();
        }
        num.push_back(i);
        x.push_back(xx);
    }
    int ans = 0;
    for (int v : q) {
        int pos = 0, l = 0, r = x.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (v >= x[mid]) {
                pos = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        int i = num[pos];
        int cur = (v * a[i].first % mod + a[i].second) % mod;
        ans = (ans + cur) % mod;
    }
    cout << ans << "\n";
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