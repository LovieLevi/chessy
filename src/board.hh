#pragma once
#include <iostream>
#include <string>

#include "piece.hh"

#define BOARD_SIZE 8

namespace Board {
    enum Style {
    	BASIC,
    	BASIC_WITH_SPACES,
    	BASIC_WITH_BORDER,
    };
    
    class Board {
    private:
	Style style;
	Piece::Type board[BOARD_SIZE][BOARD_SIZE];
    	
    public:
    	Board(Style style);
    	void Draw();
	int LoadFromFEN(std::string fen);
    };
}
