//
// Created by ssm on 20. 11. 10..
//

#include "window/Window.h"
#include "window/Sdl2Window.h"
#include "core/Game.h"
#include "SDL.h"

namespace se4 {
    // 2020.11.11 non null terminated 문자열 넘겨도 잘 되는거 확임 함
    Window::Window(WindowID id, std::string_view title, int width, int height)
            : id(id), Sdl2Window(), title(title), width(width), height(height) {
        window = SDL_CreateWindow(
                title.data(),
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                width,
                height,
                SDL_WINDOW_SHOWN
        );
    }

    Window::~Window() {
        SDL_DestroyWindow(window);
    }

    auto Window::setRenderLevel(LevelID lvl_id) -> void {
        level_id = lvl_id;
    }

    auto Window::renderingLevelId() const -> LevelID {
        return level_id;
    }

    Sdl2Window::Sdl2Window() {
        std::call_once(isInit, []() {
            SDL_Init(SDL_INIT_EVERYTHING);
            std::atexit(SDL_Quit);
        });
    }
}