#pragma once
#include "Piece.h"

class Pawn : public Piece
{
	bool isDirectionDown;
public:
	Pawn(const ChessBoard& , ChessColor , Position );
	void Draw();
	bool isLegal(Position);

	bool AmIPawn();
	bool AmIMove();
	~Pawn();
};

