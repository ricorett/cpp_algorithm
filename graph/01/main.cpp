#include "header.h"


int main() {
    std::ifstream inputFile("in.txt");

    if (!inputFile) {
        std::cerr << "Ошибка открытия файла" << std::endl;
        return 1;
    }

    int N;
    inputFile >> N;

    std::vector<std::vector<int> > adjacencyMatrix(N, std::vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            inputFile >> adjacencyMatrix[i][j];
        }
    }

    inputFile.close();

    std::vector<bool> visited(N, false);
    DFS(0, adjacencyMatrix, visited);

    return 0;
}

void DFS(int vertex, std::vector<std::vector<int> > &adjacencyMatrix, std::vector<bool> &visited) {

    std::cout << vertex + 1 << " ";

    visited[vertex] = true;

    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        if (adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i, adjacencyMatrix, visited);
        }
    }
}
