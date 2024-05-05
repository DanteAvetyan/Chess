#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <string>
#include <cmath>
#include <iostream>

enum class Color { White, Black };

class Piece
{
public:
    virtual ~Piece() {}
    virtual bool isValidMove(int startX, int startY, int endX, int endY, const std::vector<std::vector<Piece*>>& board) const = 0;
    virtual std::string symbol() const = 0;
public:
    Color color;
};

class Knight : public Piece
{
public:
    Knight(Color color);
    bool isValidMove(int startX, int startY, int endX, int endY, const std::vector<std::vector<Piece*>>& board) const override;
    std::string symbol() const override;
public:
    Color color;
};

class Rook : public Piece
{
public:
    Rook(Color color);
    bool isValidMove(int startX, int startY, int endX, int endY, const std::vector<std::vector<Piece*>>& board) const override;
    std::string symbol() const override;
public:
    Color color;
};

class Bishop : public Piece
{
public:
    Bishop(Color color);
    bool isValidMove(int startX, int startY, int endX, int endY, const std::vector<std::vector<Piece*>>& board) const override;
    std::string symbol() const override;
public:
    Color color;
};

class Queen : public Piece
{
public:
    Queen(Color color);
    bool isValidMove(int startX, int startY, int endX, int endY, const std::vector<std::vector<Piece*>>& board) const override;
    std::string symbol() const override;
public:
    Color color;
};

class King : public Piece
{
public:
    King(Color color);
    bool isValidMove(int startX, int startY, int endX, int endY, const std::vector<std::vector<Piece*>>& board) const override;
    std::string symbol() const override;
public:
    Color color;
};

class Pawn : public Piece
{
public:
    Pawn(Color color);
    bool isValidMove(int startX, int startY, int endX, int endY, const std::vector<std::vector<Piece*>>& board) const override;
    std::string symbol() const override;
public:
    Color color;
};

#endif