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
		m_PieceContainer[0].init(2, 2, true);
		m_GamePieces.emplace(std::make_pair(std::make_pair(2, 2), &m_PieceContainer[0]));

		m_PieceContainer[1].init(1, 2, false);
		m_GamePieces.emplace(std::make_pair(std::make_pair(1, 2), &m_PieceContainer[1]));
	}


	// Member Functions
public:

	/* Returns true if the given coordinates are a valid place for the given piece to move */
	bool IsValidMove(int piece_x, int piece_y, int x, int y, bool& OutIsJump);

	/* Moves the given piece to the given coordinates if it is valid */
	void MovePiece(int piece_x, int piece_y, int x, int y);

	// Private member functions
private:
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
	std::map<std::pair<int, int>, Piece*> m_GamePieces;
	Piece m_PieceContainer[s_MaxPieces]; // Allocates pieces to the board stack frame. Not used other than for memory management
	bool m_HasPiece[s_SideLength][s_SideLength];
};

#endif