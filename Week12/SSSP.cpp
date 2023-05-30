#include <iostream>
#include <vector>

const int INF = 1e9;

void dijkstraShortestPaths(std::vector<std::vector<int>>& graph, int source) {
    int n = graph.size();
    std::vector<int> distance(n, INF);
    std::vector<bool> visited(n, false);

    distance[source] = 0;

    for (int count = 0; count < n - 1; ++count) {
        int minimumDist = INF;
        int minimumIndex = -1;

        // Find the node with the minimum distance
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && distance[i] < minimumDist) {
                minimumDist = distance[i];
                minimumIndex = i;
            }
        }

        if (minimumIndex == -1) {
            break;  // All remaining nodes are unreachable
        }

        visited[minimumIndex] = true;

        // Update distances of adjacent nodes
        for (int j = 0; j < n; ++j) {
            if (graph[minimumIndex][j] != 0 && distance[minimumIndex] != INF && distance[minimumIndex] + graph[minimumIndex][j] < distance[j]) {
                distance[j] = distance[minimumIndex] + graph[minimumIndex][j];
            }
        }
    }

    std::cout << "Shortest distances from City " << source << " to:\n";
    for (int i = 0; i < n; ++i) {
        if (i != source) {
            std::cout << "City " << i << ": " << distance[i] << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };
    int n = graph.size();

    for (int source = 0; source < n; ++source) {
        dijkstraShortestPaths(graph, source);
    }

    return 0;
}
