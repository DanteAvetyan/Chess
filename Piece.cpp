#include "Piece.h"
#include <cmath>
#include <iostream>

Knight::Knight(Color color) : color(color) {}

bool Knight::isValidMove(int startX, int startY, int endX, int endY, const std::vector<std::vector<Piece*>>& board) const
{
    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);

    // Move is L-shaped and within board limits
    bool isLShaped = (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
    bool isWithinBounds = endX >= 0 && endX < 8 && endY >= 0 && endY < 8;

    // Destination cell is free or has an opponent's piece
    bool isDestinationValid = board[endX][endY] == nullptr || board[endX][endY]->color != this->color;

    return isLShaped && isWithinBounds && isDestinationValid;
}

std::string Knight::symbol() const
{
    return color == Color::White ? "WH" : "BH";  // 'N' for White knight, 'n' for Black knight
}



Rook::Rook(Color color) : color(color) {}

bool Rook::isValidMove(int startX, int startY, int endX, int endY, const std::vector<std::vector<Piece*>>& board) const
{
    bool isStraightLine = (startX == endX) || (startY == endY);
    bool isWithinBounds = endX >= 0 && endX < 8 && endY >= 0 && endY < 8;
    bool isPathClear = true;

    for (int i = std::min(startX, endX) + 1; i < std::max(startX, endX); i++) {
        if (board[i][startY] != nullptr) {
            isPathClear = false;
            break;
        }
    }
    for (int j = std::min(startY, endY) + 1; j < std::max(startY, endY); j++) {
        if (board[startX][j] != nullptr) {
            isPathClear = false;
            break;
        }
    }

    bool isDestinationValid = board[endX][endY] == nullptr || board[endX][endY]->color != this->color;

    return isStraightLine && isWithinBounds && isPathClear && isDestinationValid;
}

std::string Rook::symbol() const
{
    return color == Color::White ? "WR" : "BR";  // 'WR' for White knight, 'BR' for Black knight
}



Bishop::Bishop(Color color) : color(color) {}

bool Bishop::isValidMove(int startX, int startY, int endX, int endY, const std::vector<std::vector<Piece*>>& board) const
{
    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);

    // Bishop moves diagonally, meaning dx and dy must be equal
    bool isDiagonal = dx == dy;
    bool isWithinBounds = endX >= 0 && endX < 8 && endY >= 0 && endY < 8;
    bool isPathClear = true;

    // Checking the path is clear
    int xStep = (endX > startX) ? 1 : -1;
    int yStep = (endY > startY) ? 1 : -1;
    int x = startX + xStep, y = startY + yStep;

    while (x != endX && y != endY) {
        if (board[x][y] != nullptr) {
            isPathClear = false;
            break;
        }
        x += xStep;
        y += yStep;
    }

    bool isDestinationValid = board[endX][endY] == nullptr || board[endX][endY]->color != this->color;

    return isDiagonal && isWithinBounds && isPathClear && isDestinationValid;
}

std::string Bishop::symbol() const
{
    return color == Color::White ? "WB" : "BB";
}



Queen::Queen(Color color) : color(color) {}

bool Queen::isValidMove(int startX, int startY, int endX, int endY, const std::vector<std::vector<Piece*>>& board) const
{
    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);

    // Queen moves diagonally or straight
    bool isStraightOrDiagonal = (dx == dy) || (startX == endX) || (startY == endY);
    bool isWithinBounds = endX >= 0 && endX < 8 && endY >= 0 && endY < 8;
    bool isPathClear = true;

    // Path checking logic combines Rook and Bishop logic
    int xStep = (dx != 0) ? ((endX > startX) ? 1 : -1) : 0;
    int yStep = (dy != 0) ? ((endY > startY) ? 1 : -1) : 0;
    int x = startX + xStep, y = startY + yStep;

    while (x != endX || y != endY) {
        if (board[x][y] != nullptr) {
            isPathClear = false;
            break;
        }
        if (x != endX) x += xStep;
        if (y != endY) y += yStep;
    }

    bool isDestinationValid = board[endX][endY] == nullptr || board[endX][endY]->color != this->color;

    return isStraightOrDiagonal && isWithinBounds && isPathClear && isDestinationValid;
}

std::string Queen::symbol() const
{
    return color == Color::White ? "WQ" : "BQ";
}



King::King(Color color) : color(color) {}

bool King::isValidMove(int startX, int startY, int endX, int endY, const std::vector<std::vector<Piece*>>& board) const
{
    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);

    // King moves only one square in any direction
    bool isOneSquare = (dx <= 1 && dy <= 1);
    bool isWithinBounds = endX >= 0 && endX < 8 && endY >= 0 && endY < 8;
    bool isDestinationValid = board[endX][endY] == nullptr || board[endX][endY]->color != this->color;

    if (isOneSquare && isWithinBounds && isDestinationValid)
    {
        //KingX = dx;
        //KingX = dy;
        return true;
    }
    else
        return false;
}

std::string King::symbol() const
{
    return color == Color::White ? "WK" : "BK";
}


Pawn::Pawn(Color color) : color(color) {}

bool Pawn::isValidMove(int startX, int startY, int endX, int endY, const std::vector<std::vector<Piece*>>& board) const
{
    std::cout << "Debug: startX - " << startX << ", startY - " << startY << std::endl;
    std::cout << "Debug: endX - " << endX << ", endY - " << endY << std::endl;

    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);
    std::cout << "dx: " << dx << std::endl;
    std::cout << "dy: " << dy << std::endl;

    int forward = (color == Color::White) ? 1 : -1;  // Direction based on color
    int startRow = (color == Color::White) ? 1 : 6;  // Initial row for two-step move

    // Pawn moves straight forward one square
    bool isMovingForward = (dx == 1 || dx == 2);

    bool isCapture = (dx == dy) && board[endX][endY] != nullptr && board[endX][endY]->color != this->color;

    // Validating moves
    // Pawn moves straight forward one square
    bool isMovingForwardOne = (dx == forward) && (dy == 0) && board[endX][endY] == nullptr;

    // Pawn moves straight forward two squares from the initial row
    bool isInitialDoubleStep = (dx == 2 * forward) && (dy == 0) &&
        board[startX + forward][startY] == nullptr && board[endX][endY] == nullptr;

    // Pawn captures diagonally one square
    bool isCapturing = (std::abs(dy) == 1) && (dx == forward) &&
        board[endX][endY] != nullptr && board[endX][endY]->color != this->color;

    bool isWithinBounds = endX >= 0 && endX < 8 && endY >= 0 && endY < 8;

    return (isMovingForwardOne || isInitialDoubleStep || isCapturing) && isWithinBounds;
}

std::string Pawn::symbol() const
{
    return color == Color::White ? "WP" : "BP";
}