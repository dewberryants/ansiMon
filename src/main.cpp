#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/canvas.hpp>
#include "ui.hpp"
#include "game_state.hpp"


int main() {
    using namespace ftxui;

    int selectedTab = 0;

    GameState *state = new GameState();


    ScreenInteractive screen = ScreenInteractive::FitComponent();

    Component exitButton = Button("Quit", screen.ExitLoopClosure(), ButtonOption::Ascii());

    Component gameTab = Renderer([] {
        Canvas c = Canvas(90, 22);
        c.DrawText(0, 0, "This is the game renderer!");
        return canvas(std::move(c));
    });

    Component creaturesTab = Renderer([] { return text("Creatures...") | center; });
    Component inventoryTab = game::MakeInventoryTab(state->player.inventory);
    Component playerTab = Renderer([] { return text("Player...") | center; });
    Component settingsTab = game::MakeSettingsTab(state->settings.musicEnabled, state->settings.volume);

    Component tab = Container::Tab({
        gameTab,
        creaturesTab,
        inventoryTab,
        settingsTab
    }, &selectedTab);

    std::vector<std::string> tabTitles = {
        "| Game",
        "| Creatures",
        "| Inventory",
        "| Settings"
    };

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
                tabToggle->Render()
            }) | size(HEIGHT, EQUAL, 25) | size(WIDTH, EQUAL, 105),
            hbox({
                text("AsciiMon v.0.0.1") | dim, filler(), exitButton->Render() | bold
            })
         });
    });

    Item test1 {1};
    state->player.inventory.items.push_back(test1);
  
    screen.Loop(mainRenderer);
}