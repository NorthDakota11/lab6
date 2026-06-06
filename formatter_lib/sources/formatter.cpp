#include "formatter.hpp"

#include <string>

std::string format_text(const std::string& text)
{
    return "----------\n" + text + "\n----------";
}
