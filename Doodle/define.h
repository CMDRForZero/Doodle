/* ! \file define.h
*   \brief Файл содержащий константы
*   \author Охманович Андрей
*   \date 24.12.2020
*/
#ifndef DEFINE_H
#define DEFINE_H

#define VIEW_WIDTH 600
#define VIEW_HEIGHT 800
#define BUTTON_WIDTH 175
#define PLAYER_WIDTH 120
#define MOVE_RANGE 200
#define PLATFORM_WIDTH 120
#define PLATFORM_ONSCREEN 6
#define OFFSET 20

#define BACKGROUND_PATH ":/resource/background.png"
#define PLATFORM_PATH ":/resource/platform.png"
#define PLAYER_LEFT_PATH ":/resource/player_left.png"
#define PLAYER_RIGHT_PATH ":/resource/player_right.png"
#define MAIN_MENU_PATH ":/resource/mainmenu.png"
#define PLAY_PATH ":/resource/play.png"
#define PLAY_HOVER_PATH ":/resource/playhover.png"
#define MENU_PATH ":/resource/menu.png"
#define MENU_HOVER_PATH ":/resource/menuhover.png"

enum verticalDirection{
    UP,
    DOWN
};

enum horizontalDirection{
    LEFT,
    RIGHT,
    STOP
};

enum Data{
    TYPE,
    PLATFORM_TYPE,
    NUMBER_OF_DATA
};

enum objectType{
    PLATFORM,
    NUMBER_OF_OBJECT
};

enum platformType{
    NORMAL,
    NUMBER_OF_PLATFORM
};


#endif // DEFINE_H
