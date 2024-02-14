#pragma once
#include"Piece.h"
#include"ChessColor.h"
#include"graphics.h"
#include"Rook.h"
#include"Pawn.h"
#include"Bishop.h"
#include"Knight.h"
#include"King.h"
#include"Queen.h"


using namespace std;
class ChessBoard
{
private:
	Piece * B[8][8];
	ChessColor Turn;
	int rdim, cdim;
	int BoardSize;
public:
	ChessBoard();
	void Init();
	void PrintGrid();
	void PrintBox(Position);
	void Play();
	int GetColor(Position);
	void Move(Position, Position);
	int GetRDimension() const;
	int GetCDimension() const;
	Piece* GetPiece(Position) const;
	Position GetBoxSP(Position Loc) const;
	void DisplayAllPieces() const;
	void SelectPosition(Position&)const;
	Position GetChessBoxLoc(const Position& p) const;
	bool IsStartValidSelect( Position s);
	bool isEndValidSelect(Position s, Position e);

	void DrawMovedPieces(Position S,  Position E);
	void DrawChessPieceShape(const Position& loc) const;

	~ChessBoard();
};

