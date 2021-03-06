#ifndef SE4_ENGINECONFIG_H
#define SE4_ENGINECONFIG_H

// SDL2, GLFW
#define SDK SDL2

#if SDK == SDL2
#define SDK_WINDOW Sdl2Window
#define SDK_WINDOW_H "Sdl2Window.h"
#define SDK_INPUT Sdl2Input
#define SDK_INPUT_H "Sdl2Input.h"
#define SDK_RENDERER Sdl2RenderUpdater
#define SDK_RENDERER_H "Sdl2RenderUpdater.h"
#elif SDK == GLFW
#define SDK_WINDOW GlfwWindow
#define SDK_WINDOW_H "GlfwWindow.h"
#endif
#define SharedDataID std::string
using LevelID = int;
using WindowID = int;
using TextureID = int;

#endif //SE4_ENGINECONFIG_H
