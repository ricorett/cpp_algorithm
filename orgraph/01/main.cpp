#include "header.h"


void printGraph(const std::vector<std::vector<int> >& adjacencyMatrix) {
    int N = adjacencyMatrix.size();

    for (int i = 0; i < N; ++i) {
        std::cout << "Вершина " << i + 1 << ": ";
        bool hasEdges = false;

        for (int j = 0; j < N; ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                if (hasEdges) {
                    std::cout << ", ";
                }
                std::cout << j + 1;
                hasEdges = true;
            }
        }

        if (!hasEdges) {
            std::cout << "нет";
        }

        std::cout << std::endl;
    }
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

    // Считывание матрицы смежности
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            inputFile >> adjacencyMatrix[i][j];
        }
    }

    inputFile.close();

    // Вывод графа
    printGraph(adjacencyMatrix);

    return 0;
}
