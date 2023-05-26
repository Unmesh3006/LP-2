#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform depth-first search
void dfs(vector<vector<int>> &graph, vector<bool> &visited, int node)
{
    // Mark the current node as visited
    visited[node] = true;
    cout << node << " ";

    // Recursively visit all adjacent unvisited nodes
    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs(graph, visited, neighbor);
        }
    }
}

// Function to perform breadth-first search
void bfs(vector<vector<int>> &graph, vector<bool> &visited, int start)
{
    queue<int> q;

    // Mark the start node as visited and enqueue it
    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        // Visit all adjacent unvisited nodes
        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void insertByEdges(vector<vector<int>> &graph, int n)
{
    int e;
    cout << "Enter the number of edges: ";
    cin >> e;
    for (int i = 1; i <= e; i++)
    {
        int a, b;
        cout << "Enter edge no. " << i << ": ";
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // print adjacency list
    for (int i = 0; i < n; i++)
    {
        cout << i << "->";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    vector<vector<int>> graph(numVertices);

    insertByEdges(graph, numVertices);

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    // Perform DFS
    cout << "DFS traversal: ";
    vector<bool> visitedDFS(numVertices, false);
    dfs(graph, visitedDFS, startNode);
    cout << endl;

    // Perform BFS
    cout << "BFS traversal: ";
    vector<bool> visitedBFS(numVertices, false);
    bfs(graph, visitedBFS, startNode);
    cout << endl;

    return 0;
}