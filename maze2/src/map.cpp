#include "map.hpp"

map::map(const vector<vector<int>>& matrix) {
	LoadFromMat(matrix);
}

bool map::IsPathway(int x, int y) const {
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= m) return false;
	return mat[y][x] != 1;
}

bool map::IsPathway(position pos) const {
	return IsPathway(pos.x, pos.y);
}

bool map::IsDest(position pos) const {
	return mat[pos.y][pos.x] == 3;
}

auto map::GetDestination() const -> const position& {
	return destination;
}

auto map::GetMat() -> const vector<vector<int>>& const {
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
			if (permitted == false && IsPathway(i,j)) {
				setfillcolor(LIGHTGRAY);
			}
			if (permitted == true && IsPathway(i, j)) {
				continue;
			}
			fillrectangle(posAnchor + i * scaleFactor - rectSize,
				posAnchor + j * scaleFactor - rectSize,
				posAnchor + i * scaleFactor + rectSize,
				posAnchor + j * scaleFactor + rectSize);
			setfillcolor(WHITE);
		}
	}
	setfillcolor(RED);
	int x = destination.x, y = destination.y;
	fillcircle(x * 10 + 5, y * 10 + 5, 5);
}

void map::LoadFromMat(const vector<vector<int>>& newMat) {
	//if (newMat.size() != mat.size() || newMat.size() != mat.size()) return;
	mat = newMat;
	m = mat.size();
	n = mat[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[j][i] == 2) startPoint = { i,j };
			if (mat[j][i] == 3) destination = { i,j };
		}
	}
	vector<vector<bool>> temp(40, vector<bool>(80));
	charted = temp;
}

vector<int>& map::operator[] (int index) {
	return mat[index];
}