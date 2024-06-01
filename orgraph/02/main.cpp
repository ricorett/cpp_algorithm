#include "header.h"

void DFS(int v, const std::vector<std::vector<int> >& adjacencyMatrix, std::vector<bool>& visited, std::stack<int>& Stack) {
    visited[v] = true;
    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        if (adjacencyMatrix[v][i] == 1 && !visited[i]) {
            DFS(i, adjacencyMatrix, visited, Stack);
        }
    }
    Stack.push(v);
}

void topologicalSort(const std::vector<std::vector<int>>& adjacencyMatrix) {
    int N = adjacencyMatrix.size();
    std::vector<bool> visited(N, false);
    std::stack<int> Stack;

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            DFS(i, adjacencyMatrix, visited, Stack);
        }
    }

    while (!Stack.empty()) {
        std::cout << Stack.top() + 1 << " ";
        Stack.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::ifstream inputFile("in.txt");

    if (!inputFile) {
        std::cerr << "Ошибка открытия файла" << std::endl;
        return 1;
    }

    int N;
    inputFile >> N;

    std::vector<std::vector<int>> adjacencyMatrix(N, std::vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            inputFile >> adjacencyMatrix[i][j];
        }
    }

    inputFile.close();
    topologicalSort(adjacencyMatrix);

    return 0;
}
