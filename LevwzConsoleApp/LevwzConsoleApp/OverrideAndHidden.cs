using System;
namespace LevwzConsoleApp
{
    public class OverrideAndHiddenBase
    {
        public virtual void MethodHasBeenOverride()
        {
            Console.WriteLine("Base MethodWillBeOverride");
        }

        public virtual void MethodShouldBeOverride(){
            Console.WriteLine("Base MethodShouldBeOverride");
        }
        public void MethodHidden(){
            Console.WriteLine("Base MethodHidden");
        }
        public void MethodShouldBeHidden()
        {
            Console.WriteLine("Base MethodShouldBeHidden");
        }
        public OverrideAndHiddenBase()
        {
        }
    }
    public class OverrideAndHiddenImpl : OverrideAndHiddenBase
    {
        public override void MethodHasBeenOverride(){
            Console.WriteLine("Impl MethodWillBeOverride");
        }

        public void MethodShouldBeOverride()
        {
            Console.WriteLine("Impl MethodShouldBeOverride");
        }

        new public void MethodHidden(){
            Console.WriteLine("Impl MethodHidden");
        }
        public void MethodShouldBeHidden(){
            Console.WriteLine("Impl MethodShouldBeHidden");   
        }
    }

    public class OverrideAndHiddenSample
    {
        public void Test()
        {
            

            OverrideAndHiddenBase oahb = new OverrideAndHiddenBase();
            oahb.MethodShouldBeOverride();
            oahb.MethodShouldBeHidden();
            oahb.MethodHidden();
            oahb.MethodHasBeenOverride();

            OverrideAndHiddenBase oahi = new OverrideAndHiddenImpl();
            oahi.MethodShouldBeOverride();
            oahi.MethodShouldBeHidden();
            oahi.MethodHidden();
            oahi.MethodHasBeenOverride();

            OverrideAndHiddenImpl oahii = new OverrideAndHiddenImpl();
            oahii.MethodShouldBeOverride();
            oahii.MethodShouldBeHidden();
            oahii.MethodHidden();
            oahii.MethodHasBeenOverride();
        }
    }
}
