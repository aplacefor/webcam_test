#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <ctype.h>
int main (int argc, char **argv)
{
	IplImage *frame = 0;
	double w = 320, h = 240;
	CvCapture *capture = cvCreateCameraCapture(-1);
	if (capture==NULL) {
		printf("Camera not found.\n");
		return 0;
	}
	cvSetCaptureProperty (capture, CV_CAP_PROP_FRAME_WIDTH, w);
	cvSetCaptureProperty (capture, CV_CAP_PROP_FRAME_HEIGHT, h);
	printf("(w,h)=(%d,%d)\n", w, h);

	// カメラから画像をキャプチャする
	int num = 0;
	char fname[1024];
	while (1) {
		frame = cvQueryFrame(capture);
		// ファイル名
		sprintf(fname, "cap%06d.jpg", num);
		printf("%s\n", fname);

		// ファイルに保存する
		cvSaveImage(fname, frame, NULL);
		sleep(15);
		num++;
	}

	cvReleaseCapture (&capture);
	return 0;
}
