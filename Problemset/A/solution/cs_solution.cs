using System;
namespace CheckerApplication
{
    class Checker
    {
        static void Main(string[] args)
        {
            string inputStr = null;
            inputStr = Console.ReadLine();
            int idx = inputStr.IndexOf("nnsz");
            if (idx >= 0)
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }
        }
    }
}
