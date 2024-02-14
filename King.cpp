#include "King.h"

King::King(const ChessBoard& B, ChessColor C, Position p) : Piece(B, C, p)
{
	amIMove = 0;
}
void King::Draw()
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

	int Ps[26] = { (TLoc.GetCol() + C)-5,(TLoc.GetRow() + C) - 10,
		(TLoc.GetCol() + C) + 5,(TLoc.GetRow() + C) - 10,
		(TLoc.GetCol() + C) + 5,(TLoc.GetRow() + C) - 5,
		(TLoc.GetCol() + C)+ 10,(TLoc.GetRow() + C) - 5,
		(TLoc.GetCol() + C)+10,(TLoc.GetRow() + C) + 5,
		(TLoc.GetCol() + C) + 5,(TLoc.GetRow() + C) + 5, 
		(TLoc.GetCol() + C) + 5,(TLoc.GetRow() + C) + 10, 
		(TLoc.GetCol() + C) - 5,(TLoc.GetRow() + C) + 10, 
		(TLoc.GetCol() + C)-5,(TLoc.GetRow() + C) + 5, 
		(TLoc.GetCol() + C) - 10,(TLoc.GetRow() + C) + 5, 
		(TLoc.GetCol() + C) - 10,(TLoc.GetRow() + C) - 5, 
		(TLoc.GetCol() + C) - 5,(TLoc.GetRow() + C) - 5, 
		(TLoc.GetCol() + C) - 5,(TLoc.GetRow() + C) - 10
	};
	drawpoly(13, Ps);
	floodfill(TLoc.GetCol() + C, TLoc.GetRow() + C, Ccolor);
}
bool King::isLegal(Position Destination)
{
	if (!isDestinationValid(Destination))
		return false;

	if (Board.GetPiece(Destination) != nullptr && Board.GetPiece(Destination)->GetPieceColor() == PieceColor)
		if (!AmIMove() && !Board.GetPiece(Destination)->AmIMove())
		{
			if (isHorizontalPathClear(Destination))
				return true;
		}
		else
			return false;

	int rd = Abs(Destination.GetRow() - Location.GetRow()), cd = Abs(Destination.GetCol() - Location.GetCol());
	if ((rd == 1 && (cd == 0 || cd == 1)) || (rd == 0 && cd == 1))
		return true;

	return false;
}
bool King::isDestinationValid(Position Destination)
{
	if (Piece::isDestinationValid(Destination))
		return true;

	if (Board.GetPiece(Destination)->AmIRook())
		return true;

	return false;
}

bool King::AmIKing() const
{
	return true;
}
bool King::AmIMove() const
{
	return amIMove != 0;
}
King::~King()
{

}