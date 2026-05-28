#include "print.hpp"
#include <sstream>

int main()
{
  std::ostringstream out;
  print("hello", out);
  return out.str() == "hello" ? 0 : 1;
}
