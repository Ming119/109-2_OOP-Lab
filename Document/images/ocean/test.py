import cv2;

img_file = "D:\OOP-2\mygame\opensnc-win-0.1.4(1)\opensnc-win-0.1.4\images\ocean.png";
img = cv2.imread(img_file);
height, width, channels = img.shape

name = input("輸出檔案名稱: ");
x1 = int(input("x1: "));
y1 = int(input("y1: "));
w = int(input("w: "));
h = int(input("h: "));
# cv2.line(img, (x1, y1), (x1+w,y1+h), (0,0,255), 2);
crop_img = img[y1:y1+h, x1:x1+w].copy();
try:
    cv2.imwrite("%s.bmp"%name, crop_img);
except Exception as e:
    print(str(e))
cv2.waitKey(0)
cv2.destroyAllWindows();
