#include "Game.h"

Game::Game()
{
	/*board = {{
		{ "   ", " A ", " B ", " C ", " D ", " E ", " F ", " G ", " H " },
		{ " 8 ", " R ", " K ", " B ", " Q ", " KG", " B ", " K ", " R " },
		{ " 7 ", " P ", " P ", " P ", " P ", " P ", " P ", " P ", " P " },
		{ " 6 ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   " },
		{ " 5 ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   " },
		{ " 4 ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   " },
		{ " 3 ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   " },
		{ " 2 ", " P ", " P ", " P ", " P ", " P ", " P ", " P ", " P " },
		{ " 1 ", " R ", " K ", " B ", " Q ", " KG", " B ", " K ", " R " },
	} };*/


    board = { {
    {"+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+"},
    {"|", "   ", "|", " A ", "|", " B ", "|", " C ", "|", " D ", "|", " E ", "|", " F ", "|", " G ", "|", " H ", "|"},
    {"+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+"},
    {"|", " 8 ", "|", " R ", "|", " H ", "|", " B ", "|", " Q ", "|", " K ", "|", " B ", "|", " H ", "|", " R ", "|"},
    {"+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+"},
    {"|", " 7 ", "|", " P ", "|", " P ", "|", " P ", "|", " P ", "|", " P ", "|", " P ", "|", " P ", "|", " P ", "|"},
    {"+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+"},
    {"|", " 6 ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|"},
    {"+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+"},
    {"|", " 5 ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|"},
    {"+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+"},
    {"|", " 4 ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|"},
    {"+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+"},
    {"|", " 3 ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|", "   ", "|"},
    {"+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+"},
    {"|", " 2 ", "|", " P ", "|", " P ", "|", " P ", "|", " P ", "|", " P ", "|", " P ", "|", " P ", "|", " P ", "|"},
    {"+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+"},
    {"|", " 1 ", "|", " R ", "|", " H ", "|", " B ", "|", " Q ", "|", " K ", "|", " B ", "|", " H ", "|", " R ", "|"},
    {"+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+", "---", "+"},

} };

    blackWins = false;
    whiteWins = false;
    whitesTurn = false;
    reInput = false;
}

Game::~Game()
{
}

void Game::init() {

    // Initial board print
    printBoard();

    std::string input;
    do {
        // Handling input for White's turn
        std::cout << std::endl << "Whites Turn" << std::endl;
        whitesTurn = true;

        do
        {
            try
            {
                userInput(input, whitesTurn);
            }
            catch (const char* msg)
            {
                std::cout << msg << std::endl;
            }
        } while (reInput);

        update(WchessPiece, Wcoordinate);

        printBoard();

        if (whiteWins || blackWins) break;


        // Handling input for Black's turn
        std::cout << "Blacks Turn" << std::endl;
        whitesTurn = false;

        userInput(input, whitesTurn);
        update(BchessPiece, Bcoordinate);

        printBoard();

        whiteWins = true;

    } while (!whiteWins && !blackWins);

    if (whiteWins) {
        std::cout << "White Won" << std::endl;
    }
    else {
        std::cout << "Black Won" << std::endl;
    }
}

void Game::update(const std::string& piece, const std::string& coordinate) 
{
    if (coordinate.length() < 2) return;

    // Column remains correctly calculated as before
    int col = (coordinate[0] - 'A') * 2 + 3;

    // Correcting the row calculation to accurately reflect the chessboard layout
    // The first playable row "8" maps to index 3 in the array, and each subsequent row increments by 2
    int row = 2 * ('8' - coordinate[1]) + 3;

    if (row >= 1 && row < board.size() && col >= 1 && col < board[0].size()) {
        board[row][col] = " " + piece + " ";
    }
}

void Game::userInput(std::string input, bool whitesTurn)
{
    std::getline(std::cin, input);
        if (whitesTurn)
        {
            std::stringstream ssWhite(input);
            std::getline(ssWhite, WchessPiece, ',');
            std::getline(ssWhite, Wcoordinate);
            try
            {
                checkUserInput(input, ssWhite, WchessPiece, Wcoordinate);
            }
            catch (const std::runtime_error& e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        else
        {
            std::stringstream ssBlack(input);
            std::getline(ssBlack, BchessPiece, ',');
            std::getline(ssBlack, Bcoordinate);
            try
            {
                checkUserInput(input, ssBlack, BchessPiece, Bcoordinate);
            }
            catch (const std::runtime_error& e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }

        }
    reInput = false;
}

void Game::checkUserInput(const std::string& input, std::stringstream& ss, 
    std::string& chessPiece, std::string& coordinate)
{
    if (input.empty())
    {
        reInput = true;
        throw std::runtime_error("Input is empty.");
    }
    else if (!std::getline(ss, chessPiece, ',') || !std::getline(ss, coordinate) || ss >> std::ws, !ss.eof())
    {
        reInput = true;
        throw "Invalid input format.\n";
    }
    else if (!std::all_of(input.begin(), input.end(), [](unsigned char c)
        {
            return std::isupper(c) || c == ',' || std::isdigit(c);
        }))
    {
        reInput = true;
        throw "Input must be in uppercase.\n";
    }
    else if (coordinate.length() < 2 || coordinate.length() > 3 || !std::isalpha(coordinate[0])
        || !std::all_of(coordinate.begin() + 1, coordinate.end(), [](unsigned char c) { return std::isdigit(c); }))
    {
        reInput = true;
        throw "Invalid coordinate format.\n";
    }
}

void Game::printBoard() const
{
    std::cout << std::endl;
    for (const auto& row : board) {
        for (const auto& col : row) {
            std::cout << col;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
