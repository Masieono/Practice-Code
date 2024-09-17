#include <iostream>
#include <vector>
#include <queue>

/*
    Breadth First Search is a graph traversal algorithm that explores all nodes in a graph,
    layer by layer, or level by level. BFS starts at a starting node, visits all neighbors, 
    and then moves onto the next level of neighbors. 

    BFS uses a queue (first in first out) data structure to keep track of nodes to visit next.
    BFS guarantees that the first time you visit a node, it is teh shortest path to that node (at least for an unweighted graph).

    Use cases - 
    - checking connectivity
    - finding shortest path in unweighted graph
    - determining if all vertices in a graph are connected
    - cycle detection in undirected graph
    - Level-order traversal in trees from root to leaves

    Time complexity - O(v + e) where v is vertices/nodes and e is edges.
    each node and edge are checked only once.
    
    Space complexity - 0(v) 
    requires space for the queue, visited array, adjacency list, 
    each of which requires O(v) space
*/

using std::cout;
using std::endl;

// graph class to represent undirected graph using adjacency list
class Graph {

public: 
    int num_vertices;
    std::vector<std::vector<int>> adj_list;

    // constructor
    Graph(int num_vertices)
    {
        this->num_vertices = num_vertices;
        adj_list.resize(num_vertices);
    }

    void add_edge(int u, int v)
    {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u); // symmetrical for an undirected graph
    }

    void bfs(int start)
    {
        std::vector<bool> visited(num_vertices, false); // keep track of visited nodes
        std::queue<int> q; // queue to process nodes in FIFO manner

        // mark the starting node, enqueue it
        visited[start] = true;
        q.push(start);

        while(!q.empty())
        {
            // dequeue vertex and print it
            int current = q.front();
            q.pop();
            cout << current << " ";

            // get all adjacent vertices of the dequeued vertex
            for (int neighbor : adj_list[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main () {

    // create a graph with 6 vertices
    Graph graph(6);

    // populate graph with edges

    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 3);
    graph.add_edge(1, 4);
    graph.add_edge(2, 4);
    graph.add_edge(3, 5);
    graph.add_edge(4, 5);

    cout << "Breadth-First Search starting from node 0: ";
    graph.bfs(0);

    return 0;
}