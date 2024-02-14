#include "Bishop.h"

Bishop::Bishop(const ChessBoard& B, ChessColor C, Position p) : Piece(B, C, p)
{
}
void Bishop::Draw()
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

	int Ps[10] = { (TLoc.GetCol() + C),(TLoc.GetRow() + C) - 10,
		(TLoc.GetCol() + C) + 10,(TLoc.GetRow() + C),
		(TLoc.GetCol() + C),(TLoc.GetRow() + C) + 10,
		(TLoc.GetCol() + C) - 10 ,(TLoc.GetRow() + C),
		(TLoc.GetCol() + C),(TLoc.GetRow() + C) - 10
	};
	fillpoly(5, Ps);
}
bool Bishop::isLegal(Position Destination)
{
	if (!isDestinationValid(Destination))
		return false;

	return isDiagonal(Destination) && isDiagonalPathClear(Destination);
}
Bishop::~Bishop()
{

}