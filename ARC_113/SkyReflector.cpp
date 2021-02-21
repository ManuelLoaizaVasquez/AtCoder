//https://atcoder.jp/contests/arc113/tasks/arc113_d
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
const Long MOD = 998244353;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

Long Add(Long a, Long b) {
  return (a + b) % MOD;
}

Long Sub(Long a, Long b) {
  return (a - b + MOD) % MOD;
}

Long Mul(Long a, Long b) {
  return (a * b) % MOD;
}

Long FastPow(Long a, Long b) {
  if (a == 0) return 0;
  Long ans = 1;
  while (b > 0) {
    if (b & 1) ans = Mul(ans, a);
    a = Mul(a, a);
    b >>= 1;
  }
  return ans;
}

void Solve(void) {
  Long n, m, k;
  cin >> n >> m >> k;
  if (n == 1) {
    cout << FastPow(k, m) << '\n';
    return;
  }
  if (m == 1) {
    cout << FastPow(k, n) << '\n';
    return;
  }
  Long ans = 0;
  for (Long i = 1; i <= k; i++) {
    Long delta_n = Sub(FastPow(i, n), FastPow(i - 1, n));
    ans = Add(ans, Mul(delta_n, FastPow(k - i + 1, m)));
  }
  cout << ans << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}

