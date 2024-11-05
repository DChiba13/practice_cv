#include <opencv2/opencv.hpp>
#include <iostream>
   
int main()
{
  /*** USBカメラの初期化(複数台USBカメラが存在する場合引数で選択) ***/
  cv::VideoCapture cap(0);
  /*** 初期化に失敗したらプログラム終了 ***/
  if(!cap.isOpened()) return -1;
  /*** 描画用のウィンドウを作成 ***/
  cv::namedWindow("preview");
  /*** メインのループ処理 ***/
  while(1){
    cv::Mat src;
    /*** USBカメラから画像を取り込み ***/
    cap >> src;
    /*** 画像をウィンドウに表示 ***/
    imshow("preview", src);
    /*** 30ms待機し，その間に押されたキーを変数keyに格納 ***/
    int key = cv::waitKey(30);
    if(key == 'q') break;
  }
  /*** 描画用のウィンドウを破棄 ***/
  cv::destroyWindow("preview");
  return 0;
}