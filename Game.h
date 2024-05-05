#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <algorithm>
#include <array>
#include <stdexcept>

class Game {
public:
    bool whiteWins;
    bool blackWins;
    bool whitesTurn;
    bool reInput;

    std::string Wcoordinate;
    std::string WchessPiece;
    std::string Bcoordinate;
    std::string BchessPiece;

    Game();
    ~Game();

    void init();
    void update(const std::string& piece, const std::string& coordinate);
    void userInput(std::string input, bool whitesTurn);
    void checkUserInput(const std::string& input, std::stringstream& ss, std::string& chessPiece, std::string& coordinate);
    void printBoard() const;

private:
    //std::array<std::array<std::string, 9>, 9> board;
    std::array<std::array<std::string, 19>, 19> board;
};

#endif // !GAME_H