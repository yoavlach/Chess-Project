#include "ChessExceptions.h"

std::string ChessExceptions::noPieceOfSameColorInSrc() const
{
	return std::string("Piece in source doesn't belong to current player");
}
std::string ChessExceptions::pieceOfSameColorInDest() const
{
	return std::string("Piece in destination belongs to current player");
}
std::string ChessExceptions::makeCheckOnCurrPlayer() const
{
	return std::string("Move will make a check on the current player");
}
std::string ChessExceptions::illegalIndexes() const
{
	return std::string("Illegal indexes");
}
std::string ChessExceptions::illegalPieceMovement() const
{
	return std::string("Piece can't move that way");
}
std::string ChessExceptions::srcAndDestSame() const
{
	return std::string("Source and destination are the same");
}