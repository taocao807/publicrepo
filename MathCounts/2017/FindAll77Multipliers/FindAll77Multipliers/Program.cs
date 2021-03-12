using System;
using System.Collections.Generic;

namespace FindAll77Multipliers
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> result = new List<int>();
            int count = 1;
            for (int i4 = 0; i4 <= 1; i4++)
            {
                for (int i3 = 0; i3 <= 1; i3++)
                {
                    for (int i2 = 0; i2 <= 1; i2++)
                    {
                        for (int i1 = 0; i1 <= 1; i1++)
                        {
                            for (int i0 = 0; i0 <= 1; i0++)
                            {
                                int n = 700000 + i4 * 70000 + i3 * 7000 + i2 * 700 + i1 * 70 + i0 * 7;
                                if (n%77 == 0)
                                {
                                    Console.WriteLine($"{count}: {n} = {n/77} * 77");
                                    count++;
                                }
                            }
                        }

                    }

                }
            }
            Console.ReadLine();
        }
    }
}
