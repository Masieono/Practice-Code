#include <iostream>
#include <vector>
#include <list>

/*
    Adjacency List = an array or array list of linked lists.
    
    Each linked list has a unique node at the head.
    All adjacent neighbors of the head node are added to the node's linked list.

    Runtime complexity to check an edge = O(n)
    Space complexity = O(v + e)
*/

class Graph {
    int num_vertices;                   // number of vertices in graph
    std::vector<std::list<int>> adj_list;    // vector of lists to represent adjacency list

public:
    // constructor to initialize the graph with a specific number of vertices
    Graph(int vertices) 
    {
        num_vertices = vertices;
        adj_list.resize(vertices);  // resize vector to hold 'vertices' list
    }

    // function to add an edge between two vertices (u, v)
    void add_edge(int u, int v, bool is_directed = false)
    {
        // add v to u's adjacency list
        adj_list[u].push_back(v);

        // if graph is undirected, also add u to v's list
        if(!is_directed)
        {
            adj_list[v].push_back(u);
        }
    }


    void display_adj_list()
    {
            for(int i = 0; i < num_vertices; i++)
            {
                std::cout << "Vertex " << i << ": ";
                for(auto vertex : adj_list[i])
                {
                    std::cout << vertex << " ";
                }
                std::cout << std::endl;
            }
    }

        // function to check if there is an edge between two vertices (v, u)
    bool has_edge(int u, int v) 
    {
            for(auto vertex : adj_list[u])
            {
                if(vertex == v) return true;
            }
            return false;
    }
};


int main () {
    int num_vertices = 5;
    Graph graph(num_vertices);

    // add edges to an undirected graph
    graph.add_edge(0, 1);
    graph.add_edge(0, 4);
    graph.add_edge(1, 2);
    graph.add_edge(1, 3);
    graph.add_edge(1, 4);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);

    // display the adjacency list
    graph.display_adj_list();

    std::cout << "Checking for edge between 0 and 4: " << (graph.has_edge(0, 4) ? "Yes" : "No") << std::endl;
    std::cout << "Checking for edge between 1 and 4: " << (graph.has_edge(4, 4) ? "Yes" : "No") << std::endl;

    return 0;
}