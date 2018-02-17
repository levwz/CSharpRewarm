using System;
namespace LevwzConsoleApp
{
    public class EnumSample
    {
        public enum DaysOfWeek
        {
            Monday = 0x1,
            Tuesday = 0x2,
            Wednesday = 0x4,
            Thursday = 0x8,
            Friday = 0x10,
            Saturday = 0x20,
            Sunday = 0x40
        }
        public EnumSample()
        {
        }

        public void Test(){
            DaysOfWeek mondayAndWendnesday = DaysOfWeek.Monday | DaysOfWeek.Wednesday;
            DaysOfWeek dow;
            Enum.TryParse<DaysOfWeek>("5", out dow);

            Console.WriteLine(dow);

            Console.WriteLine(mondayAndWendnesday);
        }
    }
}
