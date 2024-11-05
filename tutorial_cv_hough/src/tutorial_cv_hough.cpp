#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char **argv)
{
  /*** コマンドライン引数が足らない場合終了 ***/
  if (argc < 2)
  {
    std::cout << "Error : Usage is... " << argv[0] << " [image path]" << std::endl;
    return -1;
  }
  /*** 画像を読み込み ***/
  cv::Mat src = cv::imread(argv[1], 1), gray;
  /*** 画像の読み込みに失敗したら終了 ***/
  if (src.empty())
    return -1;
  /*** 入力画像をグレースケールに変換 ***/
  cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

  /*** ハフ変換 ***/
  std::vector<cv::Vec2d> lines;
  // Vec2bは2次元のベクトルを表す。
  // 1つ目の要素に直線の距離rho, 2つ目の要素に直線の角度thetaを表す

  /***直線を検出***/
  cv::HoughLines(gray, lines, 1, CV_PI / 180.0, std::stoi(argv[2]));
  //第2引数はrhoの解像度

  // 第3引数はハフ変換における分解能を表す。値が小さいほど距離の分解能が高くなる。

  // 第4引数はハフ変換における角度の分解能を表す。
  // ハフ空間において直線の角度をどれくらいの単位で表現するかを指定
  // CV_PI/180は度数からラジアンへの変換
  // つまり1度単位での分解能を持つことを意味する。

  // 第5引数は直線として検出するために必要なエッジ点の数の閾値を表す
  // エッジ点が80個以上ある直線のみが検出される

  /*** 検出した各直線を描画 ***/
  for (int i = 0; i < lines.size(); i++)
  {
    double rho = lines[i][0];
    double theta = lines[i][1];
    double a = cos(theta), b = sin(theta);
    double x0 = a * rho, y0 = b * rho;
    /*** 端点の設定 ***/
    cv::Point pt1(x0 + 1000 * (-b), y0 + 1000 * a);
    cv::Point pt2(x0 - 1000 * (-b), y0 - 1000 * a);
    /*** 直線の描画 ***/
    cv::line(src, pt1, pt2, cv::Scalar(0, 0, 255), 1);
  }
  /*** 結果画像をウィンドウに表示 ***/
  cv::imshow("Preview", src);
  /*** 何かキーが押されるまで待機 ***/
  cv::waitKey(0);
  return 0;
}