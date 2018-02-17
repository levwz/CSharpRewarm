using System;
namespace LevwzConsoleApp
{
    public class StrongReferenceInstance{
        private int x;
        public int X { get; set; }

        private String name;
        public String Name { set; get; }


    }

    public class WeakReferenceSample
    {
        public WeakReferenceSample()
        {
        }

        public void Test()
        {
            var reference = new WeakReference(new StrongReferenceInstance());

            if(reference.Target != null){
                StrongReferenceInstance sri = reference.Target as StrongReferenceInstance;

                Console.WriteLine($"x:{sri.X}, name:{sri.Name}");
            }
        }
    }
}
