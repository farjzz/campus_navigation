#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int n = 15; // number of vertices
const int inf = 1e9;
int adj[n][n]; // adjacency matrix
struct edge
{
    int u, v, w;
};

// arr index = node num
string locations[n] = {"GJCH", "Main gate", "Admin block", "Central avenue - first right", "Central avenue - second right", "Central avenue - third right", "MIG", "Orion", "Logos", "EEE Dept", "MME Dept", "Library", "Central avenue - first left", "CSE Dept", "Anjappar"};

// initialize adjacency matrix
void matrix()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = (i == j) ? 0 : inf;
    edge edges[] = {{1, 2, 98}, {2, 3, 125}, {3, 4, 140}, {4, 5, 92}, {5, 6, 55}, {6, 7, 132}, {7, 8, 447}, {8, 9, 370}, {9, 10, 125}, {10, 11, 250}, {2, 12, 93}, {3, 7, 207}, {4, 7, 140}, {9, 12, 55}, {12, 8, 320}, {7, 0, 300}, {8, 0, 294}, {14, 0, 700}, {8, 14, 600}, {8, 13, 590}, {11, 13, 250}, {13, 14, 140}, {8, 10, 440}};
    for (auto e : edges)
    {
        adj[e.u][e.v] = e.w;
        adj[e.v][e.u] = e.w;
    }
}

// to get node num from location name
int getNode(string s)
{
    for (int i = 0; i < n; i++)
    {
        if (locations[i] == s)
            return i;
    }
    return -1;
}

void dijkstra(int src, int dest)
{
    vector<int> P;
    vector<int> T;
    int dist[n];
    int parent[n]; // to reconstruct path

    for (int i = 0; i < n; i++)
    {
        dist[i] = inf;
        parent[i] = -1;
        if (i != src)
            T.push_back(i);
    }
    dist[src] = 0;
    P.push_back(src);

    while (P.back() != dest)
    {
        int last = P.back();
        for (int v : T)
        {
            if (adj[last][v] != inf)
            {
                int newDist = dist[last] + adj[last][v];
                if (newDist < dist[v])
                {
                    dist[v] = newDist;
                    parent[v] = last;
                }
            }
        }
        int minDist = inf, minNode = -1;
        for (int v : T)
        {
            if (dist[v] < minDist)
            {
                minDist = dist[v];
                minNode = v;
            }
        }
        if (minNode == -1)
            break; // unreachable dest
        P.push_back(minNode);
        T.erase(remove(T.begin(), T.end(), minNode), T.end());
        // remove-iterates and moves everything not equal to minNode to the front and returns the iterator of the new end. Erase actually removes them beginning from the iterator returned by remove
    }

    if (dist[dest] == inf)
    {
        cout << "No path exists";
        return;
    }

    vector<int> path;
    for (int v = dest; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    cout << "Shortest path:\n";
    for (int i = 0; i < path.size(); i++)
    {
        cout << locations[path[i]];
        if (i != path.size() - 1)
            cout << " -> ";
    }
    cout << "\nTotal dist: " << dist[dest] << endl;
}

void prim()
{
    vector<int> P;
    vector<int> T;
    int parent[n]; // to find the edge
    P.push_back(1);

    for (int i = 0; i < n; i++)
    {
        if (i != 1)
            T.push_back(i);
        parent[i] = -1;
    }
    while (!T.empty())
    {
        int min = inf, minNode = -1;
        for (int node : P)
        {
            for (int i : T)
            {
                if (adj[node][i] < min)
                {
                    min = adj[node][i];
                    minNode = i;
                    parent[minNode] = node;
                }
            }
        }
        if (minNode == -1)
        {
            cout << "Disconnected graph!";
            return;
        }
        P.push_back(minNode);
        T.erase(remove(T.begin(), T.end(), minNode), T.end());
    }
    int totWeight = 0;
    cout << "Edges in MST:\n";
    for (int i = 0; i < n; i++)
    {
        if (parent[i] != -1)
        {
            cout << locations[parent[i]] << " - " << locations[i] << " : " << adj[parent[i]][i] << endl;
            totWeight += adj[parent[i]][i];
        }
    }
    cout << "Total weight: " << totWeight << endl;
}

int main()
{
    matrix();
    string start, end;
    cout << "Enter source: ";
    getline(cin, start);
    cout << "Enter destination: ";
    getline(cin, end);
    int src = getNode(start);
    int dest = getNode(end);
    if (src == -1 || dest == -1)
    {
        cout << "Invalid location!\n";
    }
    else
    {
        dijkstra(src, dest);
    }
    prim();
}