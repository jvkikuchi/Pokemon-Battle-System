#pragma once

class Item {

    private:
        int effect;

    public:
        Item( ) {

        }

        void setEffect(int effect) {
            this->effect = effect;
        }

        int getEffect( ) {
            return this->effect;
        }

        //sobrecarga de funcao
        virtual int getHealingValue() {
            return 0;
        }

};