#include "Piece.h"
#include"ChessBoard.h"


Piece::Piece(const ChessBoard& B, ChessColor C, Position p) : Board(B)
{
	PieceColor = C;
	Location = p;
}
bool Piece::isHorizontal(Position Destination)
{
	return Location.GetRow() == Destination.GetRow();
}
bool Piece::isVertical(Position Destination)
{
	return Location.GetCol() == Destination.GetCol();
}
bool Piece::isDiagonal(Position Destination)
{
	int x = Location.GetRow() - Destination.GetRow();
	int y = Location.GetCol() - Destination.GetCol();
	return x == y || x == -y;
}
bool Piece::isHorizontalPathClear(Position Destination)
{
	int sC = 0, eC = 0;
	if (Location.GetCol() < Destination.GetCol())
	{
		sC = Location.GetCol() + 1;
		eC = Destination.GetCol();
	}
	else
	{
		sC = Destination.GetCol() + 1;
		eC = Location.GetCol();
	}

	Position t;
	while (sC < eC)
	{
		if (Board.GetPiece(t.SetAll(Location.GetRow(), sC)) != nullptr)
			return false;
		sC++;
	}
	return true;
}
bool Piece::isVerticalPathClear(Position Destination)
{
	int sR = 0, eR = 0;
	if (Location.GetRow() < Destination.GetRow())
	{
		sR = Location.GetRow() + 1;
		eR = Destination.GetRow();
	}
	else
	{
		sR = Destination.GetRow() + 1;
		eR = Location.GetRow();
	}

	Position t;
	while (sR < eR)
	{
		if (Board.GetPiece(t.SetAll(sR, Location.GetCol())) != nullptr)
			return false;
		sR++;
	}
	return true;
}
bool Piece::isDiagonalPathClear(Position Destination)
{
	int m = (Location.GetCol() - Destination.GetCol()) / (Location.GetRow() - Destination.GetRow());

	int sR = 0, sC = 0, eRC = 0;
	if (Location.GetRow() < Destination.GetRow())
	{
		sR = Location.GetRow() + 1;
		sC = Location.GetCol() + m;
		eRC = Destination.GetRow();
	}
	else
	{
		sR = Destination.GetRow() + 1;
		sC = Destination.GetCol() + m;
		eRC = Location.GetRow();
	}

	Position t;
	while (sR < eRC)
	{
		if (Board.GetPiece(t.SetAll(sR, sC)) != nullptr)
			return false;
		sR++;
		sC += m;
	}
	return true;
}
bool Piece::isDestinationValid(Position Destination) 
{
	if (Board.GetPiece(Destination) == nullptr)
		return true;

	if (Board.GetPiece(Destination)->GetPieceColor() == !PieceColor)
		return true;

	return false;
}
ChessColor Piece::GetPieceColor() 
{
	return PieceColor;
}
void Piece::UpdateLocation( Position location)
{
	Location = location;
}

 Position Piece::GetLocation()
{
	return Location;
}

bool Piece::AmIKing() const
{
	return false;
}
bool Piece::AmIRook() const
{
	return false;
}
bool Piece::AmIPawn()
{
	return false;
}
bool Piece::AmIMove()
{
	return false;
}
Piece::~Piece()
{

}