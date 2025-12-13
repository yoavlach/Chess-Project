#pragma once
#include "ChessPiece.h"

class Pawn : public ChessPiece
{
public:
    Pawn(const std::string& color);
    virtual bool checkLegalMove(int source[], int destination[], Board board) override;
    virtual ~Pawn();
};