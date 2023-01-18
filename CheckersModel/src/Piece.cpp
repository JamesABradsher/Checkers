#include "Piece.h"

bool Piece::getIsKing() const
{
	return m_IsKing;
}

int Piece::getX() const
{
	return m_X;
}

int Piece::getY() const
{
	return m_Y;
}

bool Piece::isFirstPlayer() const
{
	return m_Player;
}

void Piece::MakeKing() 
{
	m_IsKing = true;
}

void Piece::init(int x, int y, bool player)
{
	m_X = x;
	m_Y = y;
	m_Player = player;
}

void Piece::setX(int x)
{
	m_X = x;
}

void Piece::setY(int y)
{
	m_Y = y;
}