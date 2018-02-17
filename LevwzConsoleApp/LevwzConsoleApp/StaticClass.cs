using System;
namespace LevwzConsoleApp
{
    public static  class StaticClass
    {
        public static ConsoleColor cc;
        static StaticClass()
        {
            cc = ConsoleColor.Blue;   
        }
    }
}
