#include "map.hpp"

map::map(const vector<vector<int>>& matrix) {
	mat = matrix;
	m = mat.size();
	n = mat[0].size();
	for (int i = 0; i < n; i++) {
		mat[0][i] = 1;
		mat[m - 1][i] = 1;
	}
	for (int j = 0; j < m; j++) {
		mat[j][0] = 1;
		mat[j][n - 1] = 1;
	}
	vector<vector<bool>> temp(40, vector<bool>(80));
	charted = temp;
}

//地图是m行n列的
//m对应y坐标，n对应x坐标
bool map::IsPathway(int x, int y) const {
	return mat[y][x] == 0;
}

bool map::IsPathway(position pos) const {
	return IsPathway(pos.x, pos.y);
}

bool map::IsDest(position pos) const {
	return pos == destination;
}

void map::SetDestination(int x, int y) {
	destination.x = x, destination.y = y;
}

void map::SetDestination(position pos) {
	destination = pos;
}

auto map::GetDestination() const -> const position& {
	return destination;
}

auto map::MatTable() -> const vector<vector<int>>& const {
	return mat;
}

void map::UpdateCharted(position current) {
	const int x = current.x, y = current.y;
	for (int i = x - 2; i < x + 3; i++) {
		for (int j = y - 2; j < y + 3; j++) {
			if (i < 0 || i  >= n) continue;
			if (j < 0 || j  >= m) continue;
			charted[j][i] = true;
		}
	}
}

void map::Draw(bool isFogMode) {
	setfillcolor(WHITE);
	const int scaleFactor = 10;
	const int posAnchor = 5;
	const int rectSize = 5;
	bool permitted = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (isFogMode && charted[j][i] == true) {
				permitted = true;
			}
			if (isFogMode && charted[j][i] == false) {
				permitted = false;
			}
			if (!IsPathway(i, j) && permitted) {
				fillrectangle(posAnchor + i * scaleFactor - rectSize,
					posAnchor + j * scaleFactor - rectSize,
					posAnchor + i * scaleFactor + rectSize,
					posAnchor + j * scaleFactor + rectSize);
			}
		}
	}
	position dest = GetDestination();
	setfillcolor(RED);
	fillcircle(dest.x * 10, dest.y * 10, 10);
}