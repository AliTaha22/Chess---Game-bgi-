#include "Position.h"

Position::Position(int r, int c)	:row(r), col(c)
{
}
int Position::GetRow()
{
	return row;
}
int Position::GetCol()
{
	return col;
}
void Position::SetRow(int r)
{
	row = r;
}
void Position::SetCol(int c)
{
	col = c;
}
const Position& Position::SetAll(int r, int c)
{
	col = c;
	row = r;
	return (*this);
}
bool Position::operator==(const Position& p) const
{
	return row == p.row && col == p.col;
}

bool Position::operator!=(const Position& p) const
{
	return row != p.row || col != p.col;
}

bool Position::operator>(const Position& p) const
{
	if (col > p.col&& row > p.row)
		return true;
	return false;
}

bool Position::operator<(const Position& p) const
{
	return p > * this;
}

bool Position::operator>=(const Position& p) const
{
	if (col >= p.col && row >= p.row)
		return true;
	return false;
}

bool Position::operator<=(const Position& p) const
{
	return p >= *this;
}

Position Position::operator+(int i) const
{
	Position R(row + i, col + i);
	return R;
}
Position Position::operator-(int i) const
{
	return *this + (-i);
}

int Abs(int n)
{
	if (n < 0)
		n = -n;
	return n;
}
Position::~Position()
{

}