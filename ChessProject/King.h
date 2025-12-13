#pragma once
#include "ChessPiece.h"
#include "Board.h"

class King : public ChessPiece
{
public:
    King(const std::string& type, const std::string& color);
    virtual bool checkLegalMove(int source[], int destination[], Board board) override;
    virtual ~King();
};