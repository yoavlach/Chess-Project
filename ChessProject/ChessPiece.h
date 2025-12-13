#pragma once

#define ROWS_AND_COLS 8

#include <iostream>
#include <string>

#include "Board.h"

class ChessPiece
{
public:
    ChessPiece(const std::string& color, const std::string& type);

    virtual void move(const std::string& source, const std::string& dest) = 0;
    virtual bool checkLegalMove(int source[] , int destination[], Board board ) = 0;
    std::string getColor() const;
    std::string getType() const;

    virtual ~ChessPiece() = 0;

protected:
    std::string _color;
    std::string _type;
};
