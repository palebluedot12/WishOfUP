#pragma once

namespace Utility
{
    std::vector<int> SplitStringtoInt(std::string origin, const std::string& tok);
    std::vector<std::string> SplitStringtoString(std::string origin, const std::string& tok);
    std::pair<int, int> SplitStringtoPairInt(std::string origin, const std::string& tok);
}