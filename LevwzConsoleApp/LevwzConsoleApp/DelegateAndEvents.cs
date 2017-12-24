using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
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

    
    public class GamePublisher
    {
        private class WeakDelegate
        {
            public WeakReference Target;
            public MethodInfo Method;
        }
        public event EventHandler<GameInfo> Subscribe;
        

        private List<WeakDelegate> weakSubscribers = new List<WeakDelegate>();
        public event EventHandler<GameInfo> WeakSubscribe
        {
            add
            {
                weakSubscribers.Add(new WeakDelegate
                {
                    Target = new WeakReference(value.Target),
                    Method = value.Method
                    
                });
            }
            remove
            {
                
            }
        }

        public void WeakPublish(string name)
        {
            List<WeakDelegate> toRemove = new List<WeakDelegate>();
            foreach(WeakDelegate subscriber in weakSubscribers)
            {
                object target = subscriber.Target.Target;
                if(target == null)
                {
                    toRemove.Add(subscriber);
                }
                else
                {
                    subscriber.Method.Invoke(target, new object[] { this, new GameInfo(name) });
                }
            }

            weakSubscribers.RemoveAll(delegate (WeakDelegate d) { return toRemove.Contains(d); });
        }             

        public void Publish(string name)
        {            
            Console.WriteLine($"We are pleased to announce the new game {name}");
            Subscribe?.Invoke(this, new GameInfo(name));
        }

        public GamePublisher(string name)
        {
            Name = name;
        }

        public string Name { get; }
    }

    public class Player
    {
        private WeakReference<GamePublisher> publisher;
        public WeakReference<GamePublisher> Publiser { set { publisher = value; } }

        public void Unsubscribe()
        {
            if(publisher== null)
            {
                return;
            }

            
        }
        public void Preorder(object o, GameInfo e)
        {
            Console.WriteLine($"{Name} says {e.Name} published by {((GamePublisher)o).Name} is awesome");
        }

        public Player(string name)
        {
            placeHolder = new List<string>();
            int x = 0;
            while(x++ <= 100)
            {
                placeHolder.Add( "place holder{0}"+ x);
            }
            Name = name;
        }

        public string Name { get; }

        public List<string> placeHolder;
    }

    public class WeakPlayer
    {
        private WeakReference Target;
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
            int x = 0;
            int y = 0;

            
                GamePublisher pub = new GamePublisher("Activation");

            Player p1 = new Player("zhouwei");

            pub.Subscribe += p1.Preorder;

            p1.Publiser = new WeakReference<GamePublisher>(pub);


            pub.Publish("COD 4, Morden warfare");

            Player p2 = new Player("dengmin");

                pub.Subscribe += p2.Preorder;

            pub.Publish("COD6, Morden warfare II");

            Player p3 = new Player("winner");

            pub.Subscribe -= p2.Preorder;
            pub.Subscribe += p3.Preorder;

            pub.WeakPublish("test Name");

            pub.WeakSubscribe += p3.Preorder;

            
            Player p4 = new Player("Infinate" + x);
            pub.WeakSubscribe += p4.Preorder;
            pub.WeakPublish("test name 2");
            //pub.Publish("COD8, Infinte warfare");


                //    y++;
            Player p5 = new Player("infinite-loop"+5);
            pub.Subscribe += p5.Preorder;

            pub.Publish("dummy release");

            




        }
    }
}
