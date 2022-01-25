
#include "Class.h"
#include "Type.h"

using namespace std;

Type::Type(string type) : Class("securite", 3), m_type(type) {
    if(type=="policier"){
        m_bonus_pourcentage = 10;
    }
    else if(type=="pompier"){
        m_bonus_pourcentage=5;
    }
    else{
        m_bonus_pourcentage=0;
    }
}