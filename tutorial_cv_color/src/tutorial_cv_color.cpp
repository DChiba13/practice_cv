#include <opencv2/opencv.hpp>
#include <iostream>
/*** 閾値を定数として宣言 ***/
#define MIN_H 60
#define MAX_H 90
#define MIN_S 60
#define MAX_S 255
#define MIN_V 100
#define MAX_V 255
   
int main(int argc, char* argv[])
{
  /*** コマンドライン引数が足らない場合終了 ***/
  if(argc < 2){
    std::cout << "Error : Usage is... " << argv[0] << " [image path]" << std::endl;
    return -1;
  }
  /*** 画像の読み込み ***/
  cv::Mat rgb = cv::imread(argv[1], 1), hsv;
  /*** 画像の読み込みに失敗したら終了 ***/
  if(rgb.empty()) return -1;
  /*** 結果画像を黒ベタ塗りで初期化 ***/
  cv::Mat result(rgb.size(), rgb.type(), cv::Scalar(0, 0, 0));
  /*** 画像の表色系の変換 ***/
  cv::cvtColor(rgb, hsv, cv::COLOR_BGR2HSV);
  /*** 各画素値の読み書き ***/
  for(int x = 0; x < rgb.cols; x++){
    for(int y = 0; y < rgb.rows; y++){
      cv::Vec3b val = hsv.at<cv::Vec3b>(y,x);
      /*** HSVの閾値を確認 ***/
      if(  MIN_H <= val[0] && val[0] <= MAX_H
        && MIN_S <= val[1] && val[1] <= MAX_S
        && MIN_V <= val[2] && val[2] <= MAX_V){
        result.at<cv::Vec3b>(y,x) = rgb.at<cv::Vec3b>(y,x);
      }
    }
  }
  /*画像の保存*/
  cv::imwrite("output.jpg", result);

  cv::namedWindow("preview");
  cv::imshow("preview", result);

  // キーが押されるまで待機
  int key = cv::waitKey(0);

  // 'q'キーが押された場合、画像保存して終了
  if (key == 'q' || key == 'Q') {
    cv::imwrite("output_saved.jpg", result);
  }

  else if(key == cv::waitKey(0))
  {
    std::cout << "何かキーを押したら終了します"<<std::endl;
    /*** 画像の表示 ***/
    cv::namedWindow("preview");
    cv::imshow("preview", result);
    /*** 何かキーが押されるまで待機 ***/
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
  }
}