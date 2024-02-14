#include "Pawn.h"
#include "ChessBoard.h"

Pawn::Pawn(const ChessBoard& B, ChessColor C, Position p) : Piece(B, C, p)
{
	isDirectionDown = false;
	if (Location.GetRow() == 1)
		isDirectionDown = true;
};
void Pawn::Draw()
{
	Position TLoc = Board.GetBoxSP(Location);
	int C = Board.GetCDimension()/2;

	int Ccolor = 15;	//white color
	if (PieceColor == CBlack)
	{
		Ccolor = 0;		//black color
	}
	
	setcolor(Ccolor);
	setfillstyle(SOLID_FILL, Ccolor);
	circle(TLoc.GetCol() + C,TLoc.GetRow() + C , 8 );
	floodfill(TLoc.GetCol() + C, TLoc.GetRow()  + C, Ccolor);
}
bool Pawn::isLegal(Position Destination)
{
	if (!isDestinationValid(Destination))
		return false;

	int d = Location.GetRow() - Destination.GetRow();
	if (isDirectionDown)
	{
		d = Destination.GetRow() - Location.GetRow();
	}

	if (d > 0)
	{
		Position t;
		if (Location.GetCol() == Destination.GetCol() && (d == 1 || (d == 2 && !AmIMove() && Board.GetPiece(t.SetAll(Location.GetRow() + 1 + -2 * !isDirectionDown, Location.GetCol())) == nullptr)))
			if (Board.GetPiece(t.SetAll(Destination.GetRow(), Destination.GetCol())) == nullptr)
				return true;
			else
				return false;
		if (isDiagonal(Destination) && d == 1)
			if (Board.GetPiece(t.SetAll(Destination.GetRow(), Destination.GetCol())) != nullptr)
				return true;
	}
	return false;
}
bool Pawn::AmIPawn()
{
	return true;
}

bool Pawn::AmIMove()
{
	return (isDirectionDown && Location.GetRow() != 1) || (!isDirectionDown && Location.GetRow() != 6);
}
Pawn::~Pawn()
{

}