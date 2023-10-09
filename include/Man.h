//
// Created by 86183 on 2023/10/6.
//

#pragma once
#include "Chess.h"
class Man {
 public:
  void init(Chess *chess);
  void go();

 private:
  Chess *chess_;
};

