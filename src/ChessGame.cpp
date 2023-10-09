//
// Created by 86183 on 2023/10/6.
//

#include "../include/ChessGame.h"

ChessGame::ChessGame(Man *man, AI *ai, Chess *chess) {
  this->man_ = man;
  this->ai_ = ai;
  this->chess_ = chess;

  man->init(chess);
  ai->init(chess);
}

//对局开始
void ChessGame::play() {
  chess_->init();
  while (1) {
    //先由棋手走棋
    man_->go();
    if (chess_->checkOver()) {
      chess_->init();
      continue;
    }
    //ai走棋
    ai_->go();
    if (chess_->checkOver()) {
      chess_->init();
      continue;
    }
  }

}

