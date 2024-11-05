#include <opencv2/opencv.hpp>
#include <iostream>
 
int main(int argc, char* argv[])
{
  /*** コマンドライン引数が足らない場合終了 ***/
  if(argc < 2){
    std::cout << "Error : Usage is... " << argv[0] << " [image path]" << std::endl;
    return -1;
  }
  /*** 画像の読み込み & 宣言 ***/
  cv::Mat src = cv::imread(argv[1], 1), dst;
  /*** 画像の読み込みに失敗したら終了 ***/
  if(src.empty()) return -1;
  /*** srcに3×3のメディアンフィルタを適用 ***/
  medianBlur(src, dst, 3);
  /*** src, dstをウィンドウに表示 ***/
  cv::namedWindow("original");
  cv::namedWindow("filtered");
  cv::imshow("original", src);
  cv::imshow("filtered", dst);
  /*** 何かキーが押されるまで待機 ***/
  cv::waitKey(0);
  return 0;
}