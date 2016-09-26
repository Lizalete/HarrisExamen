namespace HarrisExamen
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador requerida.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén utilizando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben eliminar; false en caso contrario, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido del método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.BTN_LOAD = new System.Windows.Forms.Button();
            this.BTN_SOBEL = new System.Windows.Forms.Button();
            this.OFD = new System.Windows.Forms.OpenFileDialog();
            this.PCT_IMAGE = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.PCT_IMAGE)).BeginInit();
            this.SuspendLayout();
            // 
            // BTN_LOAD
            // 
            this.BTN_LOAD.Location = new System.Drawing.Point(12, 12);
            this.BTN_LOAD.Name = "BTN_LOAD";
            this.BTN_LOAD.Size = new System.Drawing.Size(81, 37);
            this.BTN_LOAD.TabIndex = 0;
            this.BTN_LOAD.Text = "LOAD IMAGE";
            this.BTN_LOAD.UseVisualStyleBackColor = true;
            this.BTN_LOAD.Click += new System.EventHandler(this.BTN_LOAD_Click);
            // 
            // BTN_SOBEL
            // 
            this.BTN_SOBEL.Location = new System.Drawing.Point(1, 78);
            this.BTN_SOBEL.Name = "BTN_SOBEL";
            this.BTN_SOBEL.Size = new System.Drawing.Size(103, 23);
            this.BTN_SOBEL.TabIndex = 1;
            this.BTN_SOBEL.Text = "SOBEL/HARRIS";
            this.BTN_SOBEL.UseVisualStyleBackColor = true;
            this.BTN_SOBEL.Click += new System.EventHandler(this.BTN_SOBEL_Click);
            // 
            // OFD
            // 
            this.OFD.FileName = "openFileDialog1";
            // 
            // PCT_IMAGE
            // 
            this.PCT_IMAGE.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.PCT_IMAGE.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.PCT_IMAGE.Location = new System.Drawing.Point(121, 12);
            this.PCT_IMAGE.Name = "PCT_IMAGE";
            this.PCT_IMAGE.Size = new System.Drawing.Size(575, 286);
            this.PCT_IMAGE.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.PCT_IMAGE.TabIndex = 2;
            this.PCT_IMAGE.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(708, 320);
            this.Controls.Add(this.PCT_IMAGE);
            this.Controls.Add(this.BTN_SOBEL);
            this.Controls.Add(this.BTN_LOAD);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.PCT_IMAGE)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button BTN_LOAD;
        private System.Windows.Forms.Button BTN_SOBEL;
        private System.Windows.Forms.OpenFileDialog OFD;
        private System.Windows.Forms.PictureBox PCT_IMAGE;
    }
}

