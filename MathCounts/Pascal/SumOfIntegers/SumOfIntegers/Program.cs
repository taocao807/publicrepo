using System;

namespace SumOfDistinctIntegers
{
    class Program
    {
        static int count = 0;
        static void Main(string[] args)
        {
            int N = 9;
            int n = 3;
            bool distinct = true;

            if (args.Length > 0)
            {
                int i = 0;
                while (i < args.Length)
                {
                    if (args[i] == "-N" || args[i] == "--N")
                    {
                        if (i + 1 < args.Length)
                        {
                            N = Convert.ToInt32(args[i + 1]);
                        }
                    }

                    if (args[i] == "-n" || args[i] == "--n")
                    {
                        if (i + 1 < args.Length)
                        {
                            n = Convert.ToInt32(args[i + 1]);
                        }
                    }

                    if (args[i] == "--distinct" || args[i] == "-distinct")
                    {
                        if (i < args.Length - 1)
                        distinct = Boolean.Parse(args[i+1]);
                    }
                    i++;
                }
            }

            if (N <= 0 || n <=0)
            {
                Console.WriteLine("Invalid inputs.");
                return;
            }

            if (distinct)
            {
                Console.WriteLine($"In how many ways can {N} be written as the sume of {n} distinct positive integers?");
            }
            else
            {
                Console.WriteLine($"In how many ways can {N} be written as the sume of {n} positive integers?");
            }

            int[] result = new int[n];
            for (int i = 0; i < n; i++)
            {
                result[i] = 0;
            }

            for (int i = 1; i <= N - n; i++)
            {
                result[0] = i;
                Builder(1, N-i, n-1, result, distinct);
            }
        }

        static void Builder(int start, int N, int n, int[] result, bool distinct)
        {
            if (start == result.Length - 1)
            {
                result[start] = N;
                bool valid = true;
                if (start > 1)
                {
                    valid = distinct ? result[start] > result[start - 1] : result[start] >= result[start - 1];
                }

                if (valid)
                {
                    Console.Write($"{count + 1} :");
                    count++;
                    for (int i = 0; i < result.Length; i++)
                    {
                        Console.Write(result[i]);
                        if (i < result.Length -1 )
                        {
                            Console.Write(", ");
                        }
                    }
                    Console.WriteLine();
                }

                return;
            }

            int next = distinct ? result[start - 1] + 1 : result[start - 1];
            if (N - next < 0) return;

            for (int i = next; i < N - next; i++)
            {
                result[start] = i;
                Builder(start + 1, N - i, n - 1, result, distinct);
            }
        }
    }
}
