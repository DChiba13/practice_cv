#include <opencv2/opencv.hpp>
#include <iostream>

struct ComponentStats
{
  int left;
  int top;
  int width;
  int height;
};
int main(int argc, char **argv)
{
  /*** コマンドライン引数が足らない場合終了 ***/
  if (argc < 2)
  {
    std::cout << "Error : Usage is... " << argv[0] << " [image path]" << std::endl;
    return -1;
  }
  /*** 画像をグレースケールで読み込み ***/
  cv::Mat img = cv::imread(argv[1], 0);
  /*** 画像の読み込みに失敗したら終了 ***/
  if (img.empty())
    return -1;
  /*** ラベリング処理 ***/
  cv::Mat labels, stats, centroids;
  int n = cv::connectedComponentsWithStats(img, labels, stats, centroids);
  std::cout << "n : " << cv::connectedComponentsWithStats(img, labels, stats, centroids) << std::endl;
  /*** ラベル領域の描画 ***/
  ComponentStats component;
  for (int i = 0; i < n; i++)
  {
    /*** 最初の領域は画像の外枠なので無視 ***/
    if (i == 0)
    {
      std::cout << "回ってるよ" << std::endl;
      continue;
    }
    /*** stats変数からラベル領域の矩形情報を取得 ***/
    component.left = stats.at<int>(i, 0);
    component.top = stats.at<int>(i, 1);
    component.width = stats.at<int>(i, 2);
    component.height = stats.at<int>(i, 3);
    /*** ラベル領域を灰色の矩形で描画 ***/
    cv::rectangle(img, cv::Rect(component.left, component.top, component.width, component.height), cv::Scalar(127), 2);

    /*** ラベル値を矩形の左上に書く ***/
    std::stringstream label;
    label  << i;

    cv::putText(img, label.str(), cv::Point(component.left, component.top), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255), 2);
  }

  /*** 結果画像の表示 ***/
  cv::imshow("Preview", img);
  /*** 何かキーが押されるまで待機 ***/
  cv::waitKey(0);
  return 0;
}