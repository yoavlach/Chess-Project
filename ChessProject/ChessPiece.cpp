#include "ChessPiece.h"

/*Initializes a chess piece
input: the piece's color and type
output: none*/
ChessPiece::ChessPiece(const std::string& color, const std::string& type)
    : _color(color), _type(type)
{
}

/*Clears a chess piece
input: none
output: none*/
ChessPiece::~ChessPiece()
{
}

/*Gets a chess piece's color
input: none
output: the chess piece's color*/
std::string ChessPiece::getColor() const
{
    return _color;
}

/*Gets a chess piece's type
input: none
output: the chess piece's type*/
std::string ChessPiece::getType() const
{
    return _type;
}