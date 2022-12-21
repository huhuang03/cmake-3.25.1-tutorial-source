// TODO 1: remove cmath
//#include <cmath>
#include <iostream>

#include "MathFunctions.h"
// TODO 8: include Table.h
#include "Table.h"

// a hack square root calculation using simple operations
double mysqrt(double x)
{
  if (x <= 0) {
    return 0;
  }

// TODO 2: remove origin calc methods
  // if we have both log and exp then use them
//#if defined(HAVE_LOG) && defined(HAVE_EXP)
//  double result = std::exp(std::log(x) * 0.5);
//  std::cout << "Computing sqrt of " << x << " to be " << result
//            << " using log and exp" << std::endl;
//#else
  double result = x;
  // TODO 9: use table to find a initial value.
  if (x >= 1 && x < 10) {
      std::cout << "Using table to help find an initial value " << std::endl;
      result = sqrtTable[static_cast<int>(x)];
  }

  // do ten iterations
  for (int i = 0; i < 10; ++i) {
    if (result <= 0) {
      result = 0.1;
    }
    double delta = x - (result * result);
    result = result + 0.5 * delta / result;
    std::cout << "Computing sqrt of " << x << " to be " << result << std::endl;
  }
// TODO 3: remove endif
//#endif
  return result;
}
