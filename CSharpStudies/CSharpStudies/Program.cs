using System;

namespace CSharpStudies
{
    class MainClass
    {
        delegate void DelegateVoid();
        public static void Main(string[] args)
        {
            LambdaDelegateAnonymous lda = new LambdaDelegateAnonymous();

            DelegateVoid dv = new DelegateVoid(lda.Test);

            dv();

            Console.WriteLine("Hello World!");
        }
    }
}
