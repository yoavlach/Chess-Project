#pragma once
#include "ChessPiece.h"

class Queen : public ChessPiece
{
public:
    Queen(const std::string& color);
    virtual bool checkLegalMove(int source[], int destination[], Board board) override;
    virtual ~Queen();
};