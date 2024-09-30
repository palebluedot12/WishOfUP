#include "Framework.h"

std::vector<int> Utility::SplitStringtoInt(std::string origin, const std::string& tok)
{
    std::vector<int> result;
    std::string temp = origin;
    size_t cutAt = 0;

    while ((cutAt = temp.find_first_of(tok)) != std::string::npos)
    {
        if (cutAt > 0)
        {
            result.push_back(std::stoi(temp.substr(0, cutAt)));
        }
        temp = temp.substr(cutAt + 1);
    }

    if (temp.size() > 0)
    {
        result.push_back(std::stoi(temp));
    }

    return result;
}
std::vector<std::string> Utility::SplitStringtoString(std::string origin, const std::string& tok)
{
    std::vector<std::string> result;
    std::string temp = origin;
    size_t cutAt = 0;

    while ((cutAt = temp.find_first_of(tok)) != std::string::npos)
    {
        if (cutAt > 0)
        {
            result.push_back(temp.substr(0, cutAt));
        }
        temp = temp.substr(cutAt + 1);
    }

    if (temp.size() > 0)
    {
        result.push_back(temp);
    }

    return result;
}
std::pair<int, int> Utility::SplitStringtoPairInt(std::string origin, const std::string& tok)
{
    std::vector<std::string> result;
    std::string temp = origin;
    size_t cutAt = 0;

    while ((cutAt = temp.find_first_of(tok)) != std::string::npos)
    {
        if (cutAt > 0)
            result.push_back(temp.substr(0, cutAt));

        temp = temp.substr(cutAt + 1);
    }

    if (temp.size() > 0)
        result.push_back(temp);

    if (result.size() != 2) {
        // 예외 처리: 분리된 문자열의 개수가 2가 아니면 오류 처리 (여기서는 기본값 반환)
        return std::make_pair(0, 0);
    }

    int first = std::stoi(result[0]);
    int second = std::stoi(result[1]);

    return std::make_pair(first, second);
}