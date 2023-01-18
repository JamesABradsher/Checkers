#include "Board.h"

bool Board::IsValidMove(int piece_x, int piece_y, int x, int y, bool& OutIsJump)
{
	// Gets the piece we want to move
	Piece* piece = m_GamePieces[std::make_pair(piece_x, piece_y)];

	// Checks that a valid piece was found at the given coordinates
	if (!piece)
		return false;

	// Checks if the target location is on the board
	if (x < 0 || x >= s_SideLength || y < 0 || y >= s_SideLength)
		return false;

	// Checks if the piece is moving in the right direction
	if (((piece->isFirstPlayer() && y <= piece_y) || (!piece->isFirstPlayer() && y >= piece_y)) && !piece->getIsKing())
		return false;

	int xChange = x - piece_x;
	int yChange = y - piece_y;

	// Checks if the piece is moving the right distance
	if (std::abs(xChange) != c_MoveDist && std::abs(yChange) != c_MoveDist)
	{
		// If the player is trying to move the piece futher away than one space, check if they are trying to jump
		if (std::abs(xChange) == c_JumpDist && std::abs(yChange) == c_JumpDist)
		{
			// Calculating the position of the oppoonent we are trying to jump
			int opponentX = (piece_x + x) / c_JumpDist;
			int opponentY = (piece_y + y)  / c_JumpDist;
			std::pair<int, int> opponentLocation = std::make_pair(opponentX, opponentY);

			// If there is no piece that can be jumped or if it is on the same team as the current palyer 
			if (!m_HasPiece[opponentX][opponentY] || m_GamePieces[opponentLocation]->isFirstPlayer() == piece->isFirstPlayer());
			{
				return false;
			}

			// Is a valid jump
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

void Board::MovePiece(int piece_x, int piece_y, int x, int y)
{
	// Determines if the Peice can move
	bool isJump = false;
	if (!IsValidMove(piece_x, piece_y, x, y, isJump))
		return;

	// Gets the piece we want to move
	Piece* piece = m_GamePieces[std::make_pair(piece_x, piece_y)];

	// Moves the Piece
	piece->setX(x);
	piece->setY(y);

	// If the piece is not a king piece and needs to be elevated
	if (!piece->getIsKing() && (y == s_SideLength - 1 && piece->isFirstPlayer()) || (y == 0 && !piece->isFirstPlayer()))
		piece->MakeKing();

	if (isJump)
	{
		// Calculates the position of the oppoonent we are trying to jump
		int opponentX = (piece_x + x) / c_JumpDist;
		int opponentY = (piece_y + y) / c_JumpDist;
		std::pair<int, int> opponentLocation = std::make_pair(opponentX, opponentY);

		RemovePiece(*m_GamePieces[opponentLocation]);
	}
}