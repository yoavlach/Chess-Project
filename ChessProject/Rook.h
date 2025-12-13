#pragma once
#include "ChessPiece.h"
#include "Board.h"

class Rook : public ChessPiece
{
public:
    Rook(const std::string& type, const std::string& color);
    virtual bool checkLegalMove(int source[], int destination[], Board board) override;
    virtual ~Rook();
};