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
  for (int i = 0; i < n; i++)
  {
    /*** 最初の領域は画像の外枠なので無視 ***/
    if (i == 0)
    {
      std::cout << "回ってるよ" << std::endl;
      continue;
    }
    /*** stats変数からラベル領域の矩形情報を取得 ***/
    int x = stats.at<int>(i, cv::CC_STAT_LEFT);
    int y = stats.at<int>(i, cv::CC_STAT_TOP);
    int w = stats.at<int>(i, cv::CC_STAT_WIDTH);
    int h = stats.at<int>(i, cv::CC_STAT_HEIGHT);
    /*** ラベル領域を灰色の矩形で描画 ***/
    cv::rectangle(img, cv::Rect(x, y, w, h), cv::Scalar(127), 2);
  }

  /*** 結果画像の表示 ***/
  cv::imshow("Preview", img);
  /*** 何かキーが押されるまで待機 ***/
  cv::waitKey(0);
  return 0;
}