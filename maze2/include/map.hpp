#pragma once
#include "datatypes.hpp"

class map {
private:
	position destination;
	//地图是m行n列的
	int m, n;
	vector<vector<int>> mat;
	vector<vector<bool>> charted;
public:
	map(const vector<vector<int>>& mat);
	~map() = default;
public:
	bool IsPathway(int x, int y) const;
	bool IsPathway(position pos) const;
	bool IsDest(position pos) const;
	void SetDestination(int x, int y);
	void SetDestination(position pos);
	void UpdateCharted(position currentPos);
	auto GetDestination() const -> const position&;
	auto MatTable() -> const vector<vector<int>>&;
	void Draw(bool fogMode = false);
};

