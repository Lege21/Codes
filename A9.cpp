#include <iostream> 
#include <queue> 
using namespace std; 
class Graph { 
private: 
int n; 
    int graph[10][10]; 
 
public: 
    Graph(int nodes) { 
        n = nodes; 
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                graph[i][j] = 0; 
    } 
 
    void addEdge(int u, int v) { 
        graph[u][v] = 1; 
        graph[v][u] = 1; 
    } 
 
    void BFS(int start, int end) { 
        int visited[10] = {0}; 
        int distance[10]; 
 
        for (int i = 0; i < n; i++) 
            distance[i] = -1; 
 
        queue<int> q; 
        visited[start] = 1; 
        distance[start] = 0; 
        q.push(start); 
 
        while (!q.empty()) { 
            int cur = q.front(); 
            q.pop(); 
 
            for (int i = 0; i < n; i++) { 
                if (graph[cur][i] == 1 && visited[i] == 0) { 
                    visited[i] = 1; 
                    distance[i] = distance[cur] + 1; 
                    q.push(i); 
                } 
            } 
        } 
 
        if (visited[end]) 
            cout << "Shortest distance is: " << distance[end] << endl; 
        else 
            cout << "No route found.\n"; 
    } 
}; 
 
int main() { 
    int n, e; 
    cout << "Enter number of locations: "; 
    cin >> n; 
 
    Graph g(n); 
 
    cout << "Enter number of roads: "; 
    cin >> e; 
 
    cout << "Enter road connections (u v):\n"; 
    for (int i = 0; i < e; i++) { 
        int u, v; 
        cin >> u >> v; 
        g.addEdge(u, v); 
    } 
 
    int start, end; 
    cout << "Enter start location: "; 
    cin >> start; 
    cout << "Enter destination location: "; 
    cin >> end; 
 
    g.BFS(start, end); 
 
    return 0; 
}