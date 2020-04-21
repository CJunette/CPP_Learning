using System;

namespace _3._6_RefParameterTest
{
    class Program
    {
        static void Main(string[] args)
        {
            int x = 100;

            Plus(ref x);

            Console.WriteLine(x);
        }

        static void Plus(ref int x)
        {
            ++x;
        }
    }
}
