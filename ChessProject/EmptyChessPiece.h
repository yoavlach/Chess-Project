#pragma once
#include "ChessPiece.h"

class EmptyChessPiece : public ChessPiece
{
public:
    EmptyChessPiece(const std::string& color);
    virtual bool checkLegalMove(int source[], int destination[], Board board) override;
    virtual ~EmptyChessPiece();
};