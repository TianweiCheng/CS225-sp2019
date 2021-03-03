#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>
#include <cmath>
#include <cstdlib>



void rotate(std::string inputFile, std::string outputFile) {
  // TODO: Part 2
  cs225::PNG png;
  png.readFromFile(inputFile);

  cs225::PNG png1(png.width(), png.height());
  for (int i = 0; i < png.width(); ++i) {
    for (int j = 0; j < png.height(); ++j) {
      cs225::HSLAPixel& pixel1 = png.getPixel(i, j);
      cs225::HSLAPixel& pixel2 = png1.getPixel(png.width() - i - 1, png.height() - j - 1);
      pixel2 = pixel1;
    }
  }
  png1.writeToFile(outputFile);
}
cs225::PNG createSpotlight(cs225::PNG image, int centerX, int centerY) {
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      cs225::HSLAPixel & pixel = image.getPixel(x, y);
      unsigned int d = sqrt((centerX-x)*(centerX-x)+(centerY-y)*(centerY-y));
        pixel.h=pixel.h*(1-.005*d);

      // `pixel` is a pointer to the memory stored inside of the PNG `image`,
      // which means you're changing the image directly.  No need to `set`
      // the pixel since you're directly changing the memory of the image.
      pixel.s = 0.5;
    }
  }
  return image;

}
cs225::PNG createSpotlight2(cs225::PNG image, int centerX, int centerY) {
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      cs225::HSLAPixel & pixel = image.getPixel(x, y);
      unsigned int d = sqrt((centerX-x)*(centerX-x)+(centerY-y)*(centerY-y));
        pixel.h=pixel.h*(1-.0005*d);

      // `pixel` is a pointer to the memory stored inside of the PNG `image`,
      // which means you're changing the image directly.  No need to `set`
      // the pixel since you're directly changing the memory of the image.
    }
  }
  return image;

}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3
  
  for (int i = 0; i < png.width(); ++i) {
    for (int j = 0; j < png.height(); ++j) {
      cs225::HSLAPixel &pixel = png.getPixel(i, j);
      pixel.a += 0.4;
      pixel.h += 0.1 * i + 0.1 * j;
      pixel.l += 0.5;
      pixel.s += 0.3;
    }
  }
  return png;
}
