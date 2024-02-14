#pragma once
#include "Piece.h"
#include "ChessBoard.h"
class Knight : public Piece
{
public:
	Knight(const ChessBoard&, ChessColor, Position);
	void Draw();
	bool isLegal(Position);
	~Knight();
};

