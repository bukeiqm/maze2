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

//��ͼ��m��n�еģ�m��Ӧy���꣬n��Ӧx����
//0����ͨ·��1����ǽ�ڣ�2������㣬3�����յ㣬4����ʼʱ������λ�ã����岻����ʱ�����ӣ�
