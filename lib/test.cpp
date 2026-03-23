#include "matrix.hpp"

#include <iostream>

int main(void)
{
   math::matrix<int> m1{{1,1},{1,2}};
   math::matrix<int> m2{{1,1},{1,2},{1,3}};
   math::matrix<int> m3=m2.getSubMatrix(1, 1);
   std::cout << m3;
}