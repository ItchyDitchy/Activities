#include <iostream>
#include <queue>

using namespace std;

const int MAX_VERTICES = 100;

class Graph {
 private:
  int num_vertices;
  int adj_matrix[MAX_VERTICES][MAX_VERTICES];

 public:
  Graph(int vertices) {
    num_vertices = vertices;
    for (int i = 0; i < num_vertices; i++) {
      for (int j = 0; j < num_vertices; j++) {
        adj_matrix[i][j] = 0;
      }
    }
  }

  void add_edge(int u, int v) {
    this->adj_matrix[u][v] = 1;
    this->adj_matrix[v][u] = 1;
  }

  void remove_edge(int u, int v) {
    this->adj_matrix[u][v] = 0;
    this->adj_matrix[v][u] = 0;
  }

  void bfs(int start_vertex) {
    bool visited[num_vertices] = {false};
    queue<int> q;
    visited[start_vertex] = true;
    q.push(start_vertex);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      cout << u << " ";
      for (int v = 0; v < num_vertices; v++) {
        if (adj_matrix[u][v] == 1 && !visited[v]) {
          visited[v] = true;
          q.push(v);
        }
      }
    }
    cout << endl;
  }

  void dfs_traversal(int start_vertex) {
    bool visited[this->num_vertices] = {false};
    this->dfs(start_vertex, visited);
  }

  void dfs(int vertex, bool visited[]) {
    visited[vertex] = true;
    cout << vertex << " ";
    for (int i = 0; i < num_vertices; i++) {
      if (adj_matrix[vertex][i] == 1 && !visited[i]) {
        dfs(i, visited);
      }
    }
  }

  void display_matrix() {
    std::cout << "Adjacency Matrix:\n";
    for (int i = 0; i < this->num_vertices; i++) {
      for (int j = 0; j < this->num_vertices; j++)
        std::cout << this->adj_matrix[i][j] << ' ';
      std::cout << std::endl;
    }
  };
};

int main() {
  int num_vertices, choice, start_vertex, u, v;

  cout << "Enter the number of vertices in the graph (max 100): ";
  cin >> num_vertices;

  Graph graph(num_vertices);

  do {
    cout << "Menu:" << endl;
    cout << "1. Add edge" << endl;
    cout << "2. Remove edge" << endl;
    cout << "3. Breadth First Search (BFS)" << endl;
    cout << "4. Depth First Search (DFS)" << endl;
    cout << "5. Display adjacency matrix" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter the two vertices to add an edge between (0-"
             << num_vertices - 1 << "): ";
        cin >> u >> v;
        graph.add_edge(u, v);
        break;
      case 2:
        cout << "Enter the two vertices to remove the edge between (0-"
             << num_vertices - 1 << "): ";
        cin >> u >> v;
        graph.remove_edge(u, v);
        break;
      case 3:
        cout << "Enter the starting vertex for BFS (0-" << num_vertices - 1
             << "): ";
        cin >> start_vertex;
        cout << "BFS Traversal: ";
        graph.bfs(start_vertex);
        break;
      case 4:
        cout << "Enter the starting vertex for DFS (0-" << num_vertices - 1
             << "): ";
        cin >> start_vertex;
        cout << "DFS Traversal: ";
        graph.dfs_traversal(start_vertex);
        cout << endl;
        break;
      case 5:
        graph.display_matrix();
        break;
      case 6:
        cout << "Exiting..." << endl;
        break;
      default:
        cout << "Invalid choice" << endl;
        break;
    }
  } while (choice != 6);
  return 0;
}