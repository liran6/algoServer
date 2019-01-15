//
// Created by liran-baruch on 1/15/19.
//

#ifndef UNTITLED6_GRATER_H
#define UNTITLED6_GRATER_H

#include "State.h"

template<typename N>

    struct Greater
    {
      bool operator()(State<N> x, State<N> y) const
      { return x.getCost() > y.getCost(); }
    };
#endif //UNTITLED6_GRATER_H
