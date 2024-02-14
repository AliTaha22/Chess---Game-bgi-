#pragma once
#include "Piece.h"
#include "ChessBoard.h"
class King : public Piece
{
	int amIMove;
public:
	King(const ChessBoard&, ChessColor, Position);
	void Draw();
	bool isLegal(Position);
	bool isDestinationValid(Position);

	bool AmIKing() const;
	bool AmIMove() const;
	~King();
};

