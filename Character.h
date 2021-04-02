#include "Includes.h"


class Character
{
    
private:
    
    char character ;
    int Frequency , ASCII ;
    float Probability ;
    std::string Encoding , Encoded_Character ;
    Character * Left , * Right ;
    
public:
    
    Character() ;
    void Set_Character( char c ) ;
    void Set_Frequency( int freq ) ;
    void Set_Probability( float probability ) ;
    void Set_Encoding( std::string encoding ) ;
    void Set_ASII( int ascii ) ;
    void Encode_Character() ;
    void Set_Left( Character * left ) ;
    void Set_Right( Character * right ) ;
    float Get_Probability() ;
    int Get_Frequency() ;
    char Get_Character() ;
    int Get_ASCII() ;
    float Get_LP() ; 
    std::string Get_Encoded_Character() ;
    std::string Get_Encoding() ;
    Character * Get_Left() ;
    Character * Get_Right() ;
    ~Character() ;
    
} ;
