//
// Created by 86183 on 2023/10/6.
//
#pragma once
#include "Man.h"
#include "AI.h"
#include "Chess.h"
class ChessGame {

 public:
  ChessGame(Man*man,AI*ai,Chess*chess);
  void play();//开始对局
//添加数据成员
 private:
  Man* man_;
  AI* ai_;
  Chess* chess_;
};

