#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

bool isNext(int n, int M, vector<int>& result)
{
    for (size_t i = result.size()-1; i > 0; --i)
    {
        int diff = n - result[i];
        for (size_t j = 0; j < i; ++j)
        {
            if (result[i] - result[j] == diff)
            {
                if (M == n)
                {
                     std::cout << result[j]  << ", " << result[i] << ", and " << n << " form an arithmetic sequence." << std::endl;
                }
                return false;
            }
        }
    }
    
    return true;
}

std::string numberInBase(int n, int b)
{
    std::string result;
    if (n == 0) return "0";

    int count = 0;
    while (count < 6)
    {
      if (n == 0) {
         return result;
      }

      int rem = n%b;
      result = std::to_string(rem) + result;
      n = n/b; 
      count++;
    }

    return result;
}


int main(int argc, char* argv[])
{
    vector<int> result;
    result.push_back(1);
    result.push_back(2);
    int N = 729;
    int Base = 10;
    bool subtract = false;
    int M = 0;

    for (int i = 1; i < argc; ++i)
    {
        if (std::string(argv[i]) == "-upper" && i+1 < argc)
        {
            N = std::stoi(argv[i+1]);
        }
        else if (std::string(argv[i]) == "-base" && i < argc -1)
        {
            Base = std::stoi(argv[i+1]);
        }
        else if (std::string(argv[i]) == "-subtract")
        {
            subtract = true;
        }
        else if (std::string(argv[i]) == "-check" && i+1 < argc)
        {
            M = std::stoi(argv[i+1]);
        }
    }

    for (int i = 3; i <= N; ++i)
    {
        bool canAdd = isNext(i, M, result);
        if (canAdd) result.push_back(i);
    }

    if (M > 0) return 0;

    std::cout << "Number of terms: " << result.size() << std::endl;

    for (size_t i = 0; i < result.size(); ++i)
    {
        if (i != 0 && i%8 == 0) std::cout << std::endl;

        int n = subtract ? result[i] - 1 : result[i];
        std::string v = numberInBase(n, Base);
        if (Base == 10) 
        {
            std::string w("      ");
            w = w.substr(0, 6-v.length()) + v;
            std::cout << w;
        }
        else
        {
            std::string w("000000");
            w = w.substr(0, 6-v.length()) + v;
            std::cout << w << " ";
        }
    }

    std::cout << std::endl;
    return 0;
}

