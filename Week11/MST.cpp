#include <iostream>
#include <climits>
#include <vector>
using namespace std;

#define V 6 // Number of vertices in the graph

void primMST(int graph[V][V], int start_node) {
    vector<int> connection;
    connection.push_back(start_node);

    vector<bool> visited(V, false); // Track visited vertices
    visited[start_node] = true;

    while (connection.size() < V) {
        int min_weight = INT_MAX;
        int min_index = -1;
        int min_connection_index = -1;

        // Find the minimum weight edge connecting the visited and unvisited vertices
        for (int i = 0; i < connection.size(); i++) {
            int vertex = connection[i];
            for (int j = 0; j < V; j++) {
                if (!visited[j] && graph[vertex][j] != 0 && graph[vertex][j] < min_weight) {
                    min_weight = graph[vertex][j];
                    min_index = j;
                    min_connection_index = i;
                }
            }
        }

        if (min_index != -1) {
            cout << connection[min_connection_index] << " - " << min_index << " : " << min_weight << endl;
            connection.push_back(min_index);
            visited[min_index] = true;
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    primMST(graph, 3);

    return 0;
}
