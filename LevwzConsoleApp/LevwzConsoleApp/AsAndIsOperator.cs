using System;
namespace LevwzConsoleApp
{
    public class AsAndIsOperator
    {
        public AsAndIsOperator ConvertUnsafe(Object o)
        {
            return (AsAndIsOperator)o;
        }

        public AsAndIsOperator ConvertSafeAsVersion(Object o)
        {
            return o as AsAndIsOperator;   
        }

        public AsAndIsOperator ConvertSafeIsVersion(Object o)
        {
            return o is AsAndIsOperator ? (AsAndIsOperator)o : null;
        }
        public AsAndIsOperator()
        {
        }
    }

    public class AsAndIsSample
    {
        public void Test()
        {
            AsAndIsOperator obj = new AsAndIsOperator();

            Object convertable = new AsAndIsOperator();
            Object nonconvertable = new object();

            obj.ConvertSafeAsVersion(convertable);
            obj.ConvertSafeIsVersion(convertable);
            obj.ConvertSafeAsVersion(nonconvertable);
            obj.ConvertSafeIsVersion(nonconvertable);

            obj.ConvertUnsafe(convertable);

            try
            {
                obj.ConvertUnsafe(nonconvertable);
            }catch(Exception ex){ Console.WriteLine(ex);}

        }
    }
}
