#include <iostream>
#include "Game.h"

Game* game = new Game();

int main()
{
	std::cout << "Chess" << std::endl;
	std::cout << R"(Chess Pieces:
		KG - King
		Q  - Queen
		R  - Rook
		B  - Bishop
		K  - Knight
		P  - Pawn
		)" << std::endl;

	std::cout << "Enter input in the format 'ChessPiece,Coordinate' (e.g., K,A8): \n" << std::endl;

	game->init();

	std::cin.get();
	return 0;
}