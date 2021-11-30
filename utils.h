#include <random>

//FUNÇAO PARA VARIAR O DANO DE -3 a +3
class Utils {

    public:
        int dice() {
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> dist(1,7);
            return dist(rng) - 4;
        }
};
