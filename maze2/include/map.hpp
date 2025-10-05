#pragma once
#include "datatypes.hpp"

class map {
public:
	position destination;
	int m, n;
	vector<vector<int>> mat;
public:
	map(const vector<vector<int>> mat);
	~map() = default;
public:
	bool IsPathway(int x, int y) const;
	bool IsPathway(position pos) const;
	void SetDestination(int x, int y);
	void SetDestination(position pos);
	void InitMap();
	const position& GetDestination() const { return destination; }
	const vector<vector<int>>& MatTable() const { return mat; }
};

