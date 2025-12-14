#pragma once
#include "iostream"

class ChessExceptions
{
public:
	std::string noPieceOfSameColorInSrc() const;
	std::string pieceOfSameColorInDest() const;
	std::string makeCheckOnCurrPlayer() const;
	std::string illegalIndexes() const;
	std::string illegalPieceMovement() const;
	std::string srcAndDestSame() const;
};