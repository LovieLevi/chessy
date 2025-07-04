#include "board.hh"

namespace Board {
    Board::Board(Style style) {
	this->style = style;
	for (short i = 0; i < BOARD_SIZE; ++i) {
	    for (short j = 0; j < BOARD_SIZE; ++j) {
		this->board[i][j] = Piece::EMPTY;
	    }
	}
    }

    std::string repeat(const std::string &str, int n) {
	std::string result;
	for (int i = 1; i < n; ++i) {
	    result += str;
	}
	return result;
    }

    void Board::Draw() {
	char letters[BOARD_SIZE] = {
	    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	
	switch (this->style) {
	case BASIC:
	    std::cout << " ";
	    for (short i = 0; i < BOARD_SIZE; ++i) {
		std::cout << letters[i];
	    }
	    std::cout << std::endl;
	    
	    for (short i = BOARD_SIZE; i > 0; --i) {
		std::cout << i << " " << std::endl;
		// TODO: Print the pieces
	    }
	    break;
	
	case BASIC_WITH_SPACES:
	    std::cout << "  ";
	    for (short i = 0; i < BOARD_SIZE; ++i) {
		std::cout << letters[i] << " ";
	    }
	    std::cout << std::endl;
	    
	    for (short i = BOARD_SIZE; i > 0; --i) {
		std::cout << i << " " << std::endl;
		// TODO: Print the pieces
	    }
	    break;
	    
	case BASIC_WITH_BORDER:
	    std::cout << "  | ";
	    for (short i = 0; i < BOARD_SIZE; ++i) {
		std::cout << letters[i];
		std::cout << " | ";
	    }
	    std::cout << std::endl << "--+" << repeat("---+", BOARD_SIZE + 1) << std::endl;
	    
	    for (short i = BOARD_SIZE; i > 0; --i) {
		std::cout << i;
		for (short j = 0; j < BOARD_SIZE; ++j) {
		    std::cout << " | " << Piece::Chars[this->board[i - 1][j]];
		}
		std::cout << " |" << std::endl << "--+" << repeat("---+", BOARD_SIZE + 1) << std::endl;
	    }
	    break;
	}
    }

    int Board::LoadFromFEN(std::string fen) {
	std::string board_rows[BOARD_SIZE];
	int i = 0;
	for (char c : fen) {
	    if (c == '/') {
		++i;
		if (i >= BOARD_SIZE) {
		    return -1;
		}
	    } else {
		board_rows[i] += c;
	    }
	}

	Piece::Type pieces[BOARD_SIZE][BOARD_SIZE];
	bool done = false;
	for (int i = 0; i < BOARD_SIZE; ++i) {
	    int j = 0;
	    for (char c : board_rows[i]) {
		if (!done) {
		    switch (c) {
		    case 'P':
		        pieces[i][j] = Piece::PAWN;
		        break;
		    case 'N':
		        pieces[i][j] = Piece::KNIGHT;
		        break;
		    case 'B':
		        pieces[i][j] = Piece::BISHOP;
		        break;
		    case 'R':
		        pieces[i][j] = Piece::ROOK;
		        break;
		    case 'Q':
		        pieces[i][j] = Piece::QUEEN;
		        break;
		    case 'K':
		        pieces[i][j] = Piece::KING;
		        break;
		    
		    case 'p':
		        pieces[i][j] = Piece::PAWN;
		        break;
		    case 'n':
		        pieces[i][j] = Piece::KNIGHT;
		        break;
		    case 'b':
		        pieces[i][j] = Piece::BISHOP;
		        break;
		    case 'r':
		        pieces[i][j] = Piece::ROOK;
		        break;
		    case 'q':
		        pieces[i][j] = Piece::QUEEN;
		        break;
		    case 'k':
		        pieces[i][j] = Piece::KING;
		        break;
		    
		    case '1':
		        pieces[i][j] = Piece::EMPTY;
		        break;
		    case '2':
		        for (int k = 0; k < 2; ++k) {
		    	pieces[i][j + k] = Piece::EMPTY;
		        }
		        j += 1;
		        break;
		    case '3':
		        for (int k = 0; k < 3; ++k) {
		    	pieces[i][j + k] = Piece::EMPTY;
		        }
		        j += 2;
		        break;
		    case '4':
		        for (int k = 0; k < 4; ++k) {
		    	pieces[i][j + k] = Piece::EMPTY;
		        }
		        j += 3;
		        break;
		    case '5':
		        for (int k = 0; k < 5; ++k) {
		    	pieces[i][j + k] = Piece::EMPTY;
		        }
		        j += 4;
		        break;
		    case '6':
		        for (int k = 0; k < 6; ++k) {
		    	pieces[i][j + k] = Piece::EMPTY;
		        }
		        j += 5;
		        break;
		    case '7':
		        for (int k = 0; k < 7; ++k) {
		    	pieces[i][j + k] = Piece::EMPTY;
		        }
		        j += 6;
		        break;
		    case '8':
		        for (int k = 0; k < 8; ++k) {
		    	pieces[i][j + k] = Piece::EMPTY;
		        }
		        j += 7;
		        break;
		    case ' ':
			done = true;
			break;
		    default:
		        return -1;
		    }
		}
		++j;
	    }
	}
	
	// Flip pieces vertically
	for (int i = 0; i < BOARD_SIZE / 2; ++i) {
	    for (int j = 0; j < BOARD_SIZE; ++j) {
		Piece::Type temp = pieces[i][j];
		pieces[i][j] = pieces[BOARD_SIZE - i - 1][j];
		pieces[BOARD_SIZE - i - 1][j] = temp;
	    }
	}
	
	for (int i = 0; i < BOARD_SIZE; ++i) {
	    for (int j = 0; j < BOARD_SIZE; ++j) {
		this->board[i][j] = pieces[i][j];
	    }
	}

	std::cout << "FEN: " << fen << std::endl;
	return 0;
    }
}
