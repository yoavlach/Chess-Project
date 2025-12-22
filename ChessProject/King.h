#pragma once
#include "ChessPiece.h"
#include "Board.h"

class King : public ChessPiece
{
public:
    King(const std::string& type, const std::string& color);
    virtual bool checkLegalMove(int source[], int destination[], const Board& board) override;
    virtual bool checkMakeCheck(int source[], const Board& board) override;
    virtual ~King();
};