#include "Character.h"


Character::Character()
{
    Left = Right = NULL ;
    Encoded_Character = "" ;
}

void Character::Set_Character( char c )
{
    character = c ;
}

void Character::Set_Frequency( int freq )
{
    Frequency = freq ;
}

void Character::Set_Probability( float probability )
{
    Probability = probability ;
}

void Character::Set_Encoding( std::string encoding )
{
    Encoding = encoding ;
}

void Character::Set_ASII( int ascii )
{
    ASCII = ascii ;
}

void Character::Encode_Character()
{
    for ( int i = 0 ; i < Frequency ; i++ )
        Encoded_Character = Encoded_Character + Encoding ;
}

void Character::Set_Left( Character * left )
{
    Left = left ;
}

void Character::Set_Right( Character * right )
{
    Right = right ;
}

float Character::Get_Probability()
{
    return Probability ;
}

int Character::Get_Frequency()
{
    return Frequency ;
}

char Character::Get_Character()
{
    return character ;
}

Character * Character::Get_Left()
{
    return Left ;
}

Character * Character::Get_Right()
{
    return Right ;
}

int Character::Get_ASCII()
{
    return ASCII ;
}

float Character::Get_LP()
{
    return (float)Encoding.size()*Probability ;
}

std::string Character::Get_Encoded_Character()
{
    return Encoded_Character ;
}

std::string Character::Get_Encoding()
{
    return Encoding ;
}

Character::~Character(){}
