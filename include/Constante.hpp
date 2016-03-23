#ifndef CONSTANTE_HPP
#define CONSTANTE_HPP

#include <string>

// Constant for Gravity & Mouvement
#define DEFAULT_GRAVITY 9.81
#define DEFAULT_SPEED 1

// Constant for Character
#define CHARACTER_WIDTH 105
#define CHARACTER_HEIGHT 105

// Constant for Chicken
#define CHICKEN_WIDTH 27
#define CHICKEN_HEIGHT 27

// Constant for Cow
#define COW_WIDTH 105
#define COW_HEIGHT 105

// Constant for Tile
#define PATTERN_HEIGHT 15
#define PATTERN_WIDTH 30
#define PATTERN_NBR 10

// Constant for Ground
#define GROUND_Y 933
#define SIZE_MAP_X 10000
#define SIZE_MAP_Y 1080

// Constant for Ressources
#define INIT_STORE_CAPACITY 100
#define TEXT_RESSOURCES_PADDING 10
#define AMOUNT_MONEY_START 50

// Constant for Building
#define DEFAULT_COST_TO_UPGRADE 0
#define MAX_BUILDING_LEVEL 3
#define BUILDING_WIDTH 539
#define BUILDING_HEIGHT 251
#define SIGN_HEIGHT 50
#define SIGN_WIDTH 56
#define PADDING_BAR_BUILDING 20
#define PADDING_A_BUILDING 10
#define PADDING_Y_WORKER_BUILDING 20
#define PADDING_X_WORKER_BUILDING 10
#define PADDING_Y_EVENT_BUILDING 20
#define INIT_NECESSARY_CLICK 12
#define ICON_BUILD_WIDTH 54
#define ICON_BUILD_HEIGHT 54

// Constant for sound
#define DEFAULT_VOLUME_MAINTHEME 40
#define MAX_VOLUME_AMBIANCE 70
#define DEFAULT_VOLUME_ANIMAL 50
#define NBR_ANIMALS 6
#define DEFAUT_VOLUME_FEEDBACK 60

// Constant for Event
#define BONUS_EVENT_RESSOURCE 10

// Constant for Worker
#define DEFAULT_TIME_WORKER 10

std::string const defaultCharPath = "Ressources/Character/";
std::string const defaultTilePath = "Ressources/Tileset/";
std::string const defaultMenuPath = "Ressources/Menu/";
std::string const defaultTilesetPath = "Ressources/Tileset/tileset.png";
std::string const defaultLevelPath = "Ressources/Level/";
std::string const defaultSoundPath = "Ressources/Sound/Musique/";
std::string const defaultFXPath = "Ressources/Sound/FX/";
std::string const defaultObjectPath = "Ressources/Object/";
std::string const defaultFilterPath = "Ressources/Filter/";
std::string const defaultHUDPath = "Ressources/HUD/";
std::string const defaultFontPath = "Ressources/Font/";
std::string const defaultBuildingPath = "Ressources/Object/Building/";
std::string const defaultEventPath = "Ressources/Object/Event/";
std::string const defaultInstaFarmPath = "Ressources/InstaFarm/";
std::string const defaultClimatPath = "Ressources/Object/Climat/";
std::string const defaultShopPath = "Ressources/Object/Shop/";
#endif // CONSTANTES_HPP
