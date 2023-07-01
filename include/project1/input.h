#ifndef PROJECT1_INPUT_H
#define PROJECT1_INPUT_H

#include <elements.hpp>
#include <project1/control.h>
#include <string>

using namespace cycfi::elements;

namespace project1 {

class InputBuilder : public ControlBuilder {
public:
  InputBuilder() = default;

  auto prealign_result() const {
    return fixed_size({width_, height_}, input_box(pre_text_).first);
  }

  auto result() const {
    return valign(vertical_align_,
                  halign(horizontal_align_, prealign_result()));
  }

  InputBuilder &pre_text(const std::string &text) {
    pre_text_ = text;
    return *this;
  }

  InputBuilder &width(int width) {
    width_ = width;
    return *this;
  }

  InputBuilder &height(int height) {
    height_ = height;
    return *this;
  }

  InputBuilder &AlignCenter() {
    ControlBuilder::AlignCenter();
    return *this;
  }

private:
  std::string pre_text_ = "";
  float width_ = 100;
  float height_ = 20;
};

} // namespace project1

#endif // PROJECT1_INPUT_H
