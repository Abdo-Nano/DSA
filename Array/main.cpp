

#include <iostream>
#include <functional>
#include "Array.h"
#include <vector>
#include "Problems.h"
#include <memory>
#include <limits>




int main()
{

   std::function<int(int , int)>lambda = [] (int first , int second)->int {return first + second;};

   std::cout << lambda(10 , 30) << std::endl;



}