#include "ChessColor.h"

ChessColor operator!(ChessColor P)
{
	if (P == CWhite)
	{
		return CBlack;
	}
	return CWhite;
}