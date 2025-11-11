
/*
    A BFS Algorithm to find shortest path
*/
#include "pch.h"
#ifdef EXCLUDE_THIS_FILE
#include <iostream>
#include <vector>
#include <queue>

#define TRUE 1
#define FALSE 0

using namespace std;

const int dn[4] = {-1, +1, 0, 0};
const int dm[4] = {0, 0, -1, +1};

int DungeonProblem(int** matrix, int rows, int columns, pair<int, int> start, pair<int, int> end) {
    int move_count = 0;
    int nodes_left_in_layer = 1;
    int nodes_in_next_layer = 0;
    bool reached_end = false;

    // The Queue for BFS 
    std::queue<pair<int, int>> bfsqueue;

    // Create visited matrix
    int** visited = new int*[rows];
    for(int i = 0; i < rows; i++) {
        visited[i] = new int[columns];
        for(int j = 0; j < columns; j++) {
            visited[i][j] = FALSE;
        }
    }

    // Push the first node & mark it as visited
    bfsqueue.push(start);
    visited[start.first][start.second] = TRUE;

    while(!bfsqueue.empty()) {
        auto current = bfsqueue.front();
        bfsqueue.pop();

        int n = current.first;
        int m = current.second;

        // If the end is reached, break
        if(n == end.first && m == end.second) {
            reached_end = true;
            break;
        }

        // Explore neighbours
        for(int i = 0; i < 4; i++) {
            int neighbour_n = n + dn[i];
            int neighbour_m = m + dm[i];
            if(neighbour_n < 0 || neighbour_n >= rows || neighbour_m < 0 || neighbour_m >= columns) {
                continue;
            }
            if(matrix[neighbour_n][neighbour_m] != '#' && !visited[neighbour_n][neighbour_m]) {
                bfsqueue.push(make_pair(neighbour_n, neighbour_m));
                visited[neighbour_n][neighbour_m] = TRUE;
                nodes_in_next_layer++;
            }
        }

        nodes_left_in_layer--;
        if(nodes_left_in_layer == 0) {
            move_count++;
            nodes_left_in_layer = nodes_in_next_layer;
            nodes_in_next_layer = 0;
        }
    }

    // Clean up visited matrix
    for(int i = 0; i < rows; i++) {
        delete[] visited[i];
    }
    delete[] visited;

    if(reached_end) {
        return move_count;
    }
    return -1;
}
#else
#endif