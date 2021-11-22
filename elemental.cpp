#include "pokemon.cpp"

class Elemental:public Pokemon {

    private:
        int type;
    
    public:
        int getType() {
            return type;
        }
        void setType(int type) {
            this->type = type;
        }
    
};
