using System;
namespace CheckerApplicaton
{
    class Checker
    {
        static void Main(string[] args)
        {
            string inputStr = Console.ReadLine();
            int a = Convert.ToInt32(inputStr);
            string[] num = Console.ReadLine().Split();
            int wrongAnswer = 0, correctAnswer = Convert.ToInt32(num[0]);
            for (int i = 1; i < num.Length; ++i)
            {
                wrongAnswer = Math.Max(wrongAnswer, Convert.ToInt32(num[i]) - Convert.ToInt32(num[i - 1]));
                correctAnswer = Math.Max(correctAnswer, Convert.ToInt32(num[i]));
            }
            Console.WriteLine(correctAnswer);
            Console.WriteLine(wrongAnswer);
        }
    }
}