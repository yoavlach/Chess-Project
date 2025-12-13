#pragma once
#include "ChessPiece.h"

class Pawn : public ChessPiece
{
public:
    Pawn(const std::string& color);
    virtual bool checkLegalMove(const std::string& source, const std::string& dest) override;
    virtual ~Pawn();
};