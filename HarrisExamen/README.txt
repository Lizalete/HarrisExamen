El objetivo de este programa es detectar las esquinas con
Harris.

El programa está hecho en C# y el encabezado (header) en C.

El proyecto en C consta de los siguientes métodos:

1.- YUV: Recibe el arreglo de bytes (la imagen) y la
longitud de éste. Realiza la transformación de RGB a YUV.

2.- Sobel: Recibe el arreglo de bytes (la imagen), la
longitud de éste, alto y ancho de la imagen. Aplica el 
operador Sobel en la imagen. Se hace con una máscara de 3x3.

3.- HarrisCorner: Recibe el arreglo de bytes (la imagen), la
longitud de éste, alto y ancho de la imagen. Aplica Harris
en la imagen. Se utiliza una máscara 5x5.

El proyecto en C# consta de las siguientes clases:
1.- Form1.cs: Contiene los métodos relacionados con 
los eventos que se presentan en la interfaz de usuario.

2.- Harris.cs: Esta clase importa el DLL y llama a los métodos
de YUV, Sobel y HarrisCorner.

3.- LockBitmap.cs(*): Realiza el arreglo de bytes 
que se necesita para aplicar las transformaciones y 
los operadores.

4.- ARGB.cs(*): En relación con los colores en formato ARGB.

5.-MyImg.cs(*): Almacena la información de la imagen dada: 
arreglo de bytes, tamaño del arreglo, alto y ancho.

(*) Clases realizadas por Omar López Rincón 
(https://github.com/ProcopioPi)