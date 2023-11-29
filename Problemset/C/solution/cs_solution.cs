using System;
namespace CheckerApplication
{
    class Checker
    {
        static void Main()
        {
            string[] inputStr = Console.ReadLine().Split();
            int n = Convert.ToInt32(inputStr[0]);
            int m = Convert.ToInt32(inputStr[1]);
            inputStr = Console.ReadLine().Split();
            int[] height = new int[n];
            for (int i = 0; i < n; ++i)
            {
                height[i] = Convert.ToInt32(inputStr[i]);
            }
            Array.Sort(height);
            inputStr = Console.ReadLine().Split();
            for (int k = 0; k < m; ++k)
            {
                int variable = Convert.ToInt32(inputStr[k]);
                int ans = 0;
                for (int i = 0, j = 0; j < n; ++j)
                {
                    while (i <= j && height[j] - height[i] > variable)
                    {
                        i++;
                    }
                    ans += j - i;
                }
                Console.WriteLine(ans);
            }
        }
    }
}