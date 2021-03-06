#include "global.hpp"

std::unordered_map<std::string, std::string> gTextures = {};
std::unordered_map<std::string, std::unordered_map<std::string, fea::Animation>> gAnimations = {};
bool gPaintingRuined = false;
bool gMenuOver = false;
bool gChequeDone = false;
int32_t gPlayerQueueNumber = 0;
int32_t gQueueCounter = 0;
int32_t gNoteBrokenState = -1;
int32_t gBrokenNotes = 0;

void setupGlobals()
{
    gTextures = 
    {
        {"player", "data/sprites/player.png"},
        {"crosswordt", "data/sprites/crossword_table.png"},
        {"sudoku", "data/sprites/sudoku.png"},
        {"sudokut", "data/sprites/sudoku_table.png"},
        {"checkt", "data/sprites/check.png"},
        {"cashiert", "data/sprites/cashier_blank.png"},
        {"pillar", "data/sprites/pillar.png"},
        {"outside", "data/sprites/Outside.png"},
        {"bank_bg_b", "data/sprites/bg_back.png"},
        {"bank_bg_f", "data/sprites/bg_front.png"},
        {"bank_mask", "data/sprites/mask.png"},
        {"crossword", "data/sprites/crossword.png"},
        {"say_button", "data/sprites/sayButton.png"},
        {"back_button", "data/sprites/backButton.png"},
        {"childquestion", "data/sprites/childquestion.png"},
        {"heartattack_bg", "data/sprites/heartattack.png"},
        {"ticket_machine", "data/sprites/ticketmachine.png"},
        {"number_texture", "data/sprites/numbers.png"},
        {"sad_mouth", "data/sprites/sadmouth.png"},
        {"arm_up", "data/sprites/heartattackarmup.png"},
        {"arm_down", "data/sprites/heartattackarmdown.png"},
        {"explosion", "data/sprites/explosion.png"},
        {"whiteboard", "data/sprites/whiteboard.png"},
        {"painting", "data/sprites/tavla.png"},
        {"bin", "data/sprites/bin.png"},
        {"sofa", "data/sprites/sofa.png"},
        {"wallpainting", "data/sprites/wallpainting.png"},
        {"menubg", "data/sprites/menu.png"},
        {"menubutton", "data/sprites/menubutton.png"},
        {"hangman_bg", "data/sprites/hangmanbg.png"},
        {"r", "data/sprites/R.png"},
        {"e", "data/sprites/E.png"},
        {"y", "data/sprites/Y.png"},
        {"k", "data/sprites/K.png"},
        {"a", "data/sprites/A.png"},
        {"v", "data/sprites/V.png"},
        {"i", "data/sprites/I.png"},
        {"wrong1", "data/sprites/wrong1.png"},
        {"wrong2", "data/sprites/wrong2.png"},
        {"wrong3", "data/sprites/wrong3.png"},
        {"handnotebg", "data/sprites/openhandbg.png"},
        {"queuenote", "data/sprites/queuenote.png"},
        {"chequebg", "data/sprites/chequebg.png"},
        {"broken1", "data/sprites/broken1.png"},
        {"broken2", "data/sprites/broken2.png"},
        {"notenumbers", "data/sprites/notenumbers.png"},
        {"nocashier", "data/sprites/nocashier.png"},
        {"cashier", "data/sprites/cashier.png"},
        {"cheque_table", "data/sprites/cheque_table.png"},
    };

    gAnimations = 
    {
        {
            "player", 
            {
                {"idle-front",    fea::Animation(glm::vec2(0, (0 * 396)), glm::vec2(124, 396), 4, 8)},
                {"walking-front", fea::Animation(glm::vec2(0, (1 * 396)), glm::vec2(124, 396), 4, 8)},
                {"walking-left",  fea::Animation(glm::vec2(0, (2 * 396)), glm::vec2(124, 396), 4, 8)},
                {"walking-right", fea::Animation(glm::vec2(0, (3 * 396)), glm::vec2(124, 396), 4, 8)},
                {"idle-back",     fea::Animation(glm::vec2(0, (4 * 396)), glm::vec2(124, 396), 1, 8)},
            },
        },
        {
            "ticket_machine", 
            {
                {"idle-front",    fea::Animation(glm::vec2(0.0f, 0.0f), glm::vec2(113, 96), 1, 8)},
            },
        },
        {
            "painting", 
            {
                {"idle-front",    fea::Animation(glm::vec2(0.0f, 0.0f), glm::vec2(40, 116), 1, 8)},
            },
        },
        {
            "crossword", 
            {
                {"idle-front",    fea::Animation(glm::vec2(0.0f, 0.0f), glm::vec2(156, 94), 1, 8)},
            },
        },
        {
            "sudoku", 
            {
                {"idle-front",    fea::Animation(glm::vec2(0.0f, 0.0f), glm::vec2(156, 94), 1, 8)},
            },
        },
        //{
        //    "newspaper", 
        //    {
        //        {"idle-front",    fea::Animation(glm::vec2(0.0f, 0.0f), glm::vec2(), 1, 8)},
        //    },
        //},
        {
            "check", 
            {
                {"idle-front",    fea::Animation(glm::vec2(0.0f, 0.0f), glm::vec2(43, 31), 1, 8)},
            },
        },
        {
            "cashier", 
            {
                {"idle-front",    fea::Animation(glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 1.0f), 1, 8)},
            },
        },
        {
            "outdoors", 
            {
                {"idle-front",    fea::Animation(glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 1.0f), 1, 8)},
            },
        },
        {
            "number", 
            {
                {"0", fea::Animation(glm::vec2((0.0f * 26.0f), 0), glm::vec2(26.0f, 42), 1, 1)},
                {"1", fea::Animation(glm::vec2((1.0f * 26.0f), 0), glm::vec2(26.0f, 42), 1, 1)},
                {"2", fea::Animation(glm::vec2((2.0f * 26.0f), 0), glm::vec2(26.0f, 42), 1, 1)},
                {"3", fea::Animation(glm::vec2((3.0f * 26.0f), 0), glm::vec2(26.0f, 42), 1, 1)},
                {"4", fea::Animation(glm::vec2((4.0f * 26.0f), 0), glm::vec2(26.0f, 42), 1, 1)},
                {"5", fea::Animation(glm::vec2((5.0f * 26.0f), 0), glm::vec2(26.0f, 42), 1, 1)},
                {"6", fea::Animation(glm::vec2((6.0f * 26.0f), 0), glm::vec2(26.0f, 42), 1, 1)},
                {"7", fea::Animation(glm::vec2((7.0f * 26.0f), 0), glm::vec2(26.0f, 42), 1, 1)},
                {"8", fea::Animation(glm::vec2((8.0f * 26.0f), 0), glm::vec2(26.0f, 42), 1, 1)},
                {"9", fea::Animation(glm::vec2((9.0f * 26.0f), 0), glm::vec2(26.0f, 42), 1, 1)}
            }
        },
        {
            "notenumber", 
            {
                {"0", fea::Animation(glm::vec2((0.0f * 57.0f), 0.0f), glm::vec2(57, 57), 1, 1)},
                {"1", fea::Animation(glm::vec2((1.0f * 57.0f), 0.0f), glm::vec2(57, 57), 1, 1)},
                {"2", fea::Animation(glm::vec2((2.0f * 57.0f), 0.0f), glm::vec2(57, 57), 1, 1)},
                {"3", fea::Animation(glm::vec2((3.0f * 57.0f), 0.0f), glm::vec2(57, 57), 1, 1)},
                {"4", fea::Animation(glm::vec2((4.0f * 57.0f), 0.0f), glm::vec2(57, 57), 1, 1)},
                {"5", fea::Animation(glm::vec2((5.0f * 57.0f), 0.0f), glm::vec2(57, 57), 1, 1)},
                {"6", fea::Animation(glm::vec2((6.0f * 57.0f), 0.0f), glm::vec2(57, 57), 1, 1)},
                {"7", fea::Animation(glm::vec2((7.0f * 57.0f), 0.0f), glm::vec2(57, 57), 1, 1)},
                {"8", fea::Animation(glm::vec2((8.0f * 57.0f), 0.0f), glm::vec2(57, 57), 1, 1)},
                {"9", fea::Animation(glm::vec2((9.0f * 57.0f), 0.0f), glm::vec2(57, 57), 1, 1)}
            }
        }
   };
}

const fea::Animation& getAnimation(const std::string& character, const std::string& animation)
{
    // what if it doesn't exist?
    return gAnimations.at(character).at(animation);
}
