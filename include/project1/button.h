#ifndef PROJECT1_BUTTON_H
#define PROJECT1_BUTTON_H

#include <elements.hpp>
#include <project1/control.h>
#include <project1/label.h>

using namespace cycfi::elements;

namespace project1 {

inline auto MakeButton(const LabelBuilder &builder) {
  return layered_button(builder.result(),
                        builder.clone().background_color(0.8).result());
}

class ButtonBuilder : public ControlBuilder {
public:
  auto result() const {
    auto result = MakeButton(label_);
    result.on_click = on_click_;
    return result;
  }

  ButtonBuilder &on_click(std::function<void(bool)> callback) {
    on_click_ = callback;
    return *this;
  }

  ButtonBuilder &label(const LabelBuilder &label) {
    label_ = label;
    return *this;
  }

private:
  LabelBuilder label_;
  std::function<void(bool)> on_click_;
  /*
  color font_color_ = colors::black;
  color background_color_ = colors::white;
  int font_size_ = 12;
  std::string caption_ = "button";
  int round_radius_ = 0;
  std::array<float, 4> padding_ = {0, 0, 0, 0};*/
};

} // namespace project1

#endif // PROJECT1_BUTTON_H
