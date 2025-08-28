#ifndef CONSOLE_COLORS_H
#define CONSOLE_COLORS_H

struct style_t {
    const char* code;
    const char* name;
};

const char* const SET_STYLE     = "\\033[";
const char* const RESET         = "\\033[0m";

const style_t grounds[] = {
    {"3", "FONT"},
    {"4", "BACKGROUND"}
};

const style_t colors[] = {
    {"0", "BLACK"},
    {"1", "RED"},
    {"2", "GREEN"},
    {"3", "YELLOW"},
    {"4", "BLUE"},
    {"5", "PURPLE"},
    {"6", "TURQUOISE"},
    {"7", "WHITE"} 
};

const style_t styles[] = {
    {"1", "BOLD"},
    {"2", "FADED"},
    {"3", "ITALICS"},
    {"4", "UNDERLINED"},
    {"5", "BLINKING"},
    {"9", "CROSSED_OUT"} 
};

#endif
