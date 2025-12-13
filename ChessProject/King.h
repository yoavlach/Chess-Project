#pragma once
#include "ChessPiece.h"

class King : public ChessPiece
{
public:
    King(const std::string& color);
    virtual bool checkLegalMove(const std::string& source, const std::string& dest) override;
    virtual ~King();
};