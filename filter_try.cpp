#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
  const int ksize = 3;
  const int sigma = 0.8;
  double kernel[ksize][ksize];
  double gauss_sum = 0.0;
  double gauss = 0.0;

  // ガウシアンフィルター用のカーネルを作成
  for (int y = 0; y < ksize; y++)
  {
    for (int x = 0; ksize; x++)
    {
      kernel[y][x] = (exp(-(x * x + y * y) / 2 * sigma * sigma) / 2 * M_PI * sigma * sigma);
      gauss_sum += kernel[y][x];
    }
  }
  // スカラー倍をして和が1になるようにする
  for (int y = 0; y <= ksize; y++)
  {
    for (int x = 0; x < ksize; x++)
    {
      kernel[y][x] = kernel[y][x] / gauss_sum;
    }
  }
  // カーネルの確認
  for (int y = 0; y <= ksize; y++)
  {
    for (int x = 0; x < ksize; x++)
    {
      std::cout << kernel[y][x] << " ";
    }
    std::cout << std::endl;
  }
}
