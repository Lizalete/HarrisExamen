using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using ASSISTME.SNIPS;

/**

* Esta clase contiene los métodos relacionados con los eventos que se presentan en la interfaz de usuario.

* @author: Lizbeth Peralta Malváez

* @version: 25/09/2016/C

*/

namespace HarrisExamen
{
    public partial class Form1 : Form
    {
        //Campos de la clase
        Bitmap image;
        MyImg img;
        
        public Form1()
        {
            InitializeComponent();
        }

        /**BTN_LOAD_Click
        * Al dar click en "LOAD IMAGE", se presenta una ventana para elegir la imagen a convertir.
         * La información de la imagen se almacena en img
            La imagen se presenta en el PictureBox
        */
        private void BTN_LOAD_Click(object sender, EventArgs e)
        {
            if (OFD.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                image = new Bitmap(OFD.FileName);
                img = new MyImg(image);
                PCT_IMAGE.Image = img.Image;
            }
        }

        /**BTN_SOBEL_Click
        * Al dar click en "SOBEL/HARRIS", se hace la conversión a YUV, se aplica el operador Sobel y 
         * por último Harris.
         * El resultado final se presenta en el PictureBox
        */
        private void BTN_SOBEL_Click(object sender, EventArgs e)
        {
            Harris.getYUV(img);
            Harris.getSobel(img);
            Harris.getHarris(img);
            PCT_IMAGE.Refresh();
        }
    }
}