#include "Personnage.h"
#include "Class.h"

using namespace std;

//Class::Class() : Personnage(), m_class("medecin") {}

Class::Class() : Personnage(), m_class("policier"), m_bonus(3){}


Class::Class(string cl, int bonus) : Personnage::Personnage(),  m_class(cl), m_bonus(bonus)
{
}
