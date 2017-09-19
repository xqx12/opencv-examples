

//--------------------------------------【程序说明】-------------------------------------------
//		程序说明：《OpenCV3编程入门》OpenCV3版书本配套示例程序35
//		程序描述：中值滤波medianBlur函数的使用示例程序
//		开发测试所用操作系统： Windows 7 64bit
//		开发测试所用IDE版本：Visual Studio 2010
//		开发测试所用OpenCV版本：	3.0 beta
//		2014年11月 Created by @浅墨_毛星云
//		2014年12月 Revised by @浅墨_毛星云
//------------------------------------------------------------------------------------------------

//-----------------------------------【头文件包含部分】---------------------------------------
//	描述：包含程序所依赖的头文件
//---------------------------------------------------------------------------------------------- 
#include "opencv2/core/core.hpp" 
#include "opencv2/highgui/highgui.hpp" 
#include "opencv2/imgproc/imgproc.hpp" 

//-----------------------------------【命名空间声明部分】---------------------------------------
//	描述：包含程序所使用的命名空间
//-----------------------------------------------------------------------------------------------  
using namespace cv; 

//-----------------------------------【main( )函数】--------------------------------------------
//	描述：控制台应用程序的入口函数，我们的程序从这里开始
//-----------------------------------------------------------------------------------------------
int main(int argc, char* argv[] )
{ 
	if(argc!=2) return 1;
#ifndef AFL_FUZZ
	// 载入原图
	Mat image=imread(argv[1]); 

	//创建窗口
	namedWindow( "中值滤波【原图】" ); 
	namedWindow( "中值滤波【效果图】"); 

	//显示原图
	imshow( "中值滤波【原图】", image ); 

	//进行中值滤波操作
	Mat out; 
	medianBlur ( image, out, 7);

	//显示效果图
	imshow( "中值滤波【效果图】" ,out ); 

	waitKey( 0 );     
#else
	Mat image=imread(argv[1]); 
	if( !image.data ) return 1;
	Mat out; 
	medianBlur ( image, out, 7);

#endif
	return 0;
} 

