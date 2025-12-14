#pragma once

#include <iostream>
#include <string>

class Board;

class ChessPiece
{
public:
    ChessPiece(const std::string& color, const std::string& type);
    virtual void checkLegalMove(int source[], int destination[], const Board& board) = 0;
    virtual bool checkMakeCheck(int source[], const Board& board) = 0;
    std::string getColor() const;
    std::string getType() const;

    virtual ~ChessPiece() = 0;

protected:
    std::string _color;
    std::string _type;
};
