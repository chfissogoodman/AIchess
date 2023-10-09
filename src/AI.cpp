//
// Created by 86183 on 2023/10/6.
//

#include "../include/AI.h"
void AI::init(Chess *chess) {
  this->chess_1_ = chess;
  int size = chess->getGradeSize();//duima ?
  for (int i = 0; i < size; i++) {
    vector<int> row;
    for (int j = 0; j < size; j++) {
      row.push_back(0);
    }
    scoreMap_.push_back(row);
  }
}
void AI::go() {
  ChessPos pos = think();
  Sleep(1000);//假装思考
  chess_1_->chessDown(&pos, CHESS_WHITE);

}
void AI::calculateScore() {
  int personNum = 0;
  int aiNum = 0;
  int emptyNum = 0;

  //评分向量数组清零
  for (int i = 0; i < scoreMap_.size(); ++i) {
    for (int j = 0; j < scoreMap_.size(); ++j) {
      scoreMap_[i][j] = 0;
    }
  }

  int size = chess_1_->getGradeSize();
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
//      personNum = 0;
//      aiNum = 0;
//      emptyNum = 0;

      //对每个点进行计算
      if (chess_1_->getChessData(row, col)) continue;
//控制8个方向
      for (int y = -1; y <= 0; y++) {
        for (int x = -1; x <= 1; x++) {
          if (y == 0 && x == 0) continue;
          if (y == 0 && x != 1) continue;

          personNum = 0;
          aiNum = 0;
          emptyNum = 0;

          //假设黑棋在该位置落子，会构成什么棋型
          for (int i = 1; i <= 4; i++) {
            int curRow = row + i * y;
            int curCol = col + i * x;
            if (curRow >= 0 && curRow < size &&
                curCol >= 0 && curCol < size &&
                chess_1_->getChessData(curRow, curCol) == 1) {
              personNum++;
            } else if (curRow >= 0 && curRow < size &&
                curCol >= 0 && curCol < size &&
                chess_1_->getChessData(curRow, curCol) == 0) {
              emptyNum++;
              break;
            } else {
              break;

            }
          }
          //方向继续计算
          for (int i = 1; i <= 4; i++) {
            int curRow = row - i * y;
            int curCol = col - i * x;

            if (curRow >= 0 && curRow < size &&
                curCol >= 0 && curCol < size &&
                chess_1_->getChessData(curRow, curCol) == 1) {
              personNum++;
            } else if (curRow >= 0 && curRow < size &&
                curCol >= 0 && curCol < size &&
                chess_1_->getChessData(curRow, curCol) == 0) {
              emptyNum++;
              break;
            } else {
              break;

            }
          }

          if (personNum == 1) {//连2

            scoreMap_[row][col] += 10;
          } else if (personNum == 2) {
            if (emptyNum == 1) {
              scoreMap_[row][col] += 30;
            } else if (emptyNum == 2) {
              scoreMap_[row][col] += 40;
            }
          } else if (personNum == 3) {
            if (emptyNum == 1) {
              scoreMap_[row][col] += 60;//?
            } else if (emptyNum == 2) {
              scoreMap_[row][col] += 200;
            }
          } else if (personNum == 4) {
            scoreMap_[row][col] += 20000;
            // 进行一次清空
            //假设黑棋在该位置落子，会构成什么棋型
            emptyNum = 0;

            for (int i = 1; i <= 4; ++i) {
              int curRow = row + i * y;
              int curCol = col + i * x;
              if (curRow > 0 && curRow < size &&
                  curCol > 0 && curCol < size &&
                  chess_1_->getChessData(curRow, curCol) == -1
                  ) {
                aiNum++;
              } else if (curRow > 0 && curRow < size &&
                  curCol > 0 && curCol < size &&
                  chess_1_->getChessData(curRow, curCol) == 0
                  ) {
                emptyNum++;
                break;
              } else {
                break;
              }
            }
            for (int i = 1; i <= 4; ++i) {
              int curRow = row - i * y;
              int curCol = col - i * x;
              if (curRow > 0 && curRow < size &&
                  curCol > 0 && curCol < size &&
                  chess_1_->getChessData(curRow, curCol) == -1
                  ) {
                aiNum++;
              } else if (curRow > 0 && curRow < size &&
                  curCol > 0 && curCol < size &&
                  chess_1_->getChessData(curRow, curCol) == 0
                  ) {
                emptyNum++;
                break;
              } else {
                break;
              }
            }
            if (aiNum == 0) {
              scoreMap_[row][col] += 5;
            } else if (aiNum == 1) {
              scoreMap_[row][col] += 10;
            } else if (aiNum == 2) {
              if (emptyNum == 1) {
                scoreMap_[row][col] += 25;
              } else if (emptyNum == 2) {
                scoreMap_[row][col] += 50;
              }
            } else if (aiNum == 3) {
              if (emptyNum == 1) {
                scoreMap_[row][col] += 55;
              } else if (emptyNum == 2) {
                scoreMap_[row][col] += 10000;
              }
            } else if (aiNum >= 4) {
              scoreMap_[row][col] += 30000;
            }
          }
        }
      }

    }
  }

}
ChessPos AI::think() {
  calculateScore();
  int maxScore = 0;
  int size = chess_1_->getGradeSize();
  vector<ChessPos> maxPoints;
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      if (chess_1_->getChessData(row, col) == 0) {//说明没有棋子
        if (scoreMap_[row][col] > maxScore) {

          maxScore = scoreMap_[row][col];
          maxPoints.clear();
          maxPoints.push_back(ChessPos(row, col));
        } else if (scoreMap_[row][col] == maxScore) {
          maxPoints.push_back(ChessPos(row, col));
        }
      }
    }
  }

  int index = rand() % maxPoints.size();
  return maxPoints[index];
}
