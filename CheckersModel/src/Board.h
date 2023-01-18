#pragma once

#include <cmath>
#include <map>
#include "Piece.h"

#ifndef BOARD_H
#define BOARD_H

class Board
{
	//Constructor
public:
	Board()
	{
		// Tests for moving pieces


	}


	// Member Functions
public:

	/* Returns true if the given coordinates are a valid place for the given piece to move */
	bool IsValidMove(Piece& piece, int x, int y, bool& OutIsJump);

	/* Moves the given piece to the given coordinates if it is valid */
	void MovePiece(Piece& piece, int x, int y);

	// Private member functions
private:

	/* Elevates the given piece to a king piece */
	void ElevatPiece(Piece& piece);

	/* Removes a Piece from the board */
	void RemovePiece(Piece& piece);

	// Constant fields
public:
	static const int s_SideLength = 8;
	static const int s_MaxPieces = 24;
	const int c_MoveDist = 1;
	const int c_JumpDist = 2;

	// Member fields
private:
	std::map<std::pair<int, int>, Piece> m_GamePieces;
	Piece m_PieceContainer[s_MaxPieces]; // Allocates pieces to the board stack frame. Not used other than for memory management
	bool m_HasPiece[s_SideLength][s_SideLength];
};

#endif