#pragma once

#ifndef PIECE_H
#define PIECE_H

class Piece
{

	// Constructor
public:

	Piece() : m_X(0), m_Y(0), m_IsKing(false), m_Player(false)
	{}

	// Member Functions
public:
	/* Function that turns a piece into a king piece */
	void MakeKing();

	/* Initiallizer function that sets x and y positions
	(This is done so that I can initiallize the Piece array in Board without having to put it on the heap)*/
	void init(int x, int y, bool player);

	// Getters
	bool getIsKing() const;
	int getX() const;
	int getY() const;
	bool isFirstPlayer() const; // true is player 1, false is player 2

	// Setters
	void setX(int x);
	void setY(int y);

	// Member fields
private:
	int m_X, m_Y;
	bool m_IsKing;
	bool m_Player; // true is player 1, false is player 2
};

#endif // !PIECE_H