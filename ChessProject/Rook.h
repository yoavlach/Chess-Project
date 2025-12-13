#pragma once
#include "ChessPiece.h"

class Rook : public ChessPiece
{
public:
    Rook(const std::string& color);
    virtual bool checkLegalMove(const std::string& source, const std::string& dest) override;
    virtual ~Rook();
};