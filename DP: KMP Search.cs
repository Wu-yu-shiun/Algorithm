//find substring

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test
{
    class Program
    {
        private static int[] PSArray(string input)
        {
            int num = 0;
            int[] result = new int[input.Length];
            result[0] = -1;
            result[1] = 0;
            for(int i = 1; i < input.Length-1; i++)
            {
                if (input[i] != input[num])
                {
                    result[i+1] = 0;
                    num = 0;
                }
                else
                {
                    num++;
                    result[i + 1] = num;               
                }
            }
            return result;
        }

        private static int KMP(string str1, string str2)
        {
            int i = 0,j = 0,counter = 0;
            int[] ps2 = PSArray(str2);
            while (i < str1.Length)
            {
                if (str1[i] == str2[j])
                {
                    if (j == str2.Length - 1)
                    {
                        j = 0;
                        counter++;
                    }
                    else j++;
                    i++;
                }
                else
                {
                    i -= ps2[j];
                    j = 0;
                }
            }
            return counter;
        }

        static void Main(string[] args)
        {
            Console.Write("String1: ");
            string str1 = Console.ReadLine();
            Console.Write("String2: ");
            string str2 = Console.ReadLine();
            Console.Write("How many substring(string2) in string1: "+KMP(str1,str2));
            Console.ReadKey();
        }
    }
}
