#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define graph_edge pair<int,int>

class Graph {
    private:
        int V;      // number of nodes in graph
        vector<pair<int, graph_edge>> G; // vector for graph
        vector<pair<int, graph_edge>> T; // vector for mst
        int *parent;

    public:
        Graph(int V);
        void AddEdge(int u, int v, int wt);
        int find_set(int i);
        void union_set(int u, int v);
        void kruskal_algorithm();
        void display_mst();
};


Graph::Graph(int V) {
    parent = new int[V];
    
    for (int i = 0; i < V; i++)
        parent[i] = i;
    
    G.clear();
    T.clear();
}


void Graph::AddEdge(int u, int v, int wt) {
    G.push_back(make_pair(wt, graph_edge(u, v)));
}

int Graph::find_set(int i) {
    // If i is the parent of itself
    if (i == parent[i])
        return i;
    else
        //else recursively find the parent of i
        return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
    parent[u] = parent[v];
}

void Graph::kruskal_algorithm() {
    int i, uSt, vEd;
    sort(G.begin(), G.end()); // sort the edges ordered on increasing weight
    for (i = 0; i < G.size(); i++) {
        uSt = find_set(G[i].second.first);
        vEd = find_set(G[i].second.second);
        if (uSt != vEd) {
            T.push_back(G[i]); // add to mst vector
            union_set(uSt, vEd);
        }
    }
}

void Graph::display_mst() {
    int bobot = 0;
    cout << "Edge  :" << " Weight" << endl;
    for (int i = 0; i < T.size(); i++) {
        bobot += T[i].first;
        cout << T[i].second.first << " - " << T[i].second.second << " : "
                << T[i].first;
        cout << endl;
    }

    cout << "All weight = " << bobot << endl; 
}

int main() {
    Graph gmst(8);

    gmst.AddEdge(1,2,3);  
    gmst.AddEdge(1,5,5);  
    gmst.AddEdge(2,3,5);  
    gmst.AddEdge(2,5,6);  
    gmst.AddEdge(3,4,9);  
    gmst.AddEdge(3,6,3);  
    gmst.AddEdge(4,6,7);  
    gmst.AddEdge(5,6,2);  

    gmst.kruskal_algorithm();
    cout <<"The Minimum Spanning Tree according to Kruskal's Algorithm:" << endl;
    gmst.display_mst();
    return 0;
}