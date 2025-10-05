#include<vector>
using std::vector;

class map;
enum class direction;

struct position {
	int x, y;
	position(int x = 0,int y = 0):x(x),y(y){}
	bool operator==(const position& other) { return x == other.x && y == other.y; }
	const position& dev(direction dir, int step = 1);
};

struct rect {
	int width, height;
	rect(int x, int y) :width(x), height(y) {}
};

struct cir {
	int radius;
	cir(int r) : radius(r) {}
};

enum class direction {
	NORTH,
	EAST,
	SOUTH,
	WEST,
	STAY
};

class player {
private:
	position pos;
	direction dir;
	int health;
	int speed;
	friend class trap;
public:
	player() = default;
	player(int xCoordinate,int yCoordinate);
	~player() = default;
public:
	void Move();
	void SetDirection(direction dir);
	bool IsJammed(const map& map);
	int GetX() const { return pos.x; }
	int GetY() const { return pos.y; }
};

class map {
public:
	int m, n;
	vector<vector<int>> mat;
public:
	map(const vector<vector<int>> mat);
	~map() = default;
public:
	bool IsPathway(int x, int y) const;
	bool IsPathway(position pos) const;
	const vector<vector<int>>& MatTable() const { return mat; };
};

class trap {
private:
	position pos;
	int damage;
	int duration;
public:
	void DoDamageTo(player& player, int damage = 10) { player.health -= damage; }
	bool ShouldExist() { return duration > 0; }
};