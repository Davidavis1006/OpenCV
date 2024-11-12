/* [Day5] 使用Visual Studio建立你的第一個OpenCV專案 */

#include <iostream>
#include "opencv2/opencv.hpp"

int main()
{
	// 讀取圖片
	cv::Mat img=cv::imread("Lenna.jpg", cv::IMREAD_UNCHANGED);

	// 顯示圖片
	cv::imshow("Output", img);

	// 等待使用者按下任意按鍵
	cv::waitKey(0);

	// 顯示訊息
	std::cout << "Hello OpenCV!\n";
}