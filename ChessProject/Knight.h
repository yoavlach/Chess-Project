#pragma once
#include "ChessPiece.h"

class Knight : public ChessPiece
{
public:
    Knight(const std::string& color);
    virtual bool checkLegalMove(const std::string& source, const std::string& dest) override;
    virtual ~Knight();
};