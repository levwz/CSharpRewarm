using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LevwzConsoleApp.Generic;
using System.Runtime.InteropServices;

namespace LevwzConsoleApp
{

    [StructLayout(LayoutKind.Sequential)]
    class ClassSizeof
    {
        private String name;

        public String Name
        {
            get { return name; }
            private set { name = value; }
        }

        private int age;
        public int Age
        {
            get { return age; }
            private set { age = value;}
        }


        private String gender;

        public String Gender
        {
            get { return gender; }
            private set { gender = value; }
        }

        private int income;
        public int Income
        {
            get { return income;}
            private set { income = value; }
        }
        public ClassSizeof(String name, int age, String gender)
        {
            this.name = name;
            this.age = age;
            this.gender = gender;
        }

        public override string ToString()
        {
            return string.Format("{0}-{1}-{2}-{3}", Name, Age, Gender, Income>100);
        }

    }

    delegate void StringProcessor(string input);

    class Person
    {
        string name;
        public string Name { get { return name; } set { name = value; } }
        public Person(string name) { this.name = name; }

        public void Say(string message)
        {
            Console.WriteLine("{0} says: {1}", name, message);
        }
    }

    class Background
    {
        public static void Note(string note)
        {
            Console.WriteLine("({0})", note);
        }
    }



    class Comparer : IComparer<ClassSizeof>
    {
        public int Compare(ClassSizeof x, ClassSizeof y)
        {
            return x.Age - y.Age;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            EnumSample es = new EnumSample();
            es.Test();
            System.Console.WriteLine(new structSample(12, 22).Diagnoal);

            structSample ss = new structSample(1, 2);
          //  ss.Length = 11;
            //ss.Width = 22;
            System.Console.WriteLine(ss.Diagnoal);

            System.Console.WriteLine(StaticClass.cc);
            
            Person jon = new Person("Jon");
           
            StringProcessor jonsVoice, tomsVoice, background;
            
            jonsVoice = new StringProcessor(jon.Say);
            { 
            Person tom = new Person("Tom");
            tomsVoice = new StringProcessor(tom.Say);
            }
            background = new StringProcessor(Background.Note);

            jonsVoice("Hello, son.");

            tomsVoice("hello, Daddy");
            background("An airplane flies past");
            jon.Name = "Jon Snow";
            jonsVoice += tomsVoice;

            foreach(Delegate dele in jonsVoice.GetInvocationList())
            {
                dele.DynamicInvoke("Iknow nothing yegret");
            }

            jonsVoice("I know nothing");
            background.Invoke("Another airplane files past");
            ClassSizeof szof = new ClassSizeof(name: "zhouwei", age: 33, gender: "male");
            // Program pro = new Program();
            //class 
            Console.WriteLine("{0}-{1}-{2}", szof.Name, szof.Age, szof.Gender);
            Console.WriteLine(Marshal.SizeOf(szof/*new ClassSizeof(name: "zhouwei", age: 33, gender: "male")*/));

            List<ClassSizeof> list = new List<ClassSizeof> { new ClassSizeof(name: "zhouwei", age: 33, gender: "male"),
                                                            new ClassSizeof(name: "zhouchao", age: 30, gender: "male"),
                                                            new ClassSizeof(name: "zhoujiazu", age: 230, gender: "male"),
                                                            new ClassSizeof(name: "dengmin", age: 32, gender: "female")
            };

            list.Sort(new Comparer());
            list.Sort(delegate (ClassSizeof s1, ClassSizeof s2) { return s2.Age
 
                 - s1.Age; });

            list.Sort(comparison:(a, b) => { return a.Age - b.Age; });

            foreach (ClassSizeof szof2 in list.OrderBy(z => z.Name)){
                Console.WriteLine("{0}-{1}-{2}", szof2.Name, szof2.Age, szof2.Gender);
            }

            foreach(ClassSizeof szof1 in list)
            {
                Console.WriteLine("{0}-{1}-{2}", szof1.Name, szof1.Age, szof1.Gender);
            }

            Predicate<ClassSizeof> gr30 = delegate (ClassSizeof sz) { return sz.Age > 30; };

            List<ClassSizeof> qualified = list.FindAll(gr30);
            Action<ClassSizeof> print = Console.WriteLine;
            Console.WriteLine("action print");
            qualified.ForEach(print);
            var qua = from ClassSizeof sz in list where sz.Age > 30 select sz;
            Console.WriteLine("LINQ");
            foreach(ClassSizeof sz in qua.OrderBy(p=>p.Age))
            {
                Console.WriteLine(sz);
            }


            DelegateEventsTest det = new DelegateEventsTest();

            det.Test();

            GenericDictionary td = new GenericDictionary();

            td.Test();
            PartialClassSampleInvoker pcsi = new PartialClassSampleInvoker();

            pcsi.Test();

            ExtensionClass ec = new ExtensionClass();
            ec.Test();

            OverrideAndHiddenSample oahs = new OverrideAndHiddenSample();

            oahs.Test();

            AsAndIsSample aais = new AsAndIsSample();
            aais.Test();

            WeakReferenceSample srs = new WeakReferenceSample();
            srs.Test();

            LinkedListSample lls = new LinkedListSample();
            lls.Test();

            CoContraVarianceIsMakeSureConvertFromDerivedToBase iovs = new CoContraVarianceIsMakeSureConvertFromDerivedToBase();
            iovs.Test();

            Console.Read();
        }
    }
}
