#pragma once
#include "types.hpp"

class map {
private:
	int m, n;
	position destination;
	position startPoint;
	vector<vector<int>> mat;
	vector<vector<bool>> charted;
public:
	map(const vector<vector<int>>& mat);
	~map() = default;
public:
	bool IsPathway(int x, int y) const;
	bool IsPathway(position pos) const;
	bool IsDest(position pos) const;
	void LoadFromMat(const vector<vector<int>>& newMat);
	void UpdateCharted(position currentPos);
	auto GetDestination() const -> const position&;
	auto GetMat() -> const vector<vector<int>>&;
	void Draw(bool fogMode = false);
	vector<int>& operator[] (int index);
};

//地图是m行n列的，m对应y坐标，n对应x坐标
//0代表通路，1代表墙壁，2代表起点，3代表终点，4代表开始时的陷阱位置（陷阱不会随时间增加）
