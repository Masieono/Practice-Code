#include <iostream>
#include <vector>

/*
    Adjacency matrix is one way to represent a graph in a 2 dimensional array.
    Rows and columns represent vertices of the graph.
    Each cell in the matrix holds a 0/false if there is no edge between the two vertices, or a 1/true if there is an edge.

    An undirected graph is symmetric - there is an edge from x to y and y to x
    A directed graph is not necessarily symmetric. 

    To create an adjacency matrix:
        Define the size of the matrix depending on number of vertices.
        Initialize a 2D array to store the adjacency matrix.
        Populate the matrix by marking 1/true where there is an edge, 0/false everywhere else.

*/

class Graph {
    int num_vertices;
    std::vector<std::vector<int>> adj_matrix;   // 2D vector to store matrix

public:
    // constructor to initialize the matrix
    Graph(int vertices) {
        num_vertices = vertices;
        adj_matrix.resize(vertices, std::vector<int>(vertices, 0)); // initialize all values to 0
    }

    // function to add an edge between two vertices (x, y)
    void add_edge(int x, int y) 
    {
        // for an undirected graph
        adj_matrix[x][y] = 1;
        adj_matrix[y][x] = 1;
        // for a directed graph, the symmetric add is unnecessary
    }

    // function to display the adjacency matrix
    void display_matrix()
    {
        std::cout << "Adjacency Matrix:" << std::endl;
        for(int i = 0; i < num_vertices; i++)
        {
            for(int j = 0; j < num_vertices; j++)
            {
                std::cout << adj_matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // function to remove edge
    void remove_edge(int x, int y)
    {
        // same as before, this is for an undirected graph
        adj_matrix[x][y] = 0;
        adj_matrix[y][x] = 0;
    }

    // function to check for an edge between two vertices
    bool has_edge(int x, int y)
    {
        return adj_matrix[x][y] == 1;
    }
};


int main () {
    int num_vertices = 5;
    Graph graph(num_vertices);

    // add edges
    graph.add_edge(0, 1);
    graph.add_edge(0, 4);
    graph.add_edge(1, 2);
    graph.add_edge(1, 3);
    graph.add_edge(1, 4);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);

    // display matrix
    graph.display_matrix();

    // check if there is an edge
    std::cout << "Checking for edge at 0, 4: " << (graph.has_edge(0, 4) ? "Yes" : "No") << std::endl;
    std::cout << "Checking for edge at 1, 5: " << (graph.has_edge(1, 5) ? "Yes" : "No" ) << std::endl;

    // remove an edge
    graph.remove_edge(1, 4);
    std::cout << "(1, 4) has been removed. Updated matrix: " << std::endl;
    graph.display_matrix();

    return 0;
}
