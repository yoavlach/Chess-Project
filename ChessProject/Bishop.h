#pragma once
#include "ChessPiece.h"
#include "Board.h"

enum CHECK_NUMS { UP_RIGHT, UP_LEFT, DOWN_RIGHT, DOWN_LEFT };

class Bishop : public ChessPiece
{
public:
    Bishop(const std::string& type, const std::string& color);
    virtual bool checkLegalMove(int source[], int destination[], const Board& board) override;
    virtual bool checkMakeCheck(int source[], const Board& board) override;
    virtual ~Bishop();
};