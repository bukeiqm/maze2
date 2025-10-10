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

//��ͼ��m��n�еģ�m��Ӧy���꣬n��Ӧx����
//0����ͨ·��1����ǽ�ڣ�2������㣬3�����յ㣬4����ʼʱ������λ�ã����岻����ʱ�����ӣ