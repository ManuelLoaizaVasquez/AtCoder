//https://atcoder.jp/contests/arc113/tasks/arc113_c
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define all(v) (v).begin(),(v).end()
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 2e5;
const int ALPHABET = 26;
const Long INF = 1e18;
const Double EPS = 1e-9;

struct SegmentTree {
  bool marked[4 * N];
  Long lazy[4 * N];
  void Build(const vector<Long>& a, int id, int tl, int tr) {
    marked[id] = false;
    if (tl == tr) {
      lazy[id] = a[tl];
    } else {
      int tm = (tl + tr) / 2;
      Build(a, 2 * id, tl, tm);
      Build(a, 2 * id + 1, tm + 1, tr);
    }
  }
  void Push(int id) {
    if (marked[id]) {
      // Asignar
      lazy[2 * id] = lazy[2 * id + 1] = lazy[id];
      marked[2 * id] = marked[2 * id + 1] = true;
      // Reiniciar
      marked[id] = false;
    }
  }
  void Update(int l, int r, Long val, int id, int tl, int tr) {
    if (tr < l || tl > r) return;
    if (l <= tl && tr <= r) {
      // Asignar
      lazy[id] = val;
      marked[id] = true;
    } else {
      Push(id);
      int tm = (tl + tr) / 2;
      Update(l, r, val, 2 * id, tl, tm);
      Update(l, r, val, 2 * id + 1, tm + 1, tr);
    }
  }
  Long Query(int pos, int id, int tl, int tr) {
    if (tl == tr) return lazy[id];
    int tm = (tl + tr) / 2;
    Push(id);
    if (pos <= tm) return Query(pos, 2 * id, tl, tm);
    return Query(pos, 2 * id + 1, tm + 1, tr);
  }
} st;

struct Block {
  Long val, ini, len, id;
};

void Solve(void) {
  string s;
  cin >> s;
  Long n = s.size();
  vector<Long> a(n);
  for (int i = 0; i < n; i++) a[i] = s[i] - 'a';
  st.Build(a, 1, 0, n - 1);
  // Construyo los bloques
  vector<Block> blocks;
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j < n && a[i] == a[j]) j++;
    blocks.push_back({a[i], i, j - i, -1});
    i = j - 1;
  }
  Long ans = 0;
  vector<Block> aux;
  for (int i = 0; i < blocks.size(); i++) {
    if (aux.size() == 0) {
      aux.push_back(blocks[i]);
    } else {
      if (blocks[i].val == aux.end()[-1].val) {
        aux.end()[-1].len += blocks[i].len;
      } else {
        if (blocks[i].len == 1) {
          if (aux.end()[-1].len >= 2) {
            aux.end()[-1].len++;
            ans++;
            st.Update(blocks[i].ini, blocks[i].ini, aux.end()[-1].val, 1, 0, n - 1);
          } else {
            aux.push_back(blocks[i]);
          }
        } else {
          aux.push_back(blocks[i]);
        }
      }
    }
  } 
  blocks = aux;
  int sz = blocks.size();
  // Guardo las posiciones de cada tipo de bloque
  vector<int> adj[ALPHABET];
  for (int i = 0; i < sz; i++) {
    adj[blocks[i].val].push_back(i);
    blocks[i].id = adj[blocks[i].val].size() - 1;
  }
  for (int i = sz - 1; i >= 0; i--) {
    if (blocks[i].len >= 2) {
      Long val = blocks[i].val;
      Long ini = blocks[i].ini;
      Long len = blocks[i].len;
      Long id = blocks[i].id;
      Long block_len = adj[val].size();
      if (id == block_len - 1) {
        int nxt_pos = ini + len;
        if (nxt_pos < n) {
          ans += (Long) (n - nxt_pos);
          st.Update(nxt_pos, n - 1, val, 1, 0, n - 1);
        }
      } else {
        int first_nxt_block = blocks[adj[val][id + 1]].ini;
        Long current_color = st.Query(first_nxt_block, 1, 0, n - 1);
        int nxt_pos = ini + len;
        if (current_color == val) {
          ans += (Long) (first_nxt_block - nxt_pos);
          st.Update(nxt_pos, first_nxt_block - 1, val, 1, 0, n - 1);
        } else {
          ans += (Long) (n - nxt_pos);
          st.Update(nxt_pos, n - 1, val, 1, 0, n - 1);
        }
      }
    }
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

