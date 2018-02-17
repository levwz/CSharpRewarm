using System;
namespace LevwzConsoleApp.Generic
{
    public interface Covariance<out IAmAnOutputType>
    {
        IAmAnOutputType this[int index]{ get;}
        IAmAnOutputType this[string key] { get; }
        int Count { get; }
    }

    public interface Contravariance<in IAmAnInputType>
    {
        void Display(IAmAnInputType item);
    }

    public class Base
    {
        public string Name { get; set; }
    }

    public class Derived: Base
    {
        public string Occupation { get; set; }
    }
    public class CoContraVariance: Covariance<Derived>, Contravariance<Base>
    {
        private Derived[] data = new Derived[3]
        {
            new Derived { Name="name1", Occupation="Teacher" },
            new Derived{ Name="name2", Occupation="Engineer" },
            new Derived{ Name="name3" , Occupation="CEO" }
        };

        private static CoContraVariance _coll;
        public static CoContraVariance GetVariances() =>
        _coll ?? (_coll = new CoContraVariance());

        public Derived this[int index]
        {
            get
            {
                if (index < 0 || index > 100)
                {
                    throw new ArgumentOutOfRangeException("index");
                }

                return data[index];
            }
        }

        public Derived this[string key]
        {
            get
            {
                for (int i = 0; i < data.Length; i++)
                {
                    if(key.Equals(data[i].Name))
                    {
                        return data[i];
                    }
                }

                return null;
            }
        }

        public void Display(Base item) => Console.WriteLine($"{item.GetType().Name}");

        public int Count => data.Length;

    }


    public class CoContraVarianceIsMakeSureConvertFromDerivedToBase
    {
        public void Test()
        {
            //Covariance<Base> coB = new CoContraVarianceCollection();
            //Covariance<Derived> coD = coB;
            Covariance<Derived> coD = new CoContraVariance();
            Covariance<Base> coB = coD;
            


            //Contravariance<Derived> contraD = new CoContraVarianceCollection();
            //Contravariance<Base> contraB = contraD;
            Contravariance<Base> contraB = new CoContraVariance();
            Contravariance<Derived> contraD = contraB;

        }
    }
}
