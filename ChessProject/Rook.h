#pragma once
#include "ChessPiece.h"

class Rook : public ChessPiece
{
public:
    Rook(const std::string& color);
    virtual bool checkLegalMove(int source[], int destination[], Board board) override;
    virtual ~Rook();
};