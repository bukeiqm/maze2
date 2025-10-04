#include<vector>
using std::vector;


struct position {
	int x, y;
	position(int x,int y):x(x),y(y){}
	bool operator==(const position& other) { return x == other.x && y == other.y; }
};

struct rect {
	int width, height;
	rect(int x, int y) :width(x), height(y) {}
};

struct cir {
	int radius;
	cir(int r) : radius(r) {}
};

class player {
private:
	position pos;
	int health;
	int direction;
	int speed;
	friend class trap;
public:
	void Move();
	void SetDirection();
	bool IsJammed(const map& map);

};

class map {
private:
	int m, n;
	vector<vector<int>> mat;
public:
	map(int m,int n);
	~map();
};

class trap {
private:
	int damage;
	int duration;
public:
	void DoDamageTo(player& player);
};