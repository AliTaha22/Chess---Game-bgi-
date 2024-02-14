#pragma once
#include "Piece.h"
#include "ChessBoard.h"
class Bishop : public Piece
{
public:
	Bishop(const ChessBoard& , ChessColor , Position );
	void Draw();
	bool isLegal(Position);
	~Bishop();
};

