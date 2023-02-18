#include <iostream>
#include "src/core/tile.h"


int main(){
    attrClass A;
    A.NewAttr(123,321);
    int a;
    std::cout << A.GetAttr(123);
}

