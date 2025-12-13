#pragma once
#include <iostream>
#include <string>

class ChessPiece
{
public:
    ChessPiece(const std::string& color, const std::string& type);

    virtual void move(const std::string& source, const std::string& dest) = 0;
    virtual bool checkLegalMove(const std::string& source, const std::string& dest) = 0;

    virtual std::string getColor() const;
    virtual std::string getType() const;

    virtual ~ChessPiece() = 0;

protected:
    std::string _color;
    std::string _type;
};
