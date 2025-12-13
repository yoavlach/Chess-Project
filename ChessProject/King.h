#pragma once
#include "ChessPiece.h"

class King : public ChessPiece
{
public:
    King(const std::string& color);
    virtual bool checkLegalMove(int source[], int destination[], Board board) override;
    virtual ~King();
};