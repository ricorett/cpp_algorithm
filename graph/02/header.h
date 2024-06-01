#pragma once
#include <iostream>
#include <fstream>
#include <istream>
#include <vector>
#include <queue>

void BFS(int startVertex, std::vector<std::vector<int> >& adjacencyMatrix, std::vector<bool>& visited);