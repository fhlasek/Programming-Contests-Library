/* Written by Filip Hlasek 2016 */
#include "template.h"
#include "../algorithms/bipartite_matching.h"

/**
* Problem bachelors at Rýchlostné programovanie
* https://people.ksp.sk/~acm/problem.php?problem=bachelors
*/

void print_vertices(vector< pair<int, int> > vertices) {
  printf("%d\n", (int)vertices.size());
  REP(i, vertices.size()) {
    if (i) printf(" ");
    printf("%d", vertices[i].first);
  }
  printf("\n");
}

BipartiteGraph bg;

int main(int argc, char *argv[]) {

  int M, F, Z;
  scanf("%d%d%d", &M, &F, &Z);

  FOR(i, 0    , M    ) bg.add_vertex1(i);
  FOR(i, M + 1, M + F) bg.add_vertex2(i);

  REP(i, Z) {
    int a, b;
    scanf("%d%d", &a, &b);
    if ((a > M && b > M) || (a <= M && b <= M)) continue;
    if (a > M) swap(a, b);
    bg.add_edge(a, b);
  }

  /*
  vector<pair<int, int> > matching = bg.maximum_matching();
  printf("Maximum matching: size = %d\n", (int)matching.size());
  REP(i, matching.size()) {
    printf("  %d %d\n", matching[i].first, matching[i].second);
  }
  */

  print_vertices(bg.maximum_independent_set());
  print_vertices(bg.minimum_vertex_cover());

  return 0;
}
