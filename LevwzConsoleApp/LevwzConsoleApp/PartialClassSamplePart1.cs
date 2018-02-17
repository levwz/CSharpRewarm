using System;
namespace LevwzConsoleApp
{
    partial class PartialClassSample
    {
        public PartialClassSample()
        {
        }

        public int Method1(){
            Console.WriteLine("I am Method1, defeined in part 1, and I will call Partial Method dfeined in part 2");
            PartialMethodDefinedInPart2();
            return 1;
        }

      //  partial void PartialMethodDefinedInPart2(); //should be updated, declaration is no longer required
    }


    public class PartialClassSampleInvoker{
        public PartialClassSampleInvoker(){}

        public void Test(){
            PartialClassSample pcs = new PartialClassSample();

            pcs.Method1();

        }
    }
}
