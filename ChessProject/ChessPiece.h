#pragma once
#include <iostream>

class ChessPiece
{
public:
	ChessPiece(const std::string& color, const std::string& type);
	const std::string& move(const std::string& source, const std::string& dest);
	~ChessPiece();
	bool checkLegalMove(const std::string& source, const std::string& dest);
private:
	std::string _color;
	std::string _type;
};