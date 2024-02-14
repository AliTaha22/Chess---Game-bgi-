#pragma once
#include"Position.h"
#include"ChessColor.h"
#include"graphics.h"

class ChessBoard;	//compiler ko dhoka diya

using namespace std;

class Piece
{
protected:
	Position Location;
	ChessColor PieceColor;
	const ChessBoard &Board; 
public:
	Piece(const ChessBoard &, ChessColor, Position);
	virtual void Draw() = 0;
	virtual bool isLegal(Position) = 0;
	virtual bool isDestinationValid(Position);
	ChessColor GetPieceColor();
	virtual void UpdateLocation(Position);
	 Position GetLocation();


	bool isHorizontal(Position);
	bool isHorizontalPathClear(Position);
	bool isVertical(Position);
	bool isVerticalPathClear(Position);
	bool isDiagonal(Position);
	bool isDiagonalPathClear(Position);

	virtual bool AmIKing() const;
	virtual bool AmIRook() const;
	virtual bool AmIPawn();
	virtual bool AmIMove();

	~Piece();

};