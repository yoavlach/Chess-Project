#pragma once
#include "ChessPiece.h"

class Bishop : public ChessPiece
{
public:
    Bishop(const std::string& color);
    virtual bool checkLegalMove(const std::string& source, const std::string& dest) override;
    virtual ~Bishop();
};