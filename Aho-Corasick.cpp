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

#define pb push_back
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
    cout << fixed; cout.precision(10);
}

void precalc() {
}
constexpr int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    cin >> a >> b;

    vi dp(n);
    multiset<int> s;
    s.insert(inf);
    s.insert(0);
    ve<vi> v(n + 1);
    v[1].push_back(0);
    int sum = 0, ans = 0;
    rep(i, n) {
        for (int x : v[i]) {
            s.erase(s.find(x));
        }
        dp[i] = *s.begin();
        int r = max(i + 1, b[i]);
        s.insert(dp[i] + a[i]);
        v[r].push_back(dp[i] + a[i]);
        sum += a[i];
        ans = max(ans, sum - dp[i]);
    }
    cout << ans << "\n";
}

signed main() {
#ifdef LOCAL
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    fast(); 
    precalc();
    int t = 1;
    cin >> t;
    rep(i, t) {
#ifdef LOCAL
        cout << "test case #" << i + 1 << ":\n";
#endif
        solve();
    }
    return 0;
}