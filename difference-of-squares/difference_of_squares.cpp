#include "difference_of_squares.h"
#include <iostream>

unsigned int squares::square_of_sums(int n){
  // Using Gauss Solution
  //
  //       n (n+1)
  // Sn = ---------
  //          2
  const auto Sn = (n*(n+1))>>1;
  return Sn*Sn;
}
unsigned int squares::sum_of_squares(int n){
  // Using Gauss Solution
  //
  //           n(n+1)(2n+1)
  // S(n^2) = --------------
  //                6
  return (n*(n+1)*((2*n)+1))/6;
}
unsigned int squares::difference(int n){
  return square_of_sums(n) - sum_of_squares(n);
}
