#include <string>
#include "board.hh"

int main() {
    Board::Board board(Board::Style::BASIC_WITH_BORDER);
    std::string fen;
    std::cout << "Enter FEN: ";
    std::cin >> fen;
    if (board.LoadFromFEN(fen) != 0) {
	std::cout << "Invalid FEN" << std::endl;
	return 1;
    } 
    board.Draw();
    return 0;
}
