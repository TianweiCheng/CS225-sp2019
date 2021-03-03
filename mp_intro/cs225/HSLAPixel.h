/**
 * @file HSLAPixel.h
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#pragma once

namespace cs225 {
  class HSLAPixel {
    public:
      HSLAPixel();
      HSLAPixel(double hue, double saturation, double luminance);
      HSLAPixel(double hue, double saturation, double luminance, double alpha);

      double h;
      double s;
      double l;
      double a;
  };
}