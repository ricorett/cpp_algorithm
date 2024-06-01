#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

void DFS(int v, const std::vector<std::vector<int>>& adjacencyMatrix, std::vector<bool>& visited, std::stack<int>& Stack);