#include <iostream>
#include <vector>
using namespace std;

const int M = 4, N = 4;
vector<vector<vector<long long>>> memo;

long long countPaths(const vector<vector<int>>& mat, int i, int j, int cost) {
    if (i < 0 || j < 0 || cost < 0) return 0;
    if (i == 0 && j == 0) return (mat[0][0] == cost) ? 1 : 0;
    if (memo[i][j][cost] != -1) return memo[i][j][cost];

    int remaining = cost - mat[i][j];
    return memo[i][j][cost] =
        countPaths(mat, i - 1, j, remaining) +
        countPaths(mat, i, j - 1, remaining);
}

long long solve(const vector<vector<int>>& mat, int cost) {
    memo.assign(M, vector<vector<long long>>(N, vector<long long>(cost + 1, -1)));
    return countPaths(mat, M - 1, N - 1, cost);
}

int main() {
    vector<vector<int>> printed = {
        {4, 7, 1, 6}, {6, 7, 3, 9}, {3, 8, 1, 2}, {7, 1, 7, 3}};
    vector<vector<int>> classic = {
        {4, 7, 1, 6}, {5, 7, 3, 9}, {3, 2, 1, 2}, {7, 1, 6, 3}};

    cout << "Printed matrix, cost 25: " << solve(printed, 25) << "\n";
    cout << "Printed matrix, cost 26: " << solve(printed, 26) << "\n";
    cout << "Classic matrix, cost 25: " << solve(classic, 25) << "\n";
}