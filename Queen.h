#pragma once
#include "Piece.h"
#include "ChessBoard.h"

class Queen : public Piece
{
public:
	Queen(const ChessBoard&, ChessColor, Position);
	void Draw();
	bool isLegal(Position);
	~Queen();
};

