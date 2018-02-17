using System;
namespace LevwzConsoleApp
{
    public struct structSample
    {
        public double Length { get; set; }
        public double Width { get; set; }
        public structSample(double length, double width)
        {
            Length = length;
            Width = width;
        }

        public double Diagnoal => Math.Sqrt(Length * Length + Width * Width); //expression attribute
    }
}
