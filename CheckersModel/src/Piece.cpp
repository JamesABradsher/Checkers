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

void Piece::MakeKing() 
{
	m_IsKing = true;
}