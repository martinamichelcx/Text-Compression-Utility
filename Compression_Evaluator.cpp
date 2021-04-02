#include "Compression_Evaluator.h"



Compression_Evaluator::Compression_Evaluator()
{
    Compression_Ratio = 0.0 ;
}

void Compression_Evaluator::Set_Data( std::vector<Character*> characters )
{
    Characters = characters ;
}

void Compression_Evaluator::Calculate_Ratio()
{
    for ( int i = 0 ; i < Characters.size() ; i++ )
        Compression_Ratio = Compression_Ratio + Characters[i]->Get_LP() ;
    std::cout << "Compression Ratio = " << Compression_Ratio << std::endl ;
    
    Calculate_Efficiency() ;
}

void Compression_Evaluator::Calculate_Efficiency()
{
    for ( int i = 0 ; i < Characters.size() ; i++ )
        Entropy = Entropy + (Characters[i]->Get_Probability()*log2((1/Characters[i]->Get_Probability()))) ;
    
    Efficiency = (Entropy/Compression_Ratio)*100 ;
    
    std::cout << "Compression Efficiency = " << Efficiency << " %" << std::endl ;
}

Compression_Evaluator::~Compression_Evaluator(){}
