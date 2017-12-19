using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LevwzConsoleApp
{
    delegate void voidDelegate(string input);
    delegate int ConvertSum<T, X>(T input1, X input2);
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

        public int Sum<X, Y>(X x, Y y) 
        {
            if (typeof(X).Equals(typeof(int)) && typeof(Y).Equals(typeof(int)))
            {
                return 1;
            }
            return 0;
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
   
    public class GameInfo: EventArgs
    {
        public GameInfo(string name)
        {
            Name = name;
            Console.WriteLine($"The game name is {Name}");
        }
        public string Name { get; }
    }

    public class Publisher
    {
        public event EventHandler<GameInfo> Notify;
        
        public void PublishNewGame(string name)
        {            
            Console.WriteLine($"We are pleased to announce the new game {name}");
            Notify?.Invoke(this, new GameInfo(name));
        }

        public Publisher(string name)
        {
            Name = name;
        }

        public string Name { get; }
    }

    public class Player
    {
        public void Subscribe(object o, GameInfo e)
        {
            Console.WriteLine($"{Name} says {e.Name} published by {((Publisher)o).Name} is awesome");
        }

        public Player(string name)
        {
            Name = name;
        }

        public string Name { get; }
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

            Publisher pub = new Publisher("Activation");

            Player p1 = new Player("zhouwei");

            pub.Notify += p1.Subscribe;

            pub.PublishNewGame("COD 4, Morden warfare");

            Player p2 = new Player("dengmin");

            pub.Notify += p2.Subscribe;

            pub.PublishNewGame("COD6, Morden warfare II");

            Player p3 = new Player("winner");

            pub.Notify -= p2.Subscribe;
            pub.Notify += p3.Subscribe;

            pub.PublishNewGame("COD8, Infinte warfare");

            
        }
    }
}
