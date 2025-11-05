#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/canvas.hpp>


int main() {
    using namespace ftxui;

    ScreenInteractive screen = ScreenInteractive::FitComponent();

    int selectedTab = 0;
    std::vector<std::string> tabTitles = {
        "| Creatures",
        "| Player",
        "| Inventory",
        "| Settings"
    };

    Component exitButton = Button("Quit", screen.ExitLoopClosure(), ButtonOption::Ascii());

    Component gameRenderer = Renderer([&] {
        Canvas c = Canvas(100, 100);
        c.DrawText(0, 0, "This is the game renderer!");
        return canvas(std::move(c));
    });

    Component tab = Container::Tab({
        gameRenderer,
        gameRenderer,
        gameRenderer,
        gameRenderer
    }, &selectedTab);

    MenuOption customMenu = MenuOption::Vertical();
    customMenu.elements_prefix = [] { return text("-O"); };
    customMenu.elements_infix = [] { return text("  |") | dim; };
    customMenu.elements_postfix = [] { return text("-O"); };
    Component tabToggle = Menu(&tabTitles, &selectedTab, customMenu);

    Component layoutContainer = Container::Vertical({
        Container::Horizontal({
            tab,
            tabToggle,
        }),
        exitButton
    });

    Component mainRenderer = Renderer(layoutContainer, [&] {
        return vbox({
            hbox({
                tab->Render() | flex | border,
                tabToggle->Render() | flex
            }),
            hbox({
                text("AsciiMon v.0.0.1") | bold, filler(), exitButton->Render() | bold
            })
        });
    });
  
    screen.Loop(mainRenderer);
}