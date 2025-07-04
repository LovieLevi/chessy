#pragma once
#include <string>
#include <limits.h>

namespace Piece {
    enum Type {
	EMPTY,
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING,
    };
    
    // Piece::Chars[(Piece::Type) pieceType]
    // Returns the character representation of the piece.
    const static char Chars[7] = {
	'.', // Empty
	'P', // Pawn
	'N', // Knight
	'B', // Bishop
	'R', // Rook
	'Q', // Queen
	'K', // King
    };
    
    // Piece::Worths[(Piece::Type) pieceType]
    // Returns the worth of the piece.
    const static unsigned short Worths[7] = {
	0, // Empty
	1, // Pawn
	3, // Knight
	3, // Bishop
	5, // Rook
	9, // Queen
	USHRT_MAX, // King (Infinity, but restricted to short max)
    };
}
