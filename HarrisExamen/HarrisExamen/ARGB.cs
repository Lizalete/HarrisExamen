using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

/**

* Esta clase es en relación con los colores en formato ARGB.

* @author: Omar López Rincón

*/

namespace ASSISTME.SNIPS.PIXELS
{
    public class ARGB
    {
        public const byte B = 0;
        public const byte G = 1;
        public const byte R = 2;
        public const byte A = 3;

        private Color pixel;

        public Color Colors
        {
            get { return pixel; }
        }

        public ARGB(byte A, byte R, byte G, byte B)
        {
            pixel = Color.FromArgb(A, R, G, B);
        }
        public ARGB(byte R, byte G, byte B)
        {
            pixel = Color.FromArgb(255, R, G, B);
        }

        public ARGB(Color color)
        {
            pixel = Color.FromArgb(color.A, color);
        }

        public ARGB()
        {
            pixel = Color.FromArgb(0,0,0);
        }

        public void setColors(byte A, byte R, byte G, byte B)
        {
            pixel = Color.FromArgb(A, R, G, B);
        }
        public void setColors(int A, int R, int G, int B)
        {
            pixel = Color.FromArgb(A, R, G, B);
        }
        public void setColors(int R, int G, int B)
        {
            pixel = Color.FromArgb(255, R, G, B);
        }
        public void setColors(Color color)
        {
            pixel = color;
        }

        public override string ToString()
        {
            return (pixel.A + " " + pixel.R + " " + pixel.G + " " + pixel.B);
        }
    }
}
