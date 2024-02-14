#pragma once
#include "Piece.h"
#include "ChessBoard.h"
class Rook : public Piece
{
	int amIMove;
public:
	Rook(const ChessBoard&, ChessColor, Position);
	void Draw();
	bool isLegal(Position);

	bool AmIRook() const;
	bool AmIMove();

	~Rook();
};

