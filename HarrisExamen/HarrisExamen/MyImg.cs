using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.Runtime.InteropServices;
using ASSISTME.SNIPS.IMG;
using ASSISTME.SNIPS.PIXELS;

/**

* Esta clase almacena la información de la imagen dada: arreglo de bytes, tamaño del arreglo,
 * alto y ancho.

* @author: Omar López Rincón

*/

namespace ASSISTME.SNIPS
{
    public class MyImg
    {
        #region Properties
        private IntPtr ptr_Address;
        private GCHandle handle;
        private Bitmap image;////************
        private byte[] data;////************
        private Graphics graphics;////************

        private static PixelFormat px;
        private static Bitmap newBmp;
        private static LockBitmap bitmap;
       
        private static int widthVar, heightVar, BYTES;

        public Size Size
        {
            get { return image.Size; }
        }

        public int Lenght
        {
            get { return data.Length;  }
        }

        public int Width
        {
            get { return image.Width; }
        }

        public int Height
        {
            get { return image.Height; }
        }

        public Bitmap Image
        {
            get { return image; }
        }

        public byte[] ImageData
        {
            get { return data; }
            set { data = value; }
        }

        public Graphics Graphics
        {
            get { return graphics; }
        }
        
        public IntPtr Ptr_Address
        {
            get { return ptr_Address; }
        }
        #endregion

        public MyImg(Bitmap bmp)
        {
            widthVar = bmp.Width;
            heightVar = bmp.Height;
            BYTES = 4;
            px = PixelFormat.Format32bppPArgb;

            Create(bmp);
            GC.Collect(GC.MaxGeneration, GCCollectionMode.Forced);
        }

        public void SetImage(Bitmap bmp)
        {
            widthVar = bmp.Width;
            heightVar = bmp.Height;
            BYTES = 4;
            px = PixelFormat.Format32bppPArgb;
            Create(bmp);
            GC.Collect(GC.MaxGeneration, GCCollectionMode.Forced);
        }

        private void Create(Bitmap bmp)
        {           
            Create();                  
            //********************************************
            newBmp = new Bitmap(bmp);//used to create a 32bppPArgb
            bitmap = new LockBitmap(newBmp);
            
            bitmap.LockBits();
            Marshal.Copy(bitmap.Pixels, 0, ptr_Address, bitmap.Pixels.Length);
            bitmap.UnlockBits();

            newBmp.Dispose();
            bitmap.Pixels = new byte[0];
            bitmap = null;
        }

        private void Create()
        {
            try
            {
                if (data == null || data.Length != (widthVar * heightVar * BYTES))
                {
                    ptr_Address = IntPtr.Zero;
                    data = null;
                    GC.Collect(GC.MaxGeneration, GCCollectionMode.Forced);

                    data = new byte[widthVar * heightVar * BYTES];
                    handle = GCHandle.Alloc(data, GCHandleType.Pinned);
                    ptr_Address = Marshal.UnsafeAddrOfPinnedArrayElement(data, 0);                   
                }

                image = new Bitmap(widthVar, heightVar, BYTES * widthVar, px, ptr_Address);
                graphics = Graphics.FromImage(image);
                graphics.Clear(Color.Empty);
            }
            catch (Exception ) {  }
        }

        public Color GetPixel(int x, int y)
        {
            byte R, G, B, A;
            int index = GetIndex(x, y);

            A = data[index + ARGB.A];
            R = data[index + ARGB.R];
            G = data[index + ARGB.G];
            B = data[index + ARGB.B];

            return Color.FromArgb(A, R, G, B);
        }

        public void SetPixel(int x, int y, Color pixel)
        {
            int index = GetIndex(x, y);

            data[index + ARGB.A] = pixel.A;
            data[index + ARGB.R] = pixel.R;
            data[index + ARGB.G] = pixel.G;
            data[index + ARGB.B] = pixel.B;
        }

        public void SetAlpha(int x, int y, byte alpha)
        {
            data[GetIndex(x, y) + ARGB.A] = alpha;
        }

        private int GetIndex(int x, int y)
        {
            return (y * 4 * image.Width) + (x * 4);
        }

    }
}
