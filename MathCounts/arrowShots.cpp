#include <iostream>

int main()
{
    for (int i40 = 0; i40 <3; ++i40)
    {
        for (int i29 = 0; i29 <= 4; ++i29)
        {
            for (int i26 = 0; i26 <= 4; ++i26) 
            {
                for (int i23 = 0; i23 <= 4; ++i23) 

                for (int i17 = 0; i17 <= 5; ++i17) 

                for (int i16 = 0; i16 <= 5; ++i16) 
                {
                    if (i40*40 + i29*29 + i26*26 + i23*23 + i17*17 + i16*16 > 100) continue;

                    if (i40*40 + i29*29 + i26*26 + i23*23 + i17*17 + i16*16 == 100) 
                    {
                        int shots = i40 + i29 + i26 + i23 + i17 + i16;
                        std::cout << "shots: " << shots << " 40: " << i40 << " 29: " << i29 << " 26: " << i26 << " 23: " << i23 << " 17: " << i17 << " 16: " << i16 << std::endl;
                        continue;
                    }
                }
            }
        }

    }
}
