using System;
namespace LevwzConsoleApp
{
    public static class ExtensionsClass
    {
        public static int GetCharactersCount(this string s){
            return (null != s) ? s.Split().Length : 0;
        }

        public static Boolean GetOppositeValue(this Boolean b){
            return !b;
        }

        public static string AppendToTail(this string s, string x){
            return s + x;
        }

        //public static string ThisMustBeThe1stParam(int x, this string s){
        //    //the default parameter this must be the first. 
        //}
    }

    public class ExtensionClass{
        public void Test(){
            Console.WriteLine("I am a string instance, guess i am composed by how many words?".GetCharactersCount());

            Console.WriteLine("oppsite True is " + true.GetOppositeValue());

            Console.WriteLine("Head ".AppendToTail("Tail"));
        }
    }
}
