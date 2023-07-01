#ifndef PROJECT1_CONTROL_H
#define PROJECT1_CONTROL_H

#include <elements.hpp>

namespace project1 {

class ControlBuilder {
public:
  virtual ~ControlBuilder() = 0;

  // virtual cycfi::elements::element &result() = 0;

  ControlBuilder &AlignLeft() {
    horizontal_align_ = 0.0f;
    return *this;
  }

  ControlBuilder &AlignCenter() {
    horizontal_align_ = 0.5f;
    return *this;
  }

  ControlBuilder &AlignRight() {
    horizontal_align_ = 1.0f;
    return *this;
  }

  ControlBuilder &AlignTop() {
    vertical_align_ = 0.0f;
    return *this;
  }

  ControlBuilder &AlignMiddle() {
    vertical_align_ = 0.5f;
    return *this;
  }

  ControlBuilder &AlignBottom() {
    vertical_align_ = 1.0f;
    return *this;
  }

  ControlBuilder &margin(const std::array<float, 4> margin) {
    margin_ = margin;
    return *this;
  }

protected:
  float horizontal_align_ = 0, vertical_align_ = 0;
  std::array<float, 4> margin_ = {0, 0, 0, 0};
};

} // namespace project1

inline project1::ControlBuilder::~ControlBuilder() {}

#endif // PROJECT1_CONTROL_H
