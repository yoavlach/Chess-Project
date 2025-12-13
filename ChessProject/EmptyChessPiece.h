#pragma once
#include "ChessPiece.h"

class EmptyChessPiece : public ChessPiece
{
public:
    EmptyChessPiece(const std::string& color);
    virtual bool checkLegalMove(const std::string& source, const std::string& dest) override;
    virtual ~EmptyChessPiece();
};