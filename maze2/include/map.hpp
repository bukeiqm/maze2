#pragma once
#include "types.hpp"

class map {
private:
	int m, n;
	position destination;
	position startPoint;
	vector<vector<int>> mat;
	vector<vector<bool>> charted;
private:
	vector<int>& operator[] (int index);
public:
	map(const vector<vector<int>>& mat);
	~map() = default;
public:
	bool IsWall(int x, int y) const;
	bool IsWall(position pos) const;
	bool IsDestination(int x, int y) const;
	bool IsDestination(position pos) const;
	auto GetStartPoint() const -> const position&;
	auto GetDestination() const -> const position&;
	void SetStartPoint(position start);
	void SetDestination(position dest);
	void SetMap(const vector<vector<int>>& newMat);
	void UpdateCharted(position currentPos);
	position GetSize();
	void Draw(bool fogMode = false);
};

//地图是m行n列的，m对应y坐标，n对应x坐标
//0代表通路，1代表墙壁，2代表起点，3代表终点，4代表开始时的陷阱位置（陷阱不会随时间增加）