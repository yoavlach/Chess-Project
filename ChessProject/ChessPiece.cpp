#include "ChessPiece.h"

ChessPiece::ChessPiece(const std::string& color, const std::string& type)
    : _color(color), _type(type)
{
}

ChessPiece::~ChessPiece()
{
}

std::string ChessPiece::getColor() const
{
    return _color;
}

std::string ChessPiece::getType() const
{
    return _type;
}