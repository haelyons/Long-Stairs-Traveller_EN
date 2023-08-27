#ifndef LOC_DATA_HPP
    #define LOC_DATA_HPP

    #include <vector>
    #include <set>
    #include <map>
    #include <libintl.h>

    #define _(STRING) gettext(STRING)

    #include "colors.hpp"

    struct Door {
        std::map<int, int> chances;
        int up, same, down;
    };

    extern const ColorMap DEFAULT_COLORS;

    struct MapSettings {
        int width, height;
        int ground, wall;
        int door_num;
        int plant_chance, stone_chance, crate_chance;
        ColorMap color;
    };

    /*const struct Location DEFAULT_LOC = {
        "none", 10, 50, 10, 0, 10, 0, 10, 3, 9, -1, 1, "none", "none"
    };*/

    struct Location {
        std::string name;
        int size_min, size_max; // in 5ft squares
        int door_max;
        int plants_min, plants_max, fluid_min, fluid_max;
        int stones_min, stones_max;
        int enemy_min, enemy_max, power_min, power_max;
        int skull_level;
        std::string common_fluid;
        std::string common_enemy;
        MapSettings map_data;
    };

    const unsigned MAX_TROUBLE_GROUP = 50;
    struct TroubleGroup {
        int weight, size;
        const char *name;
        const char *elements[MAX_TROUBLE_GROUP];
    };

    struct TroubleId {
        int group;
        int ingroup_id;
    };

    struct ConcreteLocation {
        int loc_id;
        int x, y, z; // in 5ft squares
        int door_num;
        int plants, fluid;
        int stones;
        int enemy, power;
        int focus[2];
        std::vector<Door> doors;
        std::vector<TroubleId> troubles;
    };

    // walls, grounds and pools
    enum {SQUARE_WALLS = 0, CAVERN_WALLS = 1, DIAGONAL_WALLS = 2};
    enum {COBBLESTONE = 0, GRASS = 1, STONE_BRICK = 2, WOOD_BOARDS = 3, IRON_FLOOR = 4, DIRT_ROAD = 5, SWAMP = 6, SAND = 7, CHESS = 8, GROUND = 9, SOLID_STONE = 10};
    enum {WATER = 0, LAVA = 1, SWAMP_WATER = 2};

    // objects
    enum {HEAVY_FURNITURE = 13, LOW_FURNITURE = 0, SMALL_FURNITURE = 11, CRATES = 1, DOOR = 2, WINDOW = 10, FENCE = 3,
            HEAVY_ROCKS = 14, SMALL_ROCKS = 4, TREE = 5, BUSH = 15};
    enum {LADDER_LEFT = 6, LADDER_RIGHT = 7, LADDER_TOP = 8, LADDER_BOTTOM = 10};

    const unsigned LOC_NUM = 21;
    const struct Location LOC[LOC_NUM] = {
        /*              [size],     door,   [plant],[fluid],[stones],[enemy],[power]    ☠*/
        {_("Пустыня"),     10, 50,     10,     0, 3,   0, 2,   0, 8,   0, 6,   -10, 10,    2, _("Лава или вода"), _("Дракониды или демоны"), {5, 5, SAND, SQUARE_WALLS, 0, 0, 0, 0,
            {DEFAULT_COLORS.walls, DEFAULT_COLORS.ground, 0x58260b, 0x4c220c, DEFAULT_COLORS.stones, DEFAULT_COLORS.font}}}, // water - 0x5d6649
        {_("Лес"),         30, 50,     7,      6, 10,  2, 7,   0, 5,   0, 10,  -10, 10,    2, _("Вода"), _("Звери, монстры или лесные жители"), {5, 5, GRASS, CAVERN_WALLS, 0, 0, 0, 0,
            {DEFAULT_COLORS.walls, DEFAULT_COLORS.ground, DEFAULT_COLORS.plant1, DEFAULT_COLORS.plant2, DEFAULT_COLORS.stones, DEFAULT_COLORS.font}}},
        {_("Болото"),      10, 50,     3,      1, 4,   6, 9,   0, 3,   0, 9,   -5, 20,     4, _("Вода"), _("Монстры, нежить или болотные жители"), {5, 5, SWAMP, SQUARE_WALLS, 0, 0, 0, 0,
            {3356713, DEFAULT_COLORS.ground, 6588277, 5203219, DEFAULT_COLORS.stones, DEFAULT_COLORS.font}}}, // special water 2 - 7177309
        {_("Каменная комната"),10, 40, 5,      0, 1,   0, 3,   0, 10,  0, 7,   -10, 10,    2, _("Вода"), _("Роботы"), {5, 5, SOLID_STONE, SQUARE_WALLS, 0, 0, 0, 0,
            {DEFAULT_COLORS.walls, DEFAULT_COLORS.ground, 13530947, 8421504, DEFAULT_COLORS.stones, DEFAULT_COLORS.font}}},
        {_("Стальная комната"),10, 40, 5,      0, 0,   0, 0,   0, 6,   2, 10,  0, 10,      3, _("Нет"), _("Роботы"), {5, 5, IRON_FLOOR, SQUARE_WALLS, 0, 0, 0, 0,
            {DEFAULT_COLORS.walls, DEFAULT_COLORS.ground, DEFAULT_COLORS.plant1, DEFAULT_COLORS.plant2, DEFAULT_COLORS.stones, DEFAULT_COLORS.font}}},
        /*              [size],     door,   [plant],[fluid],[stones],[enemy],[power]    ☠*/
        {_("Степь"),       10, 50,     10,     1, 4,   0, 5,   0, 6,   0, 8,  -10, 10,     2, _("Вода"), _("Звери или дракониды"), {5, 5, GRASS, SQUARE_WALLS, 0, 0, 0, 0,
            {DEFAULT_COLORS.walls, 10648612, 16247839, 13717504, DEFAULT_COLORS.stones, DEFAULT_COLORS.font}}},
        {_("Деревянная комната"),10,40,5,      0, 5,   0, 2,   0, 3,   0, 8,  -10, 0,      1, _("Вода"), _("Растения или роботы"), {5, 5, WOOD_BOARDS, SQUARE_WALLS, 0, 0, 0, 0,
            {DEFAULT_COLORS.walls, DEFAULT_COLORS.ground, DEFAULT_COLORS.plant1, DEFAULT_COLORS.plant2, DEFAULT_COLORS.stones, DEFAULT_COLORS.font}}},
        {_("Пещера"),      10, 50,     6,      0, 3,   0, 3,   0, 8,   0, 10, 0, 10,       3, _("Вода"), _("Монстры, звери или гоблиноиды"), {5, 5, GROUND, CAVERN_WALLS, 0, 0, 0, 0,
            {DEFAULT_COLORS.walls, DEFAULT_COLORS.ground, DEFAULT_COLORS.plant1, DEFAULT_COLORS.plant2, DEFAULT_COLORS.stones, DEFAULT_COLORS.font}}},
        {_("Площадь"),     30, 70,     10,     0, 2,   0, 1,   0, 1,   0, 10, -10, 10,     2, _("Вода"), _("Роботы"), {5, 5, COBBLESTONE, DIAGONAL_WALLS, 0, 0, 0, 0,
            {DEFAULT_COLORS.walls, DEFAULT_COLORS.ground, DEFAULT_COLORS.plant1, DEFAULT_COLORS.plant2, DEFAULT_COLORS.stones, DEFAULT_COLORS.font}}},
        {_("Адская комната"),20, 50,   6,      1, 4,   0, 5,   0, 6,   0, 8,  -5, 20,      4, _("Лава"), _("Демоны или элементали огня"), {5, 5, COBBLESTONE, SQUARE_WALLS, 0, 0, 0, 0,
            {7995392, 10166787, 13172736, 5768192, 11407376, DEFAULT_COLORS.font}}},
        /*              [size],     door,   [plant],[fluid],[stones],[enemy],[power]    ☠*/
        {_("Пустая комната"),10, 50,   4,      0, 0,   0, 0,   0, 0,   0, 0,  0, 0,        0, _("Нет"), _("Нет"), {5, 5, DIRT_ROAD, SQUARE_WALLS, 0, 0, 0, 0,
            {DEFAULT_COLORS.walls, DEFAULT_COLORS.ground, DEFAULT_COLORS.plant1, DEFAULT_COLORS.plant2, DEFAULT_COLORS.stones, DEFAULT_COLORS.font}}},
        {_("Зимний лес"),  30, 50,     7,      6, 10,  2, 7,   0, 5,   0, 10,  -5, 20,     4, _("Вода"), _("Звери, монстры или лесные жители"), {5, 5, GRASS, CAVERN_WALLS, 0, 0, 0, 0,
            {12895180, 12895180, 13168125, 11643647, DEFAULT_COLORS.stones, DEFAULT_COLORS.font}}}, // перекрасить в снежные тона
        {_("Вулкан"),      10, 50,     10,     0, 3,   0, 2,   0, 8,   2, 6,   0, 15,      3, _("Лава или вода"), _("Дракониды, демоны, элементали огня или земли"), {5, 5, SAND, SQUARE_WALLS, 0, 0, 0, 0,
            {7817521, 4538409, 0x58260b, 0x4c220c, 7817521, DEFAULT_COLORS.font}}}, // песок - пепел
        {_("Стеклянная комната"),10,40,5,      0, 0,   0, 3,   0, 5,   0, 10,  -20, 20,    3, _("Вода"), _("Монстры или роботы"), {5, 5, SWAMP, SQUARE_WALLS, 0, 0, 0, 0,
            {2206670, 9567487, 9567487, 1421225, 2206670, DEFAULT_COLORS.font}}},
        {_("Опасная комната"),10,40,   5,      0, 10,  0, 10,  0, 10,  4, 10,  10, 25,     5, _("Вода"), _("Кто угодно"), {5, 5, CHESS, DIAGONAL_WALLS, 0, 0, 0, 0,
            {9378254, DEFAULT_COLORS.ground, 4807619, 1421225, DEFAULT_COLORS.stones, DEFAULT_COLORS.font}}},
        /*              [size],     door,   [plant],[fluid],[stones],[enemy],[power]    ☠*/
        {_("Кладбище"),    10, 50,     5,      0, 4,   0, 5,   0, 7,   2, 8,   -5, 20,     4, _("Вода"), _("Монстры или нежить"), {5, 5, GRASS, DIAGONAL_WALLS, 0, 0, 0, 0,
            {4671561, 6899490, 13717504, 6766621, 8684676, DEFAULT_COLORS.font}}},
        {_("Чёрная комната"),30, 70,   5,      0, 2,   0, 2,   0, 2,   0, 10,  10, 20,     5, _("Масло"), _("Антиподы"), {5, 5, DIRT_ROAD, SQUARE_WALLS, 0, 0, 0, 0,
            {0x101010, 0, 0x202020, 0x202020, 0x202020, DEFAULT_COLORS.font}}},
        {_("Праздничная комната"),10,50,10,    0, 10,  0, 10,  0, 10,  0, 10,  -20,-20,    0, _("Молоко или горячий шоколад"), _("Кто-то добрый и безобидный"), {5, 5, GRASS, CAVERN_WALLS, 0, 0, 0, 0,
            {16729063, 11283868, 9437945, 16712427, 1207735, DEFAULT_COLORS.font}}},
        {_("Крошечная комната"),4,6,   2,      0, 1,   0, 1,   0, 1,   0, 2,   -10, 0,     1, _("Вода"), _("Монстры или демоны"), {5, 5, DIRT_ROAD, SQUARE_WALLS, 0, 0, 0, 0,
            {DEFAULT_COLORS.walls, DEFAULT_COLORS.ground, DEFAULT_COLORS.plant1, DEFAULT_COLORS.plant2, DEFAULT_COLORS.stones, DEFAULT_COLORS.font}}},
        {_("Осенний лес"), 30, 50,     7,      6, 10,  2, 8,   0, 4,   0, 8,   0, 15,      3, _("Вода"), _("Звери и/или красные"), {5, 5, GRASS, CAVERN_WALLS, 0, 0, 0, 0,
            {DEFAULT_COLORS.walls, 9339676, 16247839, 11930893, DEFAULT_COLORS.stones, DEFAULT_COLORS.font}}},
        /*              [size],     door,   [plant],[fluid],[stones],[enemy],[power]    ☠*/
        {_("Голубые луга"),10, 50,     10,     1, 4,   0, 5,   0, 7,   0, 7,   0, 15,      3, _("Вода"), _("Звери и/или синие"), {5, 5, GRASS, SQUARE_WALLS, 0, 0, 0, 0,
            {7509936, 2395753, 6270751, 1142061, 7509936, DEFAULT_COLORS.font}}}
        
    };

    const unsigned LANDING_DIST = 4,
                   LANDING_NUM = 5;
    const struct ConcreteLocation LANDING[LANDING_NUM] = {
        {-1, 10, 10, 50, 4, 0, 0, 0, 0, 0, {}, {}, {}},
        {-1, 80, 80, 30, 10, 0, 0, 0, 7, 10, {}, {}, {}},
        {-1, 60, 60, 5, 6, 4, 1, 1, 8, 15, {}, {}, {}},
        {-1, 100, 100, 30, 10, 2, 1, 0, 3, 0, {}, {}, {}},
        {-1, 50, 50, 20, 2, 0, 0, 0, 8, 20, {}, {}, {}}
    };

    const unsigned MAX_TROUBLES = 4;
    
#endif
