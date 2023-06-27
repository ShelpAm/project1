#include <elements.hpp>
#include <iostream>
#include <memory>
#include <project1/application.h>

int main(int argc, char *argv[]) {
  using namespace cycfi::elements;

  // Main window background color
  auto constexpr bkd_color = rgba(35, 35, 37, 255);
  auto background = rbox(bkd_color);
  auto blue_rbox =
      align_center_middle(fixed_size({100, 50}, rbox(colors::medium_blue, 10)));

  app app(argc, argv, "Empty Starter", "com.cycfi.empty-starter");
  window window(app.name());
  window.on_close = [&app]() { app.stop(); };

  view view(window);
  view.content(blue_rbox, background);

  app.run();
  return 0;
}