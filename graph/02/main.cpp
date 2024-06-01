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

    int startVertex;
    std::cout << "Введите начальную вершину (1-" << N << "): ";
    std::cin >> startVertex;

    while (startVertex < 1 || startVertex > N) {
        std::cout << "Некорректный индекс. Пожалуйста, введите значение от 1 до " << N << ": ";
        std::cin >> startVertex;
    }

    std::vector<bool> visited(N, false);

    BFS(startVertex - 1, adjacencyMatrix, visited);

    return 0;
}
void BFS(int startVertex, std::vector<std::vector<int> >& adjacencyMatrix, std::vector<bool>& visited) {
    std::queue<int> q;
    q.push(startVertex);
    visited[startVertex] = true;

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        std::cout << vertex + 1 << " "; // +1 для соответствия индексации 1..N

        for (int i = 0; i < adjacencyMatrix.size(); ++i) {
            if (adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
