import os
import cv2
from PIL import Image
import pytesseract
import time
import glob


paths = glob.glob("./images/*.png")

for path in paths:
  print(path)
  start = time.time()
  image = cv2.imread(path, 1)
  text = pytesseract.image_to_string(Image.fromarray(image))
  # print(text)
  print("Computation time: {}".format(time.time() - start))
