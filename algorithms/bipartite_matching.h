/* Written by Filip Hlasek 2016 */

class BipartiteGraph {
  private:
    vector<int> partity1, partity2;       // Original indexes of vertices
    map<int, int> new_index1, new_index2; // Mapping to new indexes
    vector< vector<int> > graph1, graph2; // Lists of neighbours per vertex

    // Match the vertex v (new index) from the first partity with a vertex
    // from the other partity.
    // Time complexity O(number of edges in the graph)
    bool match(int v);

    // Auxilary variables used by the maximum matching algorithm
    vector<int> matched1, matched2;
    vector<bool> visited1, visited2;

  public:

    // Vertices in both partities can have the same index and are converted
    // to a different index in the internal representation.
    void add_edge(int index1, int index2);
    void add_vertex1(int index);
    void add_vertex2(int index);

    // Returns a list of edges in the matching.
    // Every edge is described by original indexes if the matched vertices.
    // Time complexity: O(number of edges in the grpah * partity1 size)
    vector< pair<int, int> > maximum_matching();

    // Returns a list of pairs (original index, partity), where partity is 1 or 2
    vector< pair<int, int> > maximum_independent_set();
    vector< pair<int, int> > minimum_vertex_cover();
};

void BipartiteGraph::add_edge(int index1, int index2) {
  add_vertex1(index1);
  add_vertex2(index2);
  int i1 = new_index1[index1], i2 = new_index2[index2];
  graph1[i1].push_back(i2);
  graph2[i2].push_back(i1);
}

void BipartiteGraph::add_vertex1(int index) {
   // if a vertex with that index is already in the graph, don't add it again
  if (new_index1.find(index) != new_index1.end()) return;

  new_index1[index] = (int)partity1.size();
  partity1.push_back(index);
  graph1.push_back(vector<int>());
}

void BipartiteGraph::add_vertex2(int index) {
   // if a vertex with that index is already in the graph, don't add it again
  if (new_index2.find(index) != new_index2.end()) return;

  new_index2[index] = (int)partity2.size();
  partity2.push_back(index);
  graph2.push_back(vector<int>());
}

bool BipartiteGraph::match(int v) {
  visited1[v] = true;
  REP(i, graph1[v].size()) {
    int w = graph1[v][i];
    // Try to match vertex v with its neighbor vertex w.
    // It is possible if either w is still unmatcheed or
    // its partner can be matched somewhere else.
    if (matched2[w] == -1 || (!visited1[matched2[w]] && match(matched2[w]))) {
      matched1[v] = w;
      matched2[w] = v;
      return true;
    }
  }
  return false;
}

vector< pair<int, int> > BipartiteGraph::maximum_matching() {

  // Clear auxilary variables.
  matched1.clear(); matched2.clear();
  visited1.clear(); visited2.clear();
  REP(i, partity1.size()) {
    matched1.push_back(-1);
    visited1.push_back(false);
  }
  REP(i, partity2.size()) {
    matched2.push_back(-1); // not matched yet
    visited2.push_back(false);
  }

  // The main loop of the algorithm. Try to match vertex i.
  REP(i, partity1.size()) {
    REP(j, partity1.size()) visited1[j] = false;
    match(i);
  }

  // Format the result.
  vector< pair<int, int> > result;
  REP(i, partity1.size()) if (matched1[i] != -1) {
    result.push_back(make_pair(partity1[i], partity2[matched1[i]]));
  }
  return result;
}

vector< pair<int, int> > BipartiteGraph::maximum_independent_set() {
  maximum_matching(); // precalculate matched1 and matched2

  // It represents whether the vertex is a member of the independent set
  REP(i, partity1.size()) visited1[i] = false;
  REP(i, partity2.size()) visited2[i] = true;

  vector< pair<int, int> > result;
  REP(i, partity1.size()) if (matched1[i] == -1) {
    // Seach the graph for every unmatched vertex from the first partity
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int v = q.front(); q.pop();
      result.push_back(make_pair(partity1[v], 1));
      visited1[v] = true;
      REP(i, graph1[v].size()) {
        int w = graph1[v][i];
        if (!visited2[w]) continue;
        visited2[w] = false;
        q.push(matched2[w]);
      }
    }
  }
  REP(i, partity2.size()) if (visited2[i]) {
    result.push_back(make_pair(partity2[i], 2));
  }

  return result;
}

// The complement of the maximum independent set
vector< pair<int, int> > BipartiteGraph::minimum_vertex_cover() {
  maximum_independent_set(); // Initialize visited1 and visited2
  vector< pair<int, int> > result;
  REP(i, partity1.size()) if (!visited1[i]) {
    result.push_back(make_pair(partity1[i], 1));
  }
  REP(i, partity2.size()) if (!visited2[i]) {
    result.push_back(make_pair(partity2[i], 2));
  }
  return result;
}
