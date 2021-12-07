//algorithm:backtracking

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test
{
    class Program
    {
        private static void NQueens(int num)
        {
            int solutions = 0;
            int[] dx = { -1, -1, -1, 0, 0, 1, 1, 1 };
            int[] dy = { -1, 0, 1, -1, 1, -1, 0, 1 };
            char[,] map = new char[num, num];
            for (int i = 0; i < num; i++) for (int j = 0; j < num; j++) map[i, j] = '*';
            int locx = 0, locy = 0, checkx, checky;
            while (locx >= 0 && locx < num && locy >= 0 && locy < num)
            {
                //Console.WriteLine(locx+","+locy);
                map[locx, locy] = 'Q';
                bool block = false;
                for (int dir = 0; dir < 8; dir++)
                {
                    checkx = locx + dx[dir];
                    checky = locy + dy[dir];
                    while (checkx >= 0 && checkx < num && checky >= 0 && checky < num)
                    {
                        if (map[checkx, checky] == '*')
                        {
                            checkx += dx[dir];
                            checky += dy[dir];
                        }
                        else
                        {
                            block = true;
                            break;
                        }
                    }
                    if (block)
                    {
                        map[locx, locy] = '*';
                        locx++;
                        while (locx == num)
                        {
                            locy--;
                            for (int i = 0; i < num; i++)
                            {
                                if (map[i, locy] == 'Q')
                                {
                                    map[i, locy] = '*';
                                    locx = i + 1;
                                    break;
                                }
                            }
                            //end
                            if (locy == 0 && locx == num)
                            {
                                Console.WriteLine($"{num}Queens solutions:{solutions}");
                                return;
                            }
                        }
                        break;
                    }
                }
                if (!block)
                {
                    locy++;
                    if (locy == num)
                    {
                        solutions++;
                        //print solution
                        for (int i = 0; i < num; i++)
                        {
                            for (int j = 0; j < num; j++)
                            {
                                Console.Write(map[i, j]);
                            }
                            Console.WriteLine("");
                        }
                        Console.WriteLine("--------------------------");
                        //continue to search
                        locy--;
                        map[locx, locy] = '*';
                        locx++;
                        while (locy != 0 && locx == num)
                        {
                            locy--;
                            for (int i = 0; i < num; i++)
                            {
                                if (map[i, locy] == 'Q')
                                {
                                    map[i, locy] = '*';
                                    locx = i + 1;
                                    break;
                                }
                            }
                        }
                    }
                    else locx = 0;
                }
            }
        }
        static void Main(string[] args)
        {
            while (true)
            {
                try
                {
                    Console.Write("Set up your chess size:");
                    NQueens(int.Parse(Console.ReadLine()));
                    break;
                }
                catch
                {
                    Console.WriteLine("This is not a number!!!Try again...");
                }
            }
            Console.ReadKey();
        }
    }
}
