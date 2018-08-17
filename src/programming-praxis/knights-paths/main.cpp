#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_map>

struct Position {
  Position(std::size_t r, std::size_t c) : row(r), col(c) {}
  std::size_t row;
  std::size_t col;
};

using BoardCache = std::vector<std::vector<std::unordered_map<std::size_t, std::size_t>>>;

BoardCache new_board_cache(std::size_t board_size) {
  BoardCache b(board_size);
  for (std::size_t i = 0; i < board_size; ++i) {
    b[i] = std::vector<std::unordered_map<std::size_t, std::size_t>>(board_size);
  }
  return b;
}

std::size_t recursive_moves_helper(std::size_t n, std::size_t board_size, const Position& p, BoardCache& m) {
  if (n <= 0) return 0;
  auto& lookup = m[p.row][p.col];

  // Check cache
  if (lookup.find(n) != lookup.end()) return lookup[n];

  std::size_t up_left = 0;
  std::size_t up_right = 0;
  std::size_t down_left = 0;
  std::size_t down_right = 0;
  // Move left
  if (p.col>= 2) {
    // Move up
    if (p.row >= 1) {
      up_left = 1 + recursive_moves_helper(n-1, board_size, Position{p.row-1, p.col-2}, m);
    }
    // Move down
    if (p.row < board_size - 1) {
      down_left = 1 + recursive_moves_helper(n-1, board_size, Position{p.row+1, p.col-2}, m);
    }
  }

  // Move right
  if (p.col < board_size - 2) {
    // Move up
    if (p.row >= 1) {
      up_right = 1 + recursive_moves_helper(n-1, board_size, Position{p.row-1, p.col+2}, m);
    }
    // Move down
    if (p.row < board_size - 1) {
      down_right = 1 + recursive_moves_helper(n-1, board_size, Position{p.row+1, p.col+2}, m);
    }
  }

  auto total = up_left + up_right + down_left + down_right;
  lookup[n] = total;
  return total;
}

/**
 * Calculate the number of knights moves for a square board of size `board_size`
 * of length `n`, where a single, legal move of a knight has length 1.
 */
std::size_t knights_moves(std::size_t board_size, std::size_t n) {
  BoardCache b = new_board_cache(board_size);
  Position start_pos{0, 0};
  return recursive_moves_helper(n, board_size, start_pos, b);
}


int main() {
  auto start = std::chrono::steady_clock::now();
  std::cout << "Number of length 15 moves on a 10x10 board: " << knights_moves(15, 10);
  auto stop = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed = stop - start;
  std::cout << " in " << elapsed.count() << "s\n";
  start = std::chrono::steady_clock::now();
  std::cout << "Number of length 15 moves on a 15x15 board: " << knights_moves(15, 15);
  stop = std::chrono::steady_clock::now();
  elapsed = stop - start;
  std::cout << " in " << elapsed.count() << "s\n"; 
  return 0;
}
