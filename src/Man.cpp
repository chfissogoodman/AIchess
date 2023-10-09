//
// Created by 86183 on 2023/10/6.
//

#include "../include/Man.h"
#include <iostream>
void Man::init(Chess *chess) {
  this->chess_ = chess;

}
void Man::go() {
  MOUSEMSG msg;
  ChessPos pos;

  while (1){
    //获取鼠标点击信息
    msg = GetMouseMsg();
    //通过棋盘chess对象来调用 判断落子是否有效 以及落子功能
    if (msg.uMsg==WM_LBUTTONDOWN && chess_->clickBoard(msg.x,msg.y,&pos)){
      break;
    }
  }
//std::cout<<pos.row<<pos.col;
chess_->chessDown(&pos,CHESS_BLACK);



}
