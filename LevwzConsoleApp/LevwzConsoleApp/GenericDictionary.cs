using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace LevwzConsoleApp
{
    
    class GenericDictionary
    {
        public static Dictionary<string, int> CountWords(String text)
        {
            Dictionary<string, int> frequencies;

            frequencies = new Dictionary<string, int>();

            string[] words = Regex.Split(text, @"\W+");

            foreach (string word in words)
            {
                if (frequencies.ContainsKey(word))
                {
                    frequencies[word]++;
                }
                else
                {
                    frequencies[word] = 1;
                }
            }

            return frequencies;
        }

        

        static string ConvertName(string name)
        {
            return string.Format("{0} - {1}", name, "is singing");
        }

        private string GetType<T>(T input)
        {
            return string.Format("{0} - {1}", typeof(T).ToString(), input.GetType().ToString());
        }
    
        public void Test()
        {
            string text = @"Do you like green eggs and ham? 
                            I do not like them, Sam-I-am.
                            I do not like green eggs and ham.";

            Dictionary<string, int> frequencies = CountWords(text);

            foreach(KeyValuePair<string, int> entry in frequencies)
            {
                string word = entry.Key;
                int frequency = entry.Value;
                Console.WriteLine("{0}: {1}", word, frequency);
            }

            List<string> strings = new List<string>();
            strings.Add("Sam");
            strings.Add("Jon");
            strings.Add("Ned");
            strings.Add("Stark");

            List<string> names = strings.ConvertAll(ConvertName);

            foreach(string name in names)
            {
                Console.WriteLine(name);
            }

            Console.WriteLine(GetType<List<string>>(new List<string>()));

            SingletonInstance<LambdaTest> instance1 = SingletonInstance<LambdaTest>.GetInstance();

            instance1.Name = "instance new 1234567890";

            SingletonInstance<LambdaTest> instance2 = SingletonInstance<LambdaTest>.GetInstance();

            Console.WriteLine("{0} - {1}", instance1.GetType().ToString(), instance1.Name);
            Console.WriteLine("{0} - {1}", instance2.GetType().ToString(), instance2.Name);

            LambdaTest inst = SingletonInstance<LambdaTest>.CreateInstance();

            inst.LambdaTests();


        }
    }
    
}
