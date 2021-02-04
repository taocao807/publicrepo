#include <iostream>
#include <vector>

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
    if (b == 10) return std::to_string(n);

    std::string result;
    int count = 0;
    while (count < 6)
    {
      int rem = n%b;
      result = std::to_string(rem) + result;
      n = n/b; 
      count++;
    }

    return result;
}


int main(int argc, char** argv)
{
    vector<int> result;
    result.push_back(1);
    result.push_back(2);
    int N = 729;
    int Base = 10;
    if (argc > 1)
    {
        N = std::stoi(argv[1]);
    }
    int M = 0;
    if (argc > 2) {
        int n = std::atoi(argv[2]);
        if (n == -3) Base = 3;
        if (n > 0) M = n;
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
        std::string v = numberInBase(result[i], Base);
        std::cout << v << " " ;
       
        if (i%8 == 0 && i != 0) std::cout << std::endl; 
    }

    std::cout << std::endl;
    return 0;
}
