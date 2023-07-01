#ifndef PROJECT1_TEXT_H
#define PROJECT1_TEXT_H

#include <elements.hpp>
#include <string>

using namespace cycfi::elements;

class Text {
public:
  const std::string &caption() const { return caption_; }
  int font_size() const { return font_size_; }
  color font_color() const { return font_color_; }

  Text &caption(const std::string &caption) {
    caption_ = caption;
    return *this;
  }
  Text &font_size(int font_size) {
    font_size_ = font_size;
    return *this;
  }
  Text &font_color(color font_color) {
    font_color_ = font_color;
    return *this;
  }

private:
  std::string caption_ = "";
  int font_size_ = 12;
  color font_color_ = colors::white;
};

#endif // PROJECT1_TEXT_H
