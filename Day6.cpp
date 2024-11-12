/* [Day6] 寫出你的第一個OpenCV程式 解析圖片的組成 */

//#include "opencv_color_split.h"
#include "opencv2/opencv.hpp"
#include <opencv2/core/utils/logger.hpp>

using namespace std;

cv::Mat convertSplitChannel(int channel, cv::Mat single_channel);

int main()
{
	// 設定OpenCV的日誌級別為LOG_LEVEL_SILENT，使OpenCV不輸出任何日誌訊息
	cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);

	// 讀取圖片
	cv::Mat img=cv::imread("Lenna.jpg", cv::IMREAD_UNCHANGED);
	printf("圖片大小 高度:%dpx 寬度:%dpx\n", img.rows, img.cols);
	printf("圖片類型:%d\n", img.type());
	printf("圖片深度:%d\n", img.depth()); // 0: CV_8U, 8-bit無號整數
	printf("圖片通道數:%d\n", img.channels());

	vector<cv::Mat> channels;
	// 將分成三個顏色通道
	cv::split(img, channels);
	// 顯示Blue Channel
	cv::imshow("Blue Channel", convertSplitChannel(0, channels.at(0)));
	// 顯示Green Channel
	cv::imshow("Green Channel", convertSplitChannel(1, channels.at(1)));
	// 顯示Red Channel
	cv::imshow("Red Channel", convertSplitChannel(2, channels.at(2)));

	cv::Mat dst;
	// 合併三個通道，重建彩色圖
	cv::merge(channels, dst);
	cv::imshow("merged", dst);

	cv::waitKey(0);

	return 0;
}

// 將每個通道轉換成其通道的顏色
cv::Mat convertSplitChannel(int channel, cv::Mat single_channel)
{
	vector<cv::Mat> dst_channels;
	for (int i=0; i<3; i++)
	{
		// 0:B, 1:G, 2:R
		if (i==channel)
			dst_channels.push_back(single_channel);
		else
			dst_channels.push_back(cv::Mat::zeros(single_channel.rows, single_channel.cols, CV_8UC1)); // CV_8UC1: 8-bit無號單通道 
	}

	cv::Mat dst;
	cv::merge(dst_channels, dst);

	return dst;
}