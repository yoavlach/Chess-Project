#pragma once
#include "ChessPiece.h"

class Queen : public ChessPiece
{
public:
    Queen(const std::string& color);
    virtual bool checkLegalMove(const std::string& source, const std::string& dest) override;
    virtual ~Queen();
};