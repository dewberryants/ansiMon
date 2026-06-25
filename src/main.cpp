#include "ui/ui.hpp"
#include "state/game_state.hpp"


int main() {
    using namespace ftxui;

    int selectedTab = 0;

    state::GameState state = state::GameState{};
    UI::UIHandler ui;

    ScreenInteractive screen = ScreenInteractive::FitComponent();

    Component exitButton = Button("Quit", screen.ExitLoopClosure(), ButtonOption::Ascii());

    Component gameTab = state.world.currentScene.get()->GetRenderer();
    Component creaturesTab = ui.creatures.GetRenderer();
    Component inventoryTab = ui.inventory.GetRenderer();
    Component settingsTab = ui.settings.GetRenderer();

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
  
    screen.Loop(mainRenderer);
}