#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include <chrono>
#include <leptonica/allheaders.h>
#include <tesseract/baseapi.h>
#include <opencv2/opencv.hpp>

int main() {
  std::string imagePath = "../images";
  cv::Mat image;

  tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
  api->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);
  api->SetPageSegMode(tesseract::PSM_AUTO);
  api->SetVariable("debug_file", "tesseract.log");

  for (const auto &fn : std::filesystem::directory_iterator(imagePath)) {
    auto start = std::chrono::steady_clock::now();
    auto filepath = fn.path();
    std::cout << "Detecting text in " << filepath << std::endl;

    image = cv::imread(filepath, 1);

    api->SetImage(image.data, image.cols, image.rows, 3, image.step);
    std::string outText = api->GetUTF8Text();
    std::cout << outText << std::endl;

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> diff = end - start;
    std::cout << "Computation time: " << diff.count() << "ms" << std::endl;
  }
  api->End();
}