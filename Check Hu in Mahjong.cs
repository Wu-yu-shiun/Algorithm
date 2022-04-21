//麻將胡牌演算法

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test
{
    class Program
    {
        public static bool findHu;
        public static void FindSolution(List<int> checkList)
        {
            if (!checkList.Any())
            {
                findHu = true;
                return;
            }
            else
            {
                if (checkList.FindAll(x => x == checkList[0]).Count <= 2)
                {
                    if (checkList.Contains(checkList[0] + 1) && checkList.Contains(checkList[0] + 2))
                    {
                        int[] temp = { checkList[0], checkList[0]+1, checkList[0]+2};
                        for (int i = 0; i < 3; ++i) checkList.Remove(temp[i]);
                        FindSolution(checkList);

                    }
                    else return;

                }
                else
                {
                    for (int i = 0; i < 3; ++i) checkList.Remove(checkList[0]);
                    FindSolution(checkList);
                }
            }
        }

        static void Main(string[] args)
        {
            while (true)
            {
                findHu=false;
                Console.Write("輸入手牌代號(1-9為萬,11-19為筒,21-29條,31-37為東西南北中發白,總數3n+2,以逗號區隔):");
                string input = Console.ReadLine();
                string[] str = input.Split(',');
                List<int> bagList = new List<int>();
                try
                {
                    bool numberformat = true;
                    for (int i = 0; i < str.Length; ++i)
                    {
                        int num = int.Parse(str[i]);
                        if (num < 1 || num > 37 || num == 10 || num==20|| num == 30)
                        {
                            numberformat = false;
                            Console.WriteLine("輸入麻將代號錯誤 重新輸入!");
                            break;
                        }
                        bagList.Add(num);
                    }
                    if (!numberformat) continue;
                }
                catch
                {
                    Console.WriteLine("輸入格式錯誤 重新輸入!");
                    continue;
                }
                if ((bagList.Count-2)%3!=0)
                {
                    Console.WriteLine("輸入麻將個數錯誤 重新輸入!");
                    continue;
                }
                bagList.Sort();

                //找出最後一對可能解 
                List<int> pairList = new List<int>();
                for (int i = 1; i <=37; ++i)
                {
                    if (bagList.FindAll(x => x == i).Count >= 2)
                    {
                        pairList.Add(i);
                    }
                }

                //剩下3n張找解
                for (int i = 0; i < pairList.Count; ++i)
                {
                    List<int> checkList = new List<int>();
                    for (int j = 0; j < bagList.Count; ++j) checkList.Add(bagList[j]);
                    checkList.Remove(pairList[i]);
                    checkList.Remove(pairList[i]);
                    FindSolution(checkList);
                    if (findHu)
                    {
                        break;
                    }
                }
                Console.Write("是否有找到胡:" + findHu);
                Console.ReadKey();
            }
        }
    }
}
