#include <iostream>
#include <vector>
#include <stack>

/*
    Search algorithm primarily for trees or graphs. Explores depth before breadth.

    The algorithm starts at a specified point, explores as far in one direction as it can go, 
    then backtracks to the most recent fork in the path. Algorithm searches the new pathway 
    until it either finds another dead end, or the object it is looking for.

    Useful for maze traversal, topological sorting, 

    Useful for graphs - cycles, bridges, articulation points, connected components

    Implementation is two variations:
        - Recursive DFS (more intuitive, easier to write, limited by recursion depth)
        - Iterative DFS with a stack (avoids recursion depth limits)

    Time Complexity:
        - O(v + e) where v = number of vertices/nodes and e = number of edges.
        - Each vertices/node and edge is visited only once.
*/

void recursive_dfs(int node, std::vector<bool>& visited, std::vector<std::vector<int>>& adj)
{
    // mark current node as visited
    visited[node] = true;
    std::cout << "Visited node: " << node << std::endl;

    for (int neighbor : adj[node])
    {
        if(!visited[neighbor])
        {
            recursive_dfs(neighbor, visited, adj);
        }
    }
}

void iterative_dfs(int start, std::vector<std::vector<int>>& adj)
{
    int num_vertices = adj.size();
    std::vector<bool> visited(num_vertices, false);

    std::stack<int> stack;
    stack.push(start);

    while(!stack.empty())
    {
        int node = stack.top();
        stack.pop();    
    
        if (!visited[node])
        {
            std::cout << "Visited node: " << node << std::endl;
            visited[node] = true;

            // push all unvisited neighbors to the stack
            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    stack.push(neighbor);
                }
            }
        }
    }
}

int main () {

    int num_vertices = 5;   // declaring number of edges/vertices

    std::vector<std::vector<int>> adj(num_vertices); // creating adjacency list for graph

    // adding edges to (undirected) graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[4].push_back(2);

    // visited array to keep track of visited nodes
    std::vector<bool> visited(num_vertices, false);

    // start DFS traversal from vertex 0
    std::cout << "Starting recursive DFS from node 0:" << std::endl;
    recursive_dfs(0, visited, adj);

    // Start DFS from vertex 0
    std::cout << "Starting iterative DFS traversal from node 0:" << std::endl;
    iterative_dfs(0, adj);

    return 0;
}