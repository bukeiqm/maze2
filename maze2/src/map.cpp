#include "map.hpp"

map::map(const vector<vector<int>>& matrix) {
	SetMap(matrix);
}

bool map::IsWall(int x, int y) const {
	if (x < 0 || x >= n) return true;
	if (y < 0 || y >= m) return true;
	return mat[y][x] == 1;
}

bool map::IsWall(position pos) const {
	return IsWall(pos.x, pos.y);
}

bool map::IsDestination(int x, int y) const {
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= m) return false;
	return mat[y][x] == 3;
}

bool map::IsDestination(position pos) const {
	return IsDestination(pos.x, pos.y);
}

auto map::GetStartPoint() const -> const position& {
	return startPoint;
}

auto map::GetDestination() const -> const position& {
	return destination;
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

	bool permitted = true;

	setfillcolor(RED);
	int x = destination.x, y = destination.y;
	fillcircle(x * 10 + 5, y * 10 + 5, 5);

	setfillcolor(DARKGRAY);
	setlinecolor(DARKGRAY);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (isFogMode && charted[j][i] == true) {
				permitted = true;
			}
			if (isFogMode && charted[j][i] == false) {
				permitted = false;
			}
			if (permitted == false) {
				setlinecolor(LIGHTGRAY);
				setfillcolor(LIGHTGRAY);
			}
			if (permitted == true && IsWall(i, j) == false) {
				continue;
			}
			fillrectangle(posAnchor + i * scaleFactor - rectSize,
				posAnchor + j * scaleFactor - rectSize,
				posAnchor + i * scaleFactor + rectSize,
				posAnchor + j * scaleFactor + rectSize);
			setfillcolor(DARKGRAY);
			setlinecolor(DARKGRAY);
		}
	}
}

void map::SetMap(const vector<vector<int>>& newMat) {
	mat = newMat;
	m = mat.size();
	n = mat[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[j][i] == 2) startPoint = { i,j };
			if (mat[j][i] == 3) destination = { i,j };
		}
	}
	vector<vector<bool>> temp(m, vector<bool>(n));
	charted = temp;
}

vector<int>& map::operator[] (int index) {
	return mat[index];
}

position map::GetSize() {
	//pairs(colNum,rowNum)
	return { n,m };
}

void map::SetStartPoint(position start) {
	startPoint = start;
}

void map::SetDestination(position dest) {
	destination = dest;
}