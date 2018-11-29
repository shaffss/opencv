#include <fstream>
#include <iostream>
#include <vector>
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>

int main() {
    //cv::Mat image = cv::imread("XA-MONO2-8-12x-catheter_Frame7.bmp", 0);
	FILE* f = fopen("XA-MONO2-8-12x-catheter_Frame7.bmp", "rb");
	char header[54];
	fread(header, sizeof(char), 54, f);
	int i = 0; //iterator
	int parserArray[16] = {0,2,6,8,10,14,18,22,26,28,30,34,38,42,46,50};


	for(i = 0; i < 16; i++)
	{
		std::cout << "[" << parserArray[i] << "]" << " ";
		if(i == 15) std::cout << *(int*)&header[parserArray[i]];
		else
		{
			if(parserArray[i+1]-parserArray[i] == 4) std::cout << *(int*)&header[parserArray[i]];
			else if(parserArray[i+1]-parserArray[i] == 2) std::cout << *(short*)&header[parserArray[i]];
		}
		std::cout << "\n";
	}
	
	
	

    //cv::imshow("Loaded Image", image);
	system("pause");
    cv::waitKey(0);
    return 0;
}

