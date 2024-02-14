#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	Turn = CWhite;
	ChessBoard::Init();
	ChessBoard::PrintGrid();

}
void ChessBoard::Init()
{
	for (int r = 2; r <= 5; r++)	//initializing free spaces with null
		for (int c = 0; c < 8; c++)
			B[r][c] = nullptr;
	Position TempLoc;
	B[0][0] = new Rook(*this,!Turn,TempLoc.SetAll(0,0));	//black rook
	B[7][0] = new Rook(*this, Turn, TempLoc.SetAll(7, 0));	//white rook

	B[0][1] = new Knight(*this, !Turn, TempLoc.SetAll(0, 1));	//black knight
	B[7][1] = new Knight(*this, Turn, TempLoc.SetAll(7, 1));	//white knight

	B[0][2] = new Bishop(*this, !Turn, TempLoc.SetAll(0, 2));	//black bishop
	B[7][2] = new Bishop(*this, Turn, TempLoc.SetAll(7, 2));	//white bishop

	B[0][3] = new Queen(*this, !Turn, TempLoc.SetAll(0, 3));	//black queen
	B[7][3] = new Queen(*this, Turn, TempLoc.SetAll(7, 3));	//white queen

	B[0][4] = new King(*this, !Turn, TempLoc.SetAll(0, 4));	//black king
	B[7][4] = new King(*this, Turn, TempLoc.SetAll(7, 4));	//white king

	B[0][5] = new Bishop(*this, !Turn, TempLoc.SetAll(0, 5));	//black bishop
	B[7][5] = new Bishop(*this, Turn, TempLoc.SetAll(7, 5));	//white bishop

	B[0][6] = new Knight(*this, !Turn, TempLoc.SetAll(0, 6));	//black knight
	B[7][6] = new Knight(*this, Turn, TempLoc.SetAll(7, 6));	//white knight

	B[0][7] = new Rook(*this, !Turn, TempLoc.SetAll(0, 7));	//black rook
	B[7][7] = new Rook(*this, Turn, TempLoc.SetAll(7, 7));	//white rook

	for (int i = 0; i < 8; i++)
	{
			B[1][i] = new Pawn(*this, !Turn, TempLoc.SetAll(1, i));	//black pawn
			B[6][i] = new Pawn(*this, Turn, TempLoc.SetAll(6, i));	//white pawn
	}
}
void ChessBoard::PrintGrid()
{
	BoardSize = 500;
	rdim = BoardSize / 8, cdim = BoardSize / 8;
	initwindow(BoardSize, BoardSize, "Chess");

	Position TempLoc;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			PrintBox(TempLoc.SetAll(i,j));
		}
	}
}
void ChessBoard::PrintBox(Position BoxLocation)
{
	int BoxX = cdim * BoxLocation.GetCol() , BoxY = rdim * BoxLocation.GetRow();
	int  Point[10];

	Point[0] = BoxX;
	Point[1] = BoxY;

	Point[2] = BoxX += cdim;
	Point[3] = BoxY;

	Point[4] = BoxX;
	Point[5] = BoxY += rdim;

	Point[6] = BoxX -= cdim;
	Point[7] = BoxY;

	Point[8] = BoxX;
	Point[9] = BoxY -= rdim;

	setfillstyle(SOLID_FILL, GetColor(BoxLocation));
	fillpoly(5, Point);
}
int ChessBoard::GetColor(Position L)
{
	if ( L.GetRow() % 2 == 0)
	{
		if (L.GetCol() % 2 == 0)
			return 7;		// grey
		else
			return 4;		//red
	}
	else
	{
		if (L.GetCol() % 2 == 0)
			return 4;		//red
		else
			return 7;		//grey
	}
	return -99;
}
void ChessBoard::Move(Position Start, Position Destination)
{
	if ((*this).GetPiece(Destination) == nullptr || (*this).GetPiece(Destination)->GetPieceColor() != Turn)
	{
		B[Destination.GetRow()][Destination.GetCol()] = B[Start.GetRow()][Start.GetCol()];
		B[Start.GetRow()][Start.GetCol()] = nullptr;

		B[Destination.GetRow()][Destination.GetCol()]->UpdateLocation(Destination);
	}
}
void ChessBoard::DrawChessPieceShape(const Position& loc) const
{
	if ((*this).GetPiece(loc) != nullptr)
		(*this).GetPiece(loc)->Draw();
}
void ChessBoard::DrawMovedPieces( Position S,  Position E)
{
	PrintBox(S);
	PrintBox(E);
	DrawChessPieceShape(E);
	DrawChessPieceShape(S);
	if ((*this).GetPiece(E) == nullptr)
	{
		Position t;
		if (S.GetCol() < E.GetCol())
		{
			t.SetAll(S.GetRow(), S.GetCol() + 2);
			(*this).GetPiece(t)->Draw();

			t.SetAll(E.GetRow(), E.GetCol() - 2);
			(*this).GetPiece(t)->Draw();
		}
		else
		{
			t.SetAll(S.GetRow(), S.GetCol() - 2);
			(*this).GetPiece(t)->Draw();

			t.SetAll(E.GetRow(), E.GetCol() + 3);
			(*this).GetPiece(t)->Draw();
		}
	}
}

