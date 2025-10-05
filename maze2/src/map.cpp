#include "map.hpp"

map::map(const vector<vector<int>> mat) {
	this->mat = mat;
	m = mat.size();
	n = mat[0].size();
}

void map::InitMap() {
	for (int i = 0; i < n; i++) {
		mat[0][i] = 1;
		mat[m - 1][i] = 1;
	}
	for (int j = 0; j < m; j++) {
		mat[j][0] = 1;
		mat[j][n - 1] = 1;
	}
}

bool map::IsPathway(int x, int y) const {
	return mat[y][x] == 0;
}

bool map::IsPathway(position pos) const {
	return IsPathway(pos.x, pos.y);
}

void map::SetDestination(int x, int y) {
	destination.x = x, destination.y = y;
}

void map::SetDestination(position pos) {
	destination = pos;
}