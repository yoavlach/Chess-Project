#pragma once
#include "ChessPiece.h"

class Knight : public ChessPiece
{
public:
    Knight(const std::string& color);
    virtual bool checkLegalMove(int source[], int destination[], Board board) override;
    virtual ~Knight();
};