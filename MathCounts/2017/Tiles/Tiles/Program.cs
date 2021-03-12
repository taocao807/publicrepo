using System;
using System.Collections.Generic;

namespace Tiles
{
    public class Tile
    {
        public char letter { get; set; }
        public int number { get; set; }

        public Tile (char c, int i)
        {
            letter = c;
            number = i;
        }

    }

    class Program
    {
        private static Random rng = new Random();

        static void Main(string[] args)
        {
            Trial();
        }

        static bool Trial()
        {
            char[] letters = { 'A', 'B', 'C', 'D', 'E' };
            int[] numbers = { 1, 2, 3, 4, 5 };
            List<Tile> pile = new List<Tile>();
            for (int i = 0; i < letters.Length; i++)
            {
                for (int j = 0; j < numbers.Length; j++)
                {
                    pile.Add(new Tile(letters[i], numbers[j]));
                }
            }

            Shuffle(pile);

            var tile0 = pile[0];
            var tile1 = pile[1];
            var tile2 = pile[2];

            Console.WriteLine($"1: {tile0.letter}{tile0.number}, 2: {tile1.letter}{tile1.number}, 3: {tile2.letter}{tile2.number}");

            if ((InCommon(tile0, tile1) || InCommon(tile0, tile2)) && 


            return true;
        }

        static bool InCommon(Tile t1, Tile t2)
        {
            if (t1.letter == t2.letter || t1.number == t2.number)
            {
                return true;
            }

            return false;
        }

        public static void Shuffle<T>(IList<T> list)
        {
            int n = list.Count;
            while (n > 1)
            {
                n--;
                int k = rng.Next(n + 1);
                T value = list[k];
                list[k] = list[n];
                list[n] = value;
            }
        }
    }
}
