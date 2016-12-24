/* Written by Filip Hlasek 2016 */
#include "template.h"
#include "../algorithms/bipartite_matching.h"

/**
* Google Code Jam 2016 - Round 1B - Problem C. Technobabble
* https://code.google.com/codejam/contest/dashboard?c=11254486#s=p2
*/

// Mapping of words to integers
map<string, int> wa, wb;

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  FOR(t, 1, T) {
    int N;
    scanf("%d", &N);
    BipartiteGraph bg;
    int Wa = 0, Wb = 0; wa.clear(); wb.clear();
    REP(i, N) {
      string a, b;
      cin >> a >> b;
      if (!wa.count(a)) wa[a] = Wa++;
      if (!wb.count(b)) wb[b] = Wb++;
      bg.add_edge(wa[a], wb[b]);
    }
    int ans = N - Wa - Wb + bg.maximum_matching().size();
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
