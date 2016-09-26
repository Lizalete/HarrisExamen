using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using ASSISTME.SNIPS;
using System.Windows.Forms;

/**

* Esta clase llama al DLL donde se encuentran los métodos de YUV, Sobel y Harris para que el programa pueda utilizarlos

* @author: Lizbeth Peralta Malváez

* @version: 25/09/2016/C

*/

namespace HarrisExamen
{
    class Harris
    {
        /**
         Llamada al DLL con los métodos YUV, Sobel y Harris
         */
        [DllImport("HARRIS.dll")]
        private static extern void YUV(byte[] image, int size);
        [DllImport("HARRIS.dll")]
        private static extern void Sobel(byte[] image, int height, int width,int size);
        [DllImport("HARRIS.dll")]
        private static extern void HarrisCorner(byte[] image, int height, int width, int size);

        /**getYUV
        * Método que hace la conversión de RGB a YUV 
           
        * @param img: La imagen a convertir, se toma el arreglo de bytes y la longitud de éste

        */
        public static void getYUV(MyImg img) 
        {
            YUV(img.ImageData, img.Lenght);
        }

        /**getSobel
        * Método que aplica el operador Sobel a la imagen
           
        * @param img: La imagen a convertir, se toma el arreglo de bytes, longitud de éste, alto y ancho

        */
        public static void getSobel(MyImg img)
        {
            Sobel(img.ImageData,img.Height,img.Width, img.Lenght);
        }

        /**getHarris
        * Método que aplica Harris a la imagen
           
        * @param img: La imagen a convertir, se toma el arreglo de bytes, longitud de éste, alto y ancho

        */
        public static void getHarris(MyImg img)
        {
                HarrisCorner(img.ImageData, img.Height, img.Width, img.Lenght);
            
        }
    }
}
