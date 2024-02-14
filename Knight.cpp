#include "Knight.h"

Knight::Knight(const ChessBoard& B, ChessColor C, Position p) : Piece(B, C, p)
{
}
void Knight::Draw()
{
	Position TLoc = Board.GetBoxSP(Location);
	int C = Board.GetCDimension() / 2;
	int Ccolor = 15;	//white color
	if (PieceColor == CBlack)
	{
		Ccolor = 0;		//black color
	}

	setcolor(Ccolor);
	setfillstyle(SOLID_FILL, Ccolor);

	int Ps[8] = { TLoc.GetCol() + C,(TLoc.GetRow() + C) - 10, (TLoc.GetCol() + C)-10,(TLoc.GetRow() + C) +10,
		(TLoc.GetCol() + C)+10,(TLoc.GetRow() + C) + 10,TLoc.GetCol() + C,(TLoc.GetRow() + C) - 10 };
	drawpoly(4, Ps);
	floodfill(TLoc.GetCol() + C, TLoc.GetRow() + C, Ccolor);
}
bool Knight::isLegal(Position Destination)
{
	if (!isDestinationValid(Destination))
		return false;

	Position t;
	return Destination == t.SetAll(Location.GetRow() - 1, Location.GetCol() - 2) || Destination == t.SetAll(Location.GetRow() - 2, Location.GetCol() - 1) || Destination == t.SetAll(Location.GetRow() - 2, Location.GetCol() + 1) ||
		Destination == t.SetAll(Location.GetRow() - 1, Location.GetCol() + 2) || Destination == t.SetAll(Location.GetRow() + 1, Location.GetCol() + 2) || Destination == t.SetAll(Location.GetRow() + 2, Location.GetCol() + 1) ||
		Destination == t.SetAll(Location.GetRow() + 2, Location.GetCol() - 1) || Destination == t.SetAll(Location.GetRow() + 1, Location.GetCol() - 2);
}
Knight::~Knight()
{

}