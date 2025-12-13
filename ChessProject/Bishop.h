#pragma once
#include "ChessPiece.h"

class Bishop : public ChessPiece
{
public:
    Bishop(const std::string& color);
    virtual bool checkLegalMove(int source[], int destination[], Board board) override;
    virtual ~Bishop();
};