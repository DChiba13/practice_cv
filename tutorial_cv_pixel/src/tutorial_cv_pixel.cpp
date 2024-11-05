#include <opencv2/opencv.hpp>

int main(int argc, char *argv[])
{
  /*** 画像(src)をコンストラクタから初期化 ***/
  cv::Mat src(480, 640, CV_8UC3);
  /*** 各画素への直接アクセス ***/
  for (int x = 0; x < src.cols; x++)
  {
    for (int y = 0; y < src.rows; y++)
    {
      /*** 青，緑，赤成分に値を代入 ***/
      src.at<cv::Vec3b>(y, x)[0] = 255;
      src.at<cv::Vec3b>(y, x)[1] = 0;
      src.at<cv::Vec3b>(y, x)[2] = 0;
    }
  }
  /*** 描画ウィンドウを生成し画像を表示 ***/
  cv::imshow("preview", src);
  /*** 何かキーが押されるまで待機 ***/
  cv::waitKey(0);
  return 0;
}