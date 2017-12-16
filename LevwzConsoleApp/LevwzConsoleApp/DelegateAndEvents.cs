using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LevwzConsoleApp
{
    delegate void voidDelegate(string input);
    class DelegateAndEvents
    {
        public void VoidMethod(string input)
        {
            Console.WriteLine("input: {0}", input);
        }

        public void Test()
        {
            TestEventHandler();
            string[] strings = new string[5];
            object[] objects = strings;

            
            objects[0] = new Int64().ToString();


        }

        static void HandleDemoEvent(object sender, EventArgs e)
        {
            Console.WriteLine("Handled by HandleEemoEvent");
        }
        

        private void TestEventHandler()
        {
            EventHandler handler;
            handler = new EventHandler(HandleDemoEvent);
            handler(null, EventArgs.Empty);

            handler = HandleDemoEvent;
            handler(null, EventArgs.Empty);

            handler = delegate (object sender, EventArgs e)
            {
                Console.WriteLine("Handled anonymously");
            };

            handler(null, EventArgs.Empty);

            handler = delegate
            {
                Console.WriteLine("Handled anonymously simplified");
            };

            handler(null, EventArgs.Empty);

            
        }
       
    }

    class LambdaTest
    {
        public void LambdaTests()
        {
            Func<int, int, int> func = (x, y) => (x * y);

            Console.WriteLine ("{0}*{1}={2}", 1, 2, func(1, 2));
        }
    }

    class AnonymousTest
    {
        public void Test()
        {
            var jon = new { Name = "Jon", Age = 31 };
            var tom = new { Name = "Tom", Age = 4 };
            Console.WriteLine("{0} is {1}", jon.Name, jon.Age);
            Console.WriteLine("{0} is {1}", tom.Name, tom.Age);
        }
    }
   

    class DelegateEventsTest
    {
        public void Test()
        {
            AnonymousTest at = new AnonymousTest();
            at.Test();
            LambdaTest lt = new LambdaTest();
            lt.LambdaTests();
            DelegateAndEvents dae = new DelegateAndEvents();
            voidDelegate vd = new voidDelegate(dae.VoidMethod);

            vd("test delegate again");

            dae.Test();

            
        }
    }
}
