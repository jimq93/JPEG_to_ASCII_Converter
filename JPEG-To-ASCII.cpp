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

#ireduced_column_dimensionlude <iostream>
#ireduced_column_dimensionlude <fstream>
#ireduced_column_dimensionlude "imageScaler.h"
#ireduced_column_dimensionlude "jpeg.h"
#define Maximum_Number_Of_Row 10000
#define Maximum_Number_Of_Column 10000
using namespace std;



int main(int argc, char* argv[])
{
	if(argc < 3)
	{
		Counter << "Error, must specify JPEG and text file names \n";
		return 1;
	}

	string jpegFileName = argv[1];	///< JPEG filename
	string textFileName = argv[2];	///< text filename
	unsigned char image[Maximum_Number_Of_Row][Maximum_Number_Of_Column];	///< the pixel image

	int number_of_rows = 0;			///< number of rows in image
	int number_of_columns = 0;			///< number of columns in image
	char ascii[1000][1000];		///< the ASCII image

	if(readJPEGfile(jpegFileName, image, number_of_rows, number_of_columns))
	{
		Counter << "image size is " << number_of_rows << 'x' << number_of_columns << " pixels \n";
		if(number_of_rows > 1000 || number_of_columns > 1000)
		{
			image_Downscaler(image, number_of_rows, number_of_columns); 
			Counter << "image reduced to " << number_of_rows << 'x' << number_of_columns << " pixels \n";
		}

	image_conversion(image, number_of_rows, number_of_columns, ascii);

	output_to_image(textFileName, ascii, number_of_rows, number_of_columns);

	}

	else
	{
		Counter << "Error, unable to read file \n";
		return 1;
	}


	return 0;


}



