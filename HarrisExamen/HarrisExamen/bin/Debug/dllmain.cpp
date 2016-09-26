#include "dllharris.h"
#include <windows.h>
#include <iostream>
#include <math.h>

/**

* Esta clase contiene los métodos YUV, Sobel y HarrisCorner.

* @author: Lizbeth Peralta Malváez

* @version: 25/09/2016/C

*/


/**YUV
    * Método que hace la conversión de RGB a YUV 
           
    * @param image[]: arreglo de bytes de la imagen
			    size: la longitud del arreglo

*/
MYAPI void YUV(unsigned char image[], int size) 
{
	unsigned char temp[size];
	double Y, U, V;
    Y = 0;
    U = 0;
    V = 0;
	
	//0 = B 1 = G 2 = R
    for (int i = 0; i < size; i+=4) 
	{
        Y = (.299 * image[i + 2]) + (.587 * image[i + 1]) + (.114 * image[i]);

        temp[i] = (unsigned char)Y;
        temp[i + 1] = (unsigned char)Y;
        temp[i + 2] = (unsigned char)Y;
    }

    for (int i = 0; i < size; i += 4) 
	{
        image[i] = temp[i];
    	image[i + 1] = temp[i + 1];
        image[i + 2] = temp[i + 2];
    }
}

/**Sobel
    * Método que aplica el operador Sobel 
           
    * @param image[]: arreglo de bytes de la imagen
			  size: la longitud del arreglo
			  height: alto de la imagen
			  width: ancho de la imagen
		
		La máscara es de tamaño 3x3 (uso de top, center y down)

*/
MYAPI void Sobel(unsigned char image[], int height, int width, int size) 
{
    
    int index;
    
    int width4 = width * 4;
    int height4 = height * 4;
    unsigned char imageTemp[size];
    unsigned char top[width4];
    unsigned char center[width4];
    unsigned char down[width4];
    int sumaRX = 0; int sumaGX = 0; int sumaBX = 0;
	int sumaRY = 0; int sumaGY = 0; int sumaBY = 0;

	
	for (int t = 0; t < height - 2; t++)
	{
     	index = 0;
        for (int i = width4 * t; i < width4 * (t + 1); i++)
            {
                top[index] = image[i];
                center[index] = image[i + width4];
                down[index] = image[i + (2 * width4)];
                index++;
            }
                
                //0 = B 1 = G 2 = R
            for (int j = 0; j < width4-8; j+=4) 
			{
                sumaBY = abs(-(int)top[j] - (int)(2 * top[j+4]) - (int)top[j+8] + (int)down[j] + (int)(2 * down[j+4]) + (int)down[j+8]);
                sumaGY = abs(-(int)top[j+1] - (int)(2 * top[j+5]) - (int)top[j+9] + (int)down[j+1] + (int)(2 * down[j+5]) + (int)down[j+9]);
                sumaRY = abs(-(int)top[j+2] - (int)(2 * top[j+6]) - (int)top[j+10] + (int)down[j+2] + (int)(2 * down[j+6]) + (int)down[j+10]);
                
                sumaBX = abs(-(int)top[j] + (int)top[j + 8] - (int)(2*center[j]) + (int)(2*center[j+8]) -(int)(down[j]) + (int)(down[j+8]));
            	sumaGX = abs(-(int)top[j+1] + (int)top[j + 9] - (int)(2 * center[j+1]) + (int)(2 * center[j + 9]) - (int)(down[j+1]) + (int)(down[j + 9]));
                sumaRX = abs(-(int)top[j+2] + (int)top[j + 10] - (int)(2 * center[j+2]) + (int)(2 * center[j + 10]) - (int)(down[j+2]) + (int)(down[j + 10]));
 				
				if (sumaRY > 255) { sumaRY = 255; } else if (sumaRY < 0) { sumaRY = 0; }
                if (sumaGY > 255) { sumaGY = 255; } else if (sumaGY < 0) { sumaGY = 0; }
                if (sumaBY > 255) { sumaBY = 255; } else if (sumaBY < 0) { sumaBY = 0; }
                if (sumaRX > 255) { sumaRX = 255; } else if (sumaRX < 0) { sumaRX = 0; }
                if (sumaGX > 255) { sumaGX = 255; } else if (sumaGX < 0) { sumaGX = 0; }
                if (sumaBX > 255) { sumaBX = 255; } else if (sumaBX < 0) { sumaBX = 0; }
                
                center[j] = (unsigned char)sumaBX + sumaBY;
                center[j + 1] = (unsigned char)sumaGX + sumaGY;
                center[j + 2] = (unsigned char)sumaRX + sumaRY;
            }
            
            index = 0;
            for (int m = width4 * (t+1); m < width4 * (t+2); m++)
            {
                imageTemp[m] = center[index];
                index++;
            }
    }
    
    for (int k = 0; k < size; k++) 
	{
		image[k] = imageTemp[k];
	}
}

