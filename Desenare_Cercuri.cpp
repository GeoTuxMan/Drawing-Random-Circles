#include "/usr/local/include/opencv2/opencv.hpp"
#include "/usr/local/include/opencv2/core/core.hpp"
#include "/usr/local/include/opencv2/core.hpp"
#include "/usr/local/include/opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
// desenare cercuri random
const int NUMBER = 100;
const int DELAY = 5;

const int window_width = 900;
const int window_height = 600;
int x_1 = -window_width/2;
int x_2 = window_width*3/2;
int y_1 = -window_width/2;
int y_2 = window_width*3/2;

static Scalar randomColor( RNG& rng );
int Drawing_Random_Circles( Mat image, char* window_name, RNG rng );
int Displaying_Random_Text( Mat image, char* window_name, RNG rng );

int main(void) {

	int c;

  /// Start creating a window
char window_name[] = "Desenare Cercuri cu OpenCV";
RNG rng(0xFFFFFFFF); //generator de numere
Mat image=Mat::zeros(window_height, window_width, CV_8UC3);
imshow(window_name,image);
waitKey( DELAY );
c=Drawing_Random_Circles(image, window_name, rng);
if(c!=0) return 0;

c=Displaying_Random_Text(image, window_name, rng);
if(c!=0) return 0;

waitKey(0);
return 0;
}

int Drawing_Random_Circles(Mat image, char* window_name, RNG rng)
{
	int lineType=8;
	
	for(int i=0;i<NUMBER;i++) {
		Point center;
		center.x=rng.uniform(x_1, x_2);
		center.y=rng.uniform(y_1, y_2);
		circle( image, center, rng.uniform(0, 300), randomColor(rng),rng.uniform(-1, 9), lineType );
		imshow(window_name,image);
		if(waitKey(DELAY)>=0)
		{
			return -1;
		}
	}
	return 0;
}

static Scalar randomColor(RNG& rng)
{
	int icolor = (unsigned) rng;
	return Scalar(icolor&255, (icolor>>8)&255, (icolor>>16)&255);
}

int Displaying_Random_Text(Mat image, char* window_name, RNG rng)
{
	int lineType=8;
	for(int i=1;i<NUMBER;i++)
	{
		Point org;
		org.x=rng.uniform(x_1,x_2);
		org.y=rng.uniform(y_1,y_2);

		putText(image,"Salut Iri !",org,rng.uniform(0,8),rng.uniform(0,100)*0.05+0.1,randomColor(rng),rng.uniform(1,10),lineType);
		imshow(window_name,image);
		if(waitKey(DELAY)>=0)
		{
			return -1;
		}
	}
	return 0;
}


