#ifndef TC_STYLE_PRIMS_H
#define TC_STYLE_PRIMS_H

#define GRAPHICS_SET_GRAPHICS_MODE_CODE "\e[%dm"
#define GRAPHICS_RESET_MODE_CODE "\e[0m"

#define STYLE_BOLD_MODE_CODE "\e[1m"
#define STYLE_DIM_MODE_CODE "\e[2m"
#define STYLE_ITALIC_MODE_CODE "\e[3m"
#define STYLE_UNDERLINE_MODE_CODE "\e[4m"
#define STYLE_BLINK_MODE_CODE "\e[5m"
#define STYLE_INVERSE_MODE_CODE "\e[7m"
#define STYLE_HIDDEN_MODE_CODE "\e[8m"
#define STYLE_STRIKETHROUGH_MODE_CODE "\e[9m"
#define STYLE_RESET_CODE "\e[0m"

// Foreground_CODE Colors (Text)
#define COLOR_BLACK_FG_CODE "\e[30m"
#define COLOR_RED_FG_CODE "\e[31m"
#define COLOR_GREEN_FG_CODE "\e[32m"
#define COLOR_YELLOW_FG_CODE "\e[33m"
#define COLOR_BLUE_FG_CODE "\e[34m"
#define COLOR_MAGENTA_FG_CODE "\e[35m"
#define COLOR_CYAN_FG_CODE "\e[36m"
#define COLOR_WHITE_FG_CODE "\e[37m"
#define COLOR_DEFAULT_FG_CODE "\e[39m"

// Background_CODE Colors
#define COLOR_BLACK_BG_CODE "\e[40m"
#define COLOR_RED_BG_CODE "\e[41m"
#define COLOR_GREEN_BG_CODE "\e[42m"
#define COLOR_YELLOW_BG_CODE "\e[43m"
#define COLOR_BLUE_BG_CODE "\e[44m"
#define COLOR_MAGENTA_BG_CODE "\e[45m"
#define COLOR_CYAN_BG_CODE "\e[46m"
#define COLOR_WHITE_BG_CODE "\e[47m"
#define COLOR_DEFAULT_BG_CODE "\e[49m"

#endif
