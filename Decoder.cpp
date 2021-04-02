#include "Decoder.h"



Decoder::Decoder()
{
    Decoded_Message = "" ;
    dfile_writer = new Decompression_File_Writer() ;
}

void Decoder::Set_Data( std::string output_file_path , std::vector<std::pair<std::string,std::string> > table , std::string encoded_message )
{
    Encoded_Message = encoded_message ;
    Table = table ;
    Output_File_Path = output_file_path ;
}

void Decoder::Decode()
{
    std::string Extracted_Bits = "" , Search_Result ="" ;
    int i = 0 , j = 1 ;
    
    while ( i<(int)Encoded_Message.size() ){
        for ( int k = i ; k < i+j ; k++ )
            Extracted_Bits = Extracted_Bits + Encoded_Message[k] ;
        Search_Result = Search_Table(Extracted_Bits) ;
        if ( Search_Result == "" )
            j++ ;
        else{
            Decoded_Message = Decoded_Message + Search_Result ;
            i = i + j ;
            j = 1 ;
        }
        Extracted_Bits = "" ;
    }
    
    Write_In_File() ;
}

void Decoder::Write_In_File()
{
    dfile_writer->Set_Data( Output_File_Path , Decoded_Message ) ;
    dfile_writer->Open_File() ; 
}

std::string Decoder::Search_Table( std::string extracted_bits )
{
    std::string Search_Result = "" ;
    for ( int i = 0 ; i < Table.size() ; i++ ){
        if ( Table[i].second == extracted_bits ){
            Search_Result = Table[i].first ;
            break ;
        }
    }
    
    return Search_Result ;
}

Decoder::~Decoder()
{
    delete dfile_writer ;
}
