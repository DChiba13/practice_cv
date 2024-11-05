#include <opencv2/opencv.hpp>
#include <iostream>
 
int main(int argc, char **argv)
{
  /*** コマンドライン引数が足らない場合終了 ***/
  if(argc < 2){
    std::cout << "Error : Usage is... " << argv[0] << " [image path]" << std::endl;
    return -1;
  }
  /*** 画像をグレースケールで読み込み ***/
  cv::Mat src = cv::imread(argv[1], 0), edge_x, edge_y;
  /*** 画像の読み込みに失敗したら終了 ***/
  if(src.empty()) return -1;
  /*** Sobelフィルタ(X方向)の適用 ***/
  cv::Sobel(src, edge_x, CV_8UC1, 1, 0);
  /*** 結果画像の表示 ***/
  cv::imshow("SobelX", edge_x);
  cv::waitKey(0);
  /*** Sobelフィルタ(Y方向)の適用 ***/
  cv::Sobel(src, edge_y, CV_8UC1, 0, 1);
  /*** 結果画像の表示 ***/
  cv::imshow("SobelY", edge_y);
  /*** 何かキーが押されるまで待機 ***/
  cv::waitKey(0);
  return 0;
}