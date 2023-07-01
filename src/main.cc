#include <elements.hpp>
#include <project1/button.h>
#include <project1/input.h>
#include <project1/label.h>

using namespace cycfi::elements;
using namespace project1;

auto MakeMain() {
  // Main window background color
  constexpr auto bg_color = rgba(35, 35, 37, 255);
  const auto bg_box = rbox(bg_color);
  const auto bg = fixed_size({600, 480}, bg_box);

  auto blue_rbox = layer(margin({10, 10, 10, 10}, label("Hello elements!")),
                         rbox(colors::medium_blue, 10));
  auto track = hsize(6, box(colors::black));
  auto thumb =
      layer(margin({25, 20, 25, 18}, label("“Dogs are my favorite people”")),
            rbox(colors::medium_blue, 10));
  auto funny_slider = slider(thumb, track);
  return hgrid(funny_slider, blue_rbox);
}

auto MakeLogin() {
  constexpr auto lcolor = rgba(213, 213, 213, 255);
  constexpr auto rcolor = rgba(246, 246, 246, 255);
  LabelBuilder label;
  label.caption("Whatever is ok.")
      .font_size(24)
      .font_color(colors::black)
      .background_color(lcolor)
      .margin({0, 100, 0, 0})
      .AlignCenter();

  auto lhs = label.result();

  LabelBuilder caption, button_label;
  caption.caption("Log In")
      .font_size(32)
      .font_color(rgb(117, 117, 117))
      .background_color(rcolor)
      .padding({60, 15, 60, 13})
      .margin({0, 0, 0, 40})
      .AlignCenter()
      .AlignBottom();

  button_label.caption("Log In")
      .font_size(16)
      .font_color(colors::white)
      .padding({60, 15, 60, 13})
      .AlignCenter()
      .AlignTop();

  ButtonBuilder button;
  button.label(button_label);

  InputBuilder username_input, password_input;
  username_input.pre_text("Enter your username")
      .width(300)
      .height(40)
      .AlignCenter();
  password_input.pre_text("Enter your password")
      .width(300)
      .height(40)
      .AlignCenter();

  LabelBuilder tool_sign_up, tool_retrieve_password;
  ButtonBuilder sign_up, retrieve_password;
  tool_sign_up.caption("I have no account")
      .font_color(colors::dim_gray)
      .background_color(rcolor)
      .AlignLeft();
  tool_retrieve_password.caption("Forget my password")
      .font_color(colors::dim_gray)
      .background_color(rcolor)
      .AlignRight();
  sign_up.label(tool_sign_up);
  retrieve_password.label(tool_retrieve_password);

  auto inputs = vtile(username_input.result(), password_input.result());
  auto toolkits = align_center(
      hsize(300, htile(sign_up.result(), retrieve_password.result())));
  LabelBuilder contact_us_label;
  ButtonBuilder contact_us;
  contact_us_label.caption("contact us")
      .font_color(colors::dim_gray)
      .background_color(rcolor)
      .margin({0, 0, 10, 8})
      .AlignRight()
      .AlignBottom();
  contact_us.label(contact_us_label).on_click([](bool) {
    std::cout << "contact us" << std::endl;
  });

  auto rhs =
      hsize(800, vtile(vmin_size(200, caption.result()), inputs, toolkits,
                       MakeButton(button_label), contact_us.result()));
  auto foreground = htile(layer(lhs, fixed_size({400, 618}, box(lcolor))),
                          layer(rhs, fixed_size({800, 618}, box(rcolor))));
  auto background = fixed_size({1200, 618}, box(colors::white));
  return layer(foreground, background);
}

int main(int argc, char *argv[]) {
  app app(argc, argv, "Project1", "com.shelpam.project1");
  window window(app.name());
  window.on_close = [&app]() { app.stop(); };

  view view(window);
  view.content(MakeLogin());

  app.run();
  return 0;
}