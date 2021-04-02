#include "Decompression_File_Writer.h"


Decompression_File_Writer::Decompression_File_Writer(){}

void Decompression_File_Writer::Set_Data( std::string file_name , std::string decoded_message )
{
    File_Name = file_name ;
    Decoded_Message = decoded_message ; 
}

void Decompression_File_Writer::Open_File()
{
    F.open(File_Name,std::ios::out ) ;
    
    Check_File() ;
}

void Decompression_File_Writer::Check_File()
{
    if ( F.is_open() )
        Write_In_File() ;
    else
        Generate_Error("Output file could not be opened ") ;
}

void Decompression_File_Writer::Write_In_File()
{
    F << Decoded_Message ;
    
    Close_File() ;
}

void Decompression_File_Writer::Close_File()
{
    F.close() ;
}

void Decompression_File_Writer::Generate_Error( std::string Message )
{
    std::cout << Message << std::endl ;
}

Decompression_File_Writer::~Decompression_File_Writer(){}
