#include <opencv2/opencv.hpp>
 
int main()
{
  /*** 指定したパスの画像を読み込む ***/
  cv::Mat src = cv::imread("sample_image.jpg");
  /*** 読み込みに失敗したら終了 ***/
  if(src.empty()) return -1;
  /*** 描画用のウィンドウを作成 ***/
  cv::namedWindow("preview");
  /*** ウィンドウに読み込んだ画像表示 ***/
  cv::imshow("preview", src);
  /*** 何かキーが押されるまで待機 ***/
  int key = cv::waitKey(0);
  /*** 描画用のウィンドウを破棄 ***/
  cv::destroyWindow("preview");
  /*** 読み込んだ画像を別名で保存 ***/
  cv::imwrite("sample_image.png", src);
  return 0;
}