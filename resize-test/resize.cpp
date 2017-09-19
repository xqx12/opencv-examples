//--------------------------------------������˵����-------------------------------------------
//		����˵������OpenCV3������š�OpenCV3���鱾����ʾ������51
//		����������resize�����÷�ʾ��
//		�����������ò���ϵͳ�� Windows 7 64bit
//		������������IDE�汾��Visual Studio 2010
//		������������OpenCV�汾��	3.0 beta
//		2014��11�� Created by @ǳī_ë����
//		2014��12�� Revised by @ǳī_ë����
//------------------------------------------------------------------------------------------------



//---------------------------------��ͷ�ļ��������ռ�������֡�----------------------------
//		����������������ʹ�õ�ͷ�ļ��������ռ�
//------------------------------------------------------------------------------------------------
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

//-----------------------------------��main( )������--------------------------------------------
//		����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼ
//-----------------------------------------------------------------------------------------------
int main(int argc, char* argv[] )
{
	if(argc!=2) return 1;
#ifndef AFL_FUZZ
	//����ԭʼͼ   
	Mat srcImage = imread(argv[1]);  //����Ŀ¼��Ӧ����һ����Ϊ1.jpg���ز�ͼ
	if(!srcImage.data) return 1;
	Mat tmpImage,dstImage1,dstImage2;//��ʱ������Ŀ��ͼ�Ķ���
	tmpImage=srcImage;//��ԭʼͼ������ʱ����

	//��ʾԭʼͼ  
	imshow("��ԭʼͼ��", srcImage);  

	//���гߴ��������
	resize(tmpImage,dstImage1,Size( tmpImage.cols/2, tmpImage.rows/2 ),(0,0),(0,0),3);
	resize(tmpImage,dstImage2,Size( tmpImage.cols*2, tmpImage.rows*2 ),(0,0),(0,0),3);

	//��ʾЧ��ͼ  
	imshow("��Ч��ͼ��֮һ", dstImage1);  
	imshow("��Ч��ͼ��֮��", dstImage2);  

	waitKey(0);  
#else
	Mat srcImage = imread(argv[1]);  //����Ŀ¼��Ӧ����һ����Ϊ1.jpg���ز�ͼ
	if(!srcImage.data) return 1;
	Mat tmpImage,dstImage1,dstImage2;//��ʱ������Ŀ��ͼ�Ķ���
	tmpImage=srcImage;//��ԭʼͼ������ʱ����

	resize(tmpImage,dstImage1,Size( tmpImage.cols/2, tmpImage.rows/2 ),(0,0),(0,0),3);
	resize(tmpImage,dstImage2,Size( tmpImage.cols*2, tmpImage.rows*2 ),(0,0),(0,0),3);
#endif
	return 0;  
}
