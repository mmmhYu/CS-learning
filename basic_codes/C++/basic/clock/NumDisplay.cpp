#include"NumDisplay.h"

int NumDisplay::increase(){
    val++;
    if(val == lim){
        val = 0;
        return 1;
    }
    return 0;
}

int NumDisplay::set_val(int origin){
    val = origin;
    return 1;
}

int NumDisplay::set_lim(int limit){
    lim = limit;
    return 1;
}