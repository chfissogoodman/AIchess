//
// Created by 86183 on 2023/10/6.
//
#pragma once
#include <graphics.h>
#include <vector>
using namespace std;
//表示落子位置
struct ChessPos {
  int row;
  int col;

  ChessPos(int r=0,int c=0):row(r),col(c){}

};
typedef enum {
  CHESS_WHITE = -1,//白棋
  CHESS_BLACK = 1
} chess_kind_t;

class Chess {
 public:
  Chess(int gradeSize,int marginX,int marginY,float chessSize);



  void init();
  bool clickBoard(int x, int y, ChessPos *pos);
  void chessDown(ChessPos *pos, chess_kind_t kind);
  int getGradeSize();//获取棋牌大小（13,15,19）
  bool checkOver();//检查棋局是否结束
  int getChessData(ChessPos *pos);
  int getChessData(int row, int col);


 private:
  IMAGE chessBlackImg;//黑棋子
  IMAGE chessWhiteImg;//白

  int gradeSize_;//棋盘大小
  int margin_x_;//棋盘左边界
  int margin_y_;//上边界
  float chessSize_;//旗子大小（棋盘方格大小）
 vector<vector<int>> chessMap;//存储当前棋局的棋子分布数据 0；空白 1；黑子 -1:白子
 //表示现在轮到谁下棋
 bool playerFlag;//true:黑 false：白

  void updateGameMap(ChessPos*pos);

  bool checkWin();//如果胜负已分 就返回true

  ChessPos lastPos;


};

