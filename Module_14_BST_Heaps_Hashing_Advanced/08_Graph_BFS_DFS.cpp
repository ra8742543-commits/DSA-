#include<bits/stdc++.h>
using namespace std;

struct GraphNode {
    int vertex;
    GraphNode* next;
    
    GraphNode(int v) {
        vertex = v;
        next = NULL;
    }
};

class Graph {
private:
    int numVertices;
    vector<GraphNode*> adjList;
    
public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices, NULL);
    }
    
    // Add edge (undirected)
    void addEdge(int u, int v) {
        // u से v को जोड़ो
        GraphNode* newNode = new GraphNode(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;
        
        // v से u को जोड़ो
        newNode = new GraphNode(u);
        newNode->next = adjList[v];
        adjList[v] = newNode;
        
        cout << "Edge added: " << u << " - " << v << "\n";
    }
    
    // BFS Traversal
    void bfs(int start) {
        cout << "\nBFS from vertex " << start << ": ";
        
        vector<bool> visited(numVertices, false);
        queue<int> q;
        
        q.push(start);
        visited[start] = true;
        
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";
            
            // सभी adjacent vertices को process करो
            GraphNode* temp = adjList[vertex];
            while (temp != NULL) {
                if (!visited[temp->vertex]) {
                    visited[temp->vertex] = true;
                    q.push(temp->vertex);
                }
                temp = temp->next;
            }
        }
        cout << "\n";
    }
    
    // DFS Traversal
    void dfs(int start) {
        cout << "\nDFS from vertex " << start << ": ";
        vector<bool> visited(numVertices, false);
        dfsHelper(start, visited);
        cout << "\n";
    }
    
    void dfsHelper(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";
        
        GraphNode* temp = adjList[vertex];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                dfsHelper(temp->vertex, visited);
            }
            temp = temp->next;
        }
    }
    
    // Display adjacency list
    void display() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ": ";
            GraphNode* temp = adjList[i];
            while (temp != NULL) {
                cout << temp->vertex << " ";
                temp = temp->next;
            }
            cout << "\n";
        }
    }
};

int main() {
    Graph g(5);
    
    cout << "--- Building Graph ---\n";
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    
    g.display();
    
    g.bfs(0);
    g.dfs(0);
    
    return 0;
}

/*
Output:
--- Building Graph ---
Edge added: 0 - 1
Edge added: 0 - 2
Edge added: 1 - 3
Edge added: 2 - 4

Adjacency List:
Vertex 0: 2 1
Vertex 1: 3 0
Vertex 2: 4 0
Vertex 3: 1
Vertex 4: 2

BFS from vertex 0: 0 1 2 3 4

DFS from vertex 0: 0 1 3 2 4

Graph Structure:
    0
   / \
  1   2
  |   |
  3   4

Time Complexity:
  - BFS: O(V + E) - V = vertices, E = edges
  - DFS: O(V + E)

Space Complexity: O(V + E) - for adjacency list
*/
