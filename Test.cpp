//
// Created by netanel & Or on 6/16/2020.
//

#include "doctest.h"


TEST_CASE("Simple Test"){
    for (int i = 0 ;i <100;i++){
        CHECK(i==i);
    }
}