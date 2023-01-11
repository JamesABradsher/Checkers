#include "Board.h"

bool Board::IsValidMove(Piece& piece, int x, int y, bool firstPlayer, bool& OutIsJump)
{
	// Checks if the piece is moving in the right direction
	if ((firstPlayer && y <= piece.getY() || !firstPlayer && y >= piece.getY()) && !piece.getIsKing())
		return false;


	// Checks if the piece is moving the right distance
	if (std::abs(x - piece.getX()) != c_MoveDist && std::abs(y - piece.getY()) != c_MoveDist)
	{
		// If the player is trying to move the piece futher away than one space, check if they are trying to jump
		if (std::abs(x - piece.getX()) == c_JumpDist && std::abs(y - piece.getY()) == c_JumpDist)
		{
			if (!m_HasPiece[x][y])
			{
				OutIsJump = true;
				return true;
			}
		}
		return false;
	} 
	else
	{
		// The movement within the move limit, so check if there is a piece already in the spot
		return (!m_HasPiece[x][y]);
	}
}

bool Board::MovePiece(Piece& piece, int x, int y, bool firstPlayer)
{
	bool 
	if (!)
}