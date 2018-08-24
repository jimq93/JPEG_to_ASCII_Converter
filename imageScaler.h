/**  
*  @file    main.cpp
*  @author  Jim Quach
*  @date    06/04/2017  
*
*  JPEG to ASCII Converter
*
*  @section DESCRIPTION
*
*  This program accepts a JPEG image and text file from
*  user input and then reads the JPEG file, saves an ASCII
*  equivalent in the text file, and also prints the size
*  of the original image (number of pixels).
*
*/


#ifndef IMAGE_H
#define IMAGE_H
#define Maximum_Number_Of_Row 1000
#define Maximum_Number_Of_Column 1000
#include <iostream>
#include <fstream>
#include "824.jpg"
using namespace std;


void image_Downscaler(unsigned char image[][Maximum_Number_Of_Column], int& number_of_rows, int& number_of_columns);


void image_conversion(unsigned char image[][Maximum_Number_Of_Column],int number_of_rows, int number_of_columns, char ascii[][100]); 


void output_to_image(string& textFileName, char ascii[][100], int number_of_rows, int number_of_columns); 


#endif


