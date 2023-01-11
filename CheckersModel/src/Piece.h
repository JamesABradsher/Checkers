#pragma once

#ifndef PIECE_H
#define PIECE_H

class Piece
{

	// Constructor
public:
	Piece() : m_X(0), m_Y(0), m_IsKing(false)
	{}

	// Member Functions
public:
	/* Function that turns a piece into a king piece */
	void MakeKing();

	/* Initiallizer function that sets x and y positions
	(This is done so that I can initiallize the Piece array in Board without having to put it on the heap)*/
	void init(int x, int y);

	// Getters
	bool getIsKing() const;
	int getX() const;
	int getY() const;

	// Member fields
private:
	int m_X, m_Y;
	bool m_IsKing;
};

#endif // !PIECE_H