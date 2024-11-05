#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
  /*** コマンドライン引数が足らない場合終了 ***/
  if (argc < 3)
  {
    std::cout << "Error : Usage is... " << argv[0] << " [input img] [template img]" << std::endl;
    return -1;
  }
  /*** 入力画像＆テンプレート画像をグレースケールで読み込み ***/
  cv::Mat src = cv::imread(argv[1], 0);
  cv::Mat temp = cv::imread(argv[2], 0);
  /*** 入力画像，テンプレート画像の読み込みに失敗したら終了 ***/
  if (src.empty() || temp.empty())
    return -1;
  /*** テンプレートマッチングの結果保存用Matの作成 ***/
  cv::Mat result(src.rows - temp.rows + 1, src.cols - temp.cols + 1, CV_32FC1);
  /*** テンプレートマッチング(ZNCC) ***/
  matchTemplate(src, temp, result, cv::TM_CCOEFF_NORMED);
  /*** スコアが最大となる位置の探索 ***/
  double max_score;
  cv::Point max_loc;
  cv::minMaxLoc(result, nullptr, &max_score, nullptr, &max_loc);
  /*** マッチ位置の描画 ***/
  cv::rectangle(src, cv::Rect(max_loc.x, max_loc.y, temp.cols, temp.rows), cv::Scalar(0, 0, 0), 2);
  /*** 結果画像をウィンドウに表示 ***/
  cv::imshow("result", src);
  /*** 何かキーが押されるまで待機 ***/
  cv::waitKey(0);
  return 0;
}