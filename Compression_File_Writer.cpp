#include "Compression_File_Writer.h"



Compression_File_Writer::Compression_File_Writer()
{
    compression_evaluator = new Compression_Evaluator() ;
}

void Compression_File_Writer::Set_Data( std::string compressed_data , std::string output_file_path , std::vector<Character*> characters , std::string table_file , int sizeOfExtension )
{
    Output_File_Path = output_file_path ;
    Compressed_Data = compressed_data ;
    Characters = characters ;
    Table_File = table_file ;
    SizeOfExtension = sizeOfExtension ;
}

void Compression_File_Writer::Open_Files()
{
    O.open( Output_File_Path , std::ios::out ) ;
    T.open( Table_File, std::ios::out ) ;
    
    Check_Files() ;
}

void Compression_File_Writer::Check_Files()
{
    if ( (O.is_open()) && (T.is_open()) )
        Write_In_Files() ;
    else
        Generate_Error("Unable To open output file") ;
}

void Compression_File_Writer::Write_In_Files()
{
    O << Compressed_Data ;
    T << SizeOfExtension << "\n" ;
    for ( int i = 0 ; i < (int)Characters.size() ; i++ ){
        if ( i == (int)Characters.size()-1 )
            T << Characters[i]->Get_Character() << " " << Characters[i]->Get_Encoding() ;
        else
            T << Characters[i]->Get_Character() << " " << Characters[i]->Get_Encoding() << "\n" ;
    }
    
    Close_Files() ;
}

void Compression_File_Writer::Close_Files()
{
    T.close() ;
    O.close() ;
    
    Evaluate_Compression() ;
}

void Compression_File_Writer::Evaluate_Compression()
{
    compression_evaluator->Set_Data( Characters ) ;
    compression_evaluator->Calculate_Ratio() ;
}

void Compression_File_Writer::Generate_Error( std::string Message )
{
    std::cout << Message << std::endl ;
}

Compression_File_Writer::~Compression_File_Writer()
{
    delete compression_evaluator ;
}
