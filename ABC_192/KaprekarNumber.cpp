//https://atcoder.jp/contests/abc192/tasks/abc192_c
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define all(v) (v).begin(),(v).end()
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

Long GetInt(const vector<Long>& d) {
  Long ans = 0;
  Long n = d.size();
  Long pot = 1;
  for (int i = n - 1; i >= 0; i--) {
    ans += pot * d[i];
    pot *= 10LL;
  }
  return ans;
}

Long Delta(Long x) {
  vector<Long> d;
  while (x > 0) {
    d.push_back(x % 10);
    x /= 10;
  }
  sort(d.begin(), d.end());
  Long g1 = GetInt(d);
  reverse(d.begin(), d.end());
  Long g2 = GetInt(d);
  return g2 - g1;
}

Long f(Long x) {
  Long delta = (x == 0) ? 0 : Delta(x);
  return delta;
}

void Solve(void) {
  Long n, k;
  cin >> n >> k;
  Long ans = n;
  for (Long i = 1; i <= k; i++) ans = f(ans);
  cout << ans << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}

