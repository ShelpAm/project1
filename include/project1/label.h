#ifndef PROJECT1_LABEL_H
#define PROJECT1_LABEL_H

#include <elements.hpp>
#include <project1/control.h>

using namespace cycfi::elements;
using namespace cycfi;

namespace project1 {

class LabelBuilder : public ControlBuilder {
public:
  LabelBuilder() = default;
  LabelBuilder(const LabelBuilder &) = default;
  LabelBuilder &operator=(const LabelBuilder &) = default;

  auto result() const {
    auto background = rbox(background_color_, round_radius_);
    auto result = layer(
        elements::margin(
            {padding_[0], padding_[1], padding_[2], padding_[3]},
            label(caption_).font_color(font_color_).font_size(font_size_)),
        background);
    return valign(
        vertical_align_,
        halign(horizontal_align_,
               elements::margin(
                   {margin_[0], margin_[1], margin_[2], margin_[3]}, result)));
  }

  LabelBuilder &font_color(const color color) {
    font_color_ = color;
    return *this;
  }

  LabelBuilder &font_size(const int size) {
    font_size_ = size;
    return *this;
  }

  LabelBuilder &caption(const std::string &caption) {
    caption_ = caption;
    return *this;
  }

  LabelBuilder &round_radius(const int radius) {
    round_radius_ = radius;
    return *this;
  }

  LabelBuilder &background_color(const color &color) {
    background_color_ = color;
    return *this;
  }

  LabelBuilder &background_color(const float level) {
    background_color_ = background_color_.level(level);
    return *this;
  }

  LabelBuilder &padding(const std::array<float, 4> &padding) {
    padding_ = padding;
    return *this;
  }

  LabelBuilder clone() const { return LabelBuilder(*this); }

  LabelBuilder &margin(const std::array<float, 4> &margin) {
    ControlBuilder::margin(margin);
    return *this;
  }

  LabelBuilder &AlignLeft() {
    ControlBuilder::AlignLeft();
    return *this;
  }

  LabelBuilder &AlignCenter() {
    ControlBuilder::AlignCenter();
    return *this;
  }

  LabelBuilder &AlignRight() {
    ControlBuilder::AlignRight();
    return *this;
  }

  LabelBuilder &AlignTop() {
    ControlBuilder::AlignTop();
    return *this;
  }

  LabelBuilder &AlignMiddle() {
    ControlBuilder::AlignMiddle();
    return *this;
  }

  LabelBuilder &AlignBottom() {
    ControlBuilder::AlignBottom();
    return *this;
  }

private:
  color font_color_ = colors::white;
  color background_color_ = rgb(0, 120, 214);
  int font_size_ = 12;
  std::string caption_ = "";
  int round_radius_ = 0;
  std::array<float, 4> padding_ = {0, 0, 0, 0};
};

} // namespace project1

#endif // PROJECT1_LABEL_H
