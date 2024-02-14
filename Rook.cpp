#include "Rook.h"
Rook::Rook(const ChessBoard& B, ChessColor C, Position p) : Piece(B, C, p)
{
	amIMove = 0;
}
void Rook::Draw()
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
	bar((TLoc.GetCol() +C)-10, (TLoc.GetRow() +C)-10, (TLoc.GetCol() + C) + 10, (TLoc.GetRow() + C) + 10);
	floodfill(TLoc.GetCol() + C, TLoc.GetRow() + C, Ccolor);
}
bool Rook::isLegal(Position Destination)
{
	if (!isDestinationValid(Destination))
		return false;

	return (isVertical(Destination) && isVerticalPathClear(Destination)) || (isHorizontal(Destination) && isHorizontalPathClear(Destination));
}
bool Rook::AmIRook() const
{
	return true;
}
bool Rook::AmIMove()
{
	return amIMove != 0;
}

Rook::~Rook()
{

}