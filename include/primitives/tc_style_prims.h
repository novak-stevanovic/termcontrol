#ifndef TC_STYLE_PRIMS_H
#define TC_STYLE_PRIMS_H

// #define GRAPHICS_SET_GRAPHICS_MODE_CODE "\e[%dm"
#define GRAPHICS_RESET_MODE_CODE "\e[0m"

// TODO
#define STYLE_BOLD_MODE_CODE "\e[1m"
#define STYLE_DIM_MODE_CODE "\e[2m"
#define STYLE_ITALIC_MODE_CODE "\e[3m"
#define STYLE_UNDERLINE_MODE_CODE "\e[4m"
#define STYLE_BLINK_MODE_CODE "\e[5m"
#define STYLE_INVERSE_MODE_CODE "\e[7m"
#define STYLE_HIDDEN_MODE_CODE "\e[8m"
#define STYLE_STRIKETHROUGH_MODE_CODE "\e[9m"

// Foreground Colors 
#define COLOR_FG_CODE "\e[3%dm"

// Background Colors
#define COLOR_BG_CODE "\e[4%dm"

#endif
