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

#include <iostream>
#include <fstream>
#include "imageScaler.h"
#define Maximum_Number_Of_Row 1000
#define Maximum_Number_Of_Column 1000
using namespace std;



int main(int argc, char* argv[])
{
	if(argc < 3)
	{
		cout << "Error, must specify JPEG and text file names \n";
		return 1;
	}

	string jpegFileName = argv[1];	///< JPEG filename
	string textFileName = argv[2];	///< text filename
	unsigned char image[Maximum_Number_Of_Row][Maximum_Number_Of_Column];	///< the pixel image

	int number_of_rows = 0;			///< number of rows in image
	int number_of_columns = 0;			///< number of columns in image
	char ascii[100][100];		///< the ASCII image

	if(readJPEGfile(jpegFileName, image, number_of_rows, number_of_columns))
	{
		cout << "image size is " << number_of_rows << 'x' << number_of_columns << " pixels \n";
		if(number_of_rows > 100 || number_of_columns > 100)
		{
			image_Downscaler(image, number_of_rows, number_of_columns); 
			cout << "image reduced to " << number_of_rows << 'x' << number_of_columns << " pixels \n";
		}

	image_conversion(image, number_of_rows, number_of_columns, ascii);

	output_to_image(textFileName, ascii, number_of_rows, number_of_columns);

	}

	else
	{
		cout << "Error, unable to read file \n";
		return 1;
	}


	return 0;


}



