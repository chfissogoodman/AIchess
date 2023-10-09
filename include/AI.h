//
// Created by 86183 on 2023/10/6.
//

#pragma once
#include "Chess.h"

class AI {
 public:
  void init(Chess *chess);
  void go();

 private:
  Chess *chess_1_;
  vector<vector<int>> scoreMap_;
 private:
  void calculateScore();
  ChessPos think();

};

