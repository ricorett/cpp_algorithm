#include "main.h"

int main() {
    FILE* file;
    int N;
    fopen("in.txt");
    std::vector<std::vector<int>> graph;

    //записать значения из файла
    fclose("in.txt");
    std::unordered_set<int> visited;
    dfs(graph, 0, visited);

    return 0;
}

void dfs(std::vector<std::vector<int>>& graph, int start, std::unordered_set<int>& visited) {
    visited.insert(start);
    std::cout << start << " ";

    for (int neighbor : graph[start]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(graph, neighbor, visited);
        }
    }
}