int ChessBoard::GetRDimension() const
{
	return rdim;
}
int ChessBoard::GetCDimension() const
{
	return cdim;
}
Position ChessBoard::GetBoxSP(Position Loc) const
{
	Loc.SetAll(rdim * Loc.GetRow(), cdim * Loc.GetCol());
	return Loc;
}
void ChessBoard::Play()
{
	DisplayAllPieces();
	Position S, E;	//starting and ending position
	do
	{
			do
			{
				do
				{
					 SelectPosition(S);
				} while (!IsStartValidSelect(S));	//checks if the position selected is valid or not  i.e. out of boundary selection or selection null place
				 SelectPosition(E);	//selects destination position
				if (!isEndValidSelect(S, E) || !(*this).GetPiece(S)->isLegal(E))
				{
					continue;
				}
				break;

			} while (true);
			Move(S, E);
			Turn = !Turn;

			DrawMovedPieces(S, E);

	} while (true);
	
}
void ChessBoard::SelectPosition(Position& S)const
{
	int col = 0, row = 0;
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
		delay(50);
	}
	getmouseclick(WM_LBUTTONDOWN, col, row);
	S.SetAll(row, col);
	S = GetChessBoxLoc(S);

}
Position ChessBoard::GetChessBoxLoc(const Position& p) const
{
	Position loc, boxSP, BoardSP(0,0);
	if (BoardSP <= p && (BoardSP + BoardSize) >= p)
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
			{
				boxSP = GetBoxSP(loc.SetAll(i, j));
				if (boxSP <= p && (boxSP + BoardSize/8) >= p)
					return loc;
			}
	return loc.SetAll(-1, -1);
}
void ChessBoard::DisplayAllPieces() const
{
	for (int i = 0; i < 8; i++)	//displays all the pieces within 8x8 grid
	{
		for (int j = 0; j < 8; j++)
		{
			if (B[i][j] != nullptr)
				B[i][j]->Draw();
		}
	}
}
Piece* ChessBoard::GetPiece(Position L) const
{
	return B[L.GetRow()][L.GetCol()];
}
bool ChessBoard::IsStartValidSelect( Position s)
{
	if ((*this).GetPiece(s) == nullptr)
		return false;
	if ((*this).GetPiece(s)->GetPieceColor() == Turn)
		return true;
	return false;
}
bool ChessBoard::isEndValidSelect(Position s,  Position e)
{
	if ( s == e)
		return false;
	return true;
}
ChessBoard::~ChessBoard()
{
}