//https://atcoder.jp/contests/arc113/tasks/arc113_b
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define all(v) (v).begin(),(v).end()
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const Long PHI = 4;
const Long M = 10;

Long Mul(Long a, Long b, Long m) {
  return ((a % m) * (b % m)) % m;
}

Long FastPow(Long a, Long b, Long m) {
  Long ans = 1;
  while (b > 0) {
    if (b & 1) ans = Mul(ans, a, m);
    a = Mul(a, a, m);
    b >>= 1;
  }
  return ans;
}

void Solve(void) {
  Long a, b, c;
  cin >> a >> b >> c;
  Long ans;
  if (b == 1 || b == 2 && c == 1 || b == 3 && c == 1) {
    ans = FastPow(a, b, M);
  } else {
    Long e = FastPow(b, c, PHI);
    e += PHI;
    ans = FastPow(a, e, M);
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

