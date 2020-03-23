# [C++] Extracting Text From Image With OpenCV And Tesseract
Source code for blog post https://machinetalk.org/2020/03/23/c-extracting-text-from-image-with-opencv-and-tesseract/

Build the docker image:
```
docker build -t tesseract-opencv .
```

Clone the repo and run the docker image:
```
git clone https://github.com/ChunML/cpp-opencv-tesseract
cd cpp-opencv-tesseract

docker run -it -v $(PWD):/home/usr/app tesseract-opencv bash
```

Compile the code:
```
mkdir build && cd build
cmake ..
make
```

Run the code:
```
./main
```
