#include "Queen.h"
Queen::Queen(const ChessBoard& B, ChessColor C, Position p) : Piece(B,C,p)
{
}
void Queen::Draw()
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

	int Ps[26] = { (TLoc.GetCol() + C),(TLoc.GetRow() + C) - 5,
		(TLoc.GetCol() + C) + 5,(TLoc.GetRow() + C) - 10,
		(TLoc.GetCol() + C) + 10,(TLoc.GetRow() + C) - 5,
		(TLoc.GetCol() + C) + 5,(TLoc.GetRow() + C),
		(TLoc.GetCol() + C) + 10,(TLoc.GetRow() + C) + 5,
		(TLoc.GetCol() + C) + 5,(TLoc.GetRow() + C) + 10,
		(TLoc.GetCol() + C),(TLoc.GetRow() + C) + 5,
		(TLoc.GetCol() + C) - 5,(TLoc.GetRow() + C) + 10,
		(TLoc.GetCol() + C) - 10,(TLoc.GetRow() + C) + 5,
		(TLoc.GetCol() + C) - 5,(TLoc.GetRow() + C),
		(TLoc.GetCol() + C) - 10,(TLoc.GetRow() + C) - 5,
		(TLoc.GetCol() + C) - 5,(TLoc.GetRow() + C) - 10,
		(TLoc.GetCol() + C),(TLoc.GetRow() + C) - 5
	};
	fillpoly(13,Ps);
}
bool Queen::isLegal(Position Destination)
{
	if (!isDestinationValid(Destination))
		return false;

	return (isDiagonal(Destination) && isDiagonalPathClear(Destination)) || (isVertical(Destination) && isVerticalPathClear(Destination)) || (isHorizontal(Destination)
		&& isHorizontalPathClear(Destination));
}
Queen::~Queen()
{

}