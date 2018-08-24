/**  
*  @file    imageScaler.cpp
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



#include "imageScaler.h"
using namespace std;



/**
*  @brief image_Downscaler is a function that reduces an image 
*  to fit within a 100x100 2-Dimensional array
*
*  @param image is a 2-D array containing pixel values
*  of a digital image
*  @param number_of_rows is the number of rows in image
*  @param number_of_columns is the number of columns in image
*
*  @return void
*/
void image_Downscaler(unsigned char image[][Maximum_Number_Of_Column], int& number_of_rows, int& number_of_columns)
{

	unsigned char temp[100][100];	///< Temporary array to shrink image array
	int reduced_row_dimension = (number_of_rows / 100);		///< Reduced number of rows--dimension for pixel groups
	int nc = (number_of_columns / 100);		///< Reduced number of columns--dimension for pixel groups
	int row_counter = 0;			///< Counter for rows in temp
	int column_counter = 0;			///< Counter for columns in temp
	int pixel_value = 0;			///< Number values in each pixel group (to find average)
	int sum_of_pixels = 0;			///< Variable for sum of each pixel group

	for(int i = 0; i < number_of_rows; i += reduced_row_dimension)
	{
		column_counter = 0; 	
		for(int j = 0; j < number_of_columns; j += nc)
		{
			sum_of_pixels = 0;
			pixel_value = 0;
			for(int k = i; k < (i + reduced_row_dimension) && k < Maximum_Number_Of_Row; k++)
			{
				for(int l = j; l < (j + nc) && l < Maximum_Number_Of_Column; l++)
				{
					sum_of_pixels += image[k][l];
					pixel_value++;
				}
			}

			temp[row_counter][column_counter] = (sum_of_pixels / pixel_value);	  
			column_counter++;      
		}

		row_counter++;
	
	}
	
	number_of_rows = row_counter;
	number_of_columns = column_counter;
	

	for(int i = 0; i < number_of_rows; i++)
		for(int j = 0; j < number_of_columns; j++)
			image[i][j] = temp[i][j];


}



/**
*  @brief image_conversion generates the ASCII version of a digital image
*
*  @param image is a 2-D array of a digital image
*  @param number_of_rows is the number of rows in the image
*  @param number_of_columns is the number of columns in the image
*  @param ascii is a 2-D array of an ASCII image
*
*  @return void
*/
void image_conversion(unsigned char image[][Maximum_Number_Of_Column],int number_of_rows, int number_of_columns, char ascii[][100])
{
	int max = image[0][0];	///< Variable for max value in image
	int min = image[0][0];	///< Variable for min value in image
	int width = 0;		///< Width of each range of values
	int range1 = 0;		///< Upper bound of range 1
	int range2 = 0;		///< Upper bound of range 2
	int range3 = 0;		///< Upper bound of range 3
	int range4 = 0;		///< Upper bound of range 4
	

	for(int i = 0; i < number_of_rows; i++)
	{	
		for(int j = 0; j < number_of_columns; j++)
		{
			if(image[i][j] > max)
			max = image[i][j];
			else if (image[i][j] < min)
			min = image[i][j];
		}
	}

	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			ascii[i][j] = ' ';
	

	width = ((max - min) / 5);
	range1 = (min + width);
	range2 = ((range1 + 1) + width);
	range3 = ((range2 + 1) + width);
	range4 = ((range3 + 1) + width);

	
	for(int i = 0; i < number_of_rows; i++)
	{
		for(int j = 0; j < number_of_columns; j++)
		{
			if(image[i][j] <= range1)
			{
				ascii[i][j] = '#';
			}
			else if(image[i][j] <= range2)
			{
				ascii[i][j] = 'o';
			}
			else if(image[i][j] <= range3)
			{
				ascii[i][j] = ':';
			}
			else if ( image[i][j] <= range4)
			{
				ascii[i][j] = '.';
			}
			else
			{
				ascii[i][j] = ' ';
			}
		}
	}
}



/**
*  @brief output_to_image writesd the ASCII version of image to a text file 
*  specified in the command line arguments
* 
*  @param textFileName is the file name input from command line
*  @param ascii is a 2-D array of an ASCII image
*  @param number_of_rows is the number of rows in the array
*  @param number_of_columns is the number of columns in the array
*/
void output_to_image(string& textFileName, char ascii[][100], int number_of_rows, int number_of_columns)
{
	fstream dataFile(textFileName.c_str(), ios :: out);

	for(int i = 0; i < number_of_rows; i++)
	{
		for(int j = 0; j < number_of_columns; j++)
		{	
			dataFile << ascii[i][j];
		}

		dataFile << endl;
	}
	
	dataFile.close();
	
}






