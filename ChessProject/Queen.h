#pragma once
#include "ChessPiece.h"
#include "Board.h"

class Queen : public ChessPiece
{
public:
    Queen(const std::string& type, const std::string& color);
    virtual bool checkLegalMove(int source[], int destination[], const Board& board) override;
    virtual ~Queen();
};