/**HarrisCorner
    * Método que aplica Harris 
           
    * @param image[]: arreglo de bytes de la imagen
			  size: la longitud del arreglo
			  height: alto de la imagen
			  width: ancho de la imagen
		
		La máscara es de tamaño 5x5 (uso de line1, line2, line3, line4 y line5)

*/
MYAPI void HarrisCorner(unsigned char image[], int height, int width, int size) 
{
	int width4 = width * 4;
    int sumRow1, sumRow3, sumRow5, sumColumn1, sumColumn3, sumColumn5;
    int index;
    
    unsigned char line1[width4]; unsigned char line2[width4]; unsigned char line3[width4]; unsigned char line4[width4]; unsigned char line5[width4];
	unsigned char tempHarris[size]; unsigned char temp[size];

    int th = 150;
    
    for (int i = 0; i < size; i++) 
	{
        if (image[i] <= th){temp[i] = 0;}
        if (image[i] > th) {temp[i] = 255;}
    }
    
	for (int j = 0; j < size; j++) 
	{
        image[j] = temp[j];
    }
            
    for (int t = 0; t < height - 4; t++)
    {
        index = 0;
        for (int i = width4 * t; i < (width4 * (t + 1)); i++)
        {
            line1[index] = image[i];
            line2[index] = image[i + width4];
            line3[index] = image[i + (2 * width4)];
            line4[index] = image[i + (3 * width4)];
            line5[index] = image[i + (4 * width4)];
            index++;
        }

        //0 = B 1 = G 2 = R
        for (int j = 0; j < width4 - 20; j += 4)
        {
            sumColumn1 = 0; sumRow1 = 0; sumColumn3 = 0; sumRow3 = 0; sumColumn5 = 0; sumRow5 = 0;

            sumRow1 = abs((int)(line1[j]) + (int)(line1[j + 1]) + (int)(line1[j + 2]) + 
                    (int)(line1[j + 4]) + (int)(line1[j + 5]) + (int)(line1[j + 6]) + 
                    (int)(line1[j + 8]) + (int)(line1[j + 9]) + (int)(line1[j + 10]) + 
                    (int)(line1[j + 12]) + (int)(line1[j + 13]) + (int)(line1[j + 14]) +
                    (int)(line1[j + 16]) + (int)(line1[j + 17]) + (int)(line1[j + 18])); 

            sumRow3 = abs((int)(line3[j]) + (int)(line3[j + 1]) + (int)(line3[j + 2]) +
                    (int)(line3[j + 4]) + (int)(line3[j + 5]) + (int)(line3[j + 6]) + 
                    (int)(line3[j + 8]) + (int)(line3[j + 9]) + (int)(line3[j + 10]) +
                    (int)(line3[j + 12]) + (int)(line3[j + 13]) + (int)(line3[j + 14]) + 
                    (int)(line3[j + 16]) + (int)(line3[j + 17]) + (int)(line3[j + 18]));

            sumRow5 = abs((int)(line5[j]) + (int)(line5[j + 1]) + (int)(line5[j + 2]) + 
                    (int)(line5[j + 4]) + (int)(line5[j + 5]) + (int)(line5[j + 6]) + 
                    (int)(line5[j + 8]) + (int)(line5[j + 9]) + (int)(line5[j + 10]) + 
                    (int)(line5[j + 12]) + (int)(line5[j + 13]) + (int)(line5[j + 14]) + 
                    (int)(line5[j + 16]) + (int)(line5[j + 17]) + (int)(line5[j + 18])); 


            sumColumn1 = abs((int)line1[j] + (int)line1[j + 1] + (int)line1[j + 2] + 
                        (int)line2[j] + (int)line2[j + 1] + (int)line2[j + 2] +
                        (int)line3[j] + (int)line3[j + 1] + (int)line3[j + 2] +
                        (int)line4[j] + (int)line4[j + 1] + (int)line4[j + 2] +
                        (int)line5[j] + (int)line5[j + 1] + (int)line5[j + 2]); 

            sumColumn3 = abs((int)line1[j + 8] + (int)line1[j + 9] + (int)line1[j + 10] +
                        (int)line2[j + 8] + (int)line2[j + 9] + (int)line2[j + 10] + 
                        (int)line3[j + 8] + (int)line3[j + 9] + (int)line3[j + 10] + 
                        (int)line4[j + 8] + (int)line4[j + 9] + (int)line4[j + 10] + 
                        (int)line5[j + 8] + (int)line5[j + 9] + (int)line5[j + 10]);


            sumColumn5 = abs((int)line1[j + 16] + (int)line1[j + 17] + (int)line1[j + 18] +
                       (int)line2[j + 16] + (int)line2[j + 17] + (int)line2[j + 18] + 
                       (int)line3[j + 16] + (int)line3[j + 17] + (int)line3[j + 18] + 
                       (int)line4[j + 16] + (int)line4[j + 17] + (int)line4[j + 18] + 
                       (int)line5[j + 16] + (int)line5[j + 17] + (int)line5[j + 18]);
                   
            if (((sumColumn3) + (sumRow3)) > (sumRow1 + sumRow5 + sumColumn1 + sumColumn5))
            {
                line2[j + 4] = 255; line2[j + 5] = 255; line2[j + 6] = 255; 
                line2[j + 8] = 255; line2[j + 9] = 255; line2[j + 10] = 255; 
                line2[j + 12] = 255; line2[j + 13] = 255; line2[j + 14] = 255; 

                line3[j + 4] = 255; line3[j + 5] = 255; line3[j + 6] = 255; 
                line3[j + 8] = 255; line3[j + 9] = 255; line3[j + 10] = 255; 
                line3[j + 12] = 255; line3[j + 13] = 255; line3[j + 14] = 255; 

                line4[j + 4] = 255; line4[j + 5] = 255; line4[j + 6] = 255; 
                line4[j + 8] = 255; line4[j + 9] = 255; line4[j + 10] = 255; 
                line4[j + 12] = 255; line4[j + 13] = 255; line4[j + 14] = 255; 

                line1[j] = 0; line1[j + 1] = 0; line1[j + 2] = 0; 
                line1[j + 4] = 0; line1[j + 5] = 0; line1[j + 6] = 0;  
                line1[j + 8] = 0; line1[j + 9] = 0; line1[j + 10] = 0; 
                line1[j + 12] = 0; line1[j + 13] = 0; line1[j + 14] = 0;  
                line1[j + 16] = 0; line1[j + 17] = 0; line1[j + 18] = 0; 

                line5[j] = 0; line5[j + 1] = 0; line5[j + 2] = 0;  
                line5[j + 4] = 0; line5[j + 5] = 0; line5[j + 6] = 0;  
                line5[j + 8] = 0; line5[j + 9] = 0; line5[j + 10] = 0; 
                line5[j + 12] = 0; line5[j + 13] = 0; line5[j + 14] = 0; 
                line5[j + 16] = 0; line5[j + 17] = 0; line5[j + 18] = 0; 

                line2[j] = 0; line2[j + 1] = 0; line2[j + 2] = 0; 
                line2[j + 16] = 0; line2[j + 17] = 0; line2[j + 18] = 0; 

                line3[j] = 0; line3[j + 1] = 0; line3[j + 2] = 0; 
                line3[j + 16] = 0; line3[j + 17] = 0; line3[j + 18] = 0; 

                line4[j] = 0; line4[j + 1] = 0; line4[j + 2] = 0; 
                line4[j + 16] = 0; line4[j + 17] = 0; line4[j + 18] = 0; 
            }
        }

        index = 0;
        for (int m = width4 * (t); m < width4 * (t + 1); m++)
        {
            tempHarris[m] = line1[index];
            tempHarris[m + width4] = line2[index];
            tempHarris[m + (2*width4)] = line3[index];
            tempHarris[m + (3 * width4)] = line4[index];
            tempHarris[m + (4 * width4)] = line5[index];
            index++;
        }
    }
        
    for (int h = 0; h < size; h++)
    {
        image[h] = tempHarris[h];
    }
}
