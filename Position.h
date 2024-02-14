#pragma once
class Position
{
private:
	int row;
	int col;
public:
	Position(int = -1, int = -1);
	int GetRow();
	int GetCol();
	void SetRow(int);
	void SetCol(int);
	const Position& SetAll(int, int);

	bool operator==(const Position& p) const;
	bool operator!=(const Position& p) const;
	bool operator>(const Position& p) const;
	bool operator<(const Position& p) const;
	bool operator>=(const Position& p) const;
	bool operator<=(const Position& p) const;

	Position operator+(int i) const;
	Position operator-(int i) const;
	~Position();
};
int Abs(int n);
