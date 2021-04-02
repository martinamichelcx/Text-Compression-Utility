#include "Compression_File_Manager.h"



Compression_File_Manager::Compression_File_Manager()
{
    NumberOfCharacters = 0 ;
    Raw_Data = "" ;
    huffman_tree_builder = new Huffman_Tree_Builder() ;
}

void Compression_File_Manager::Set_Data( std::string input_file_path , std::string output_file_path , std::string table_file )
{
    Input_File_Path = input_file_path ;
    Output_File_Path = output_file_path ;
    Table_File = table_file ;
}

void Compression_File_Manager::Open_File()
{
    I.open( Input_File_Path , std::ios::in ) ;
    
    Check_File() ;
}

void Compression_File_Manager::Check_File()
{
    if ( I.is_open() )
        Read_File() ;
    else
        Generate_Error("Files could not be opened") ;
}

void Compression_File_Manager::Read_File()
{
    std::vector<char> * characters = new std::vector<char>[256] ;
    
    std::getline(I,Raw_Data) ;
    for ( int i = 0 ; i < Raw_Data.size() ; i++ ){
        characters[(int)(Raw_Data[i])].push_back(Raw_Data[i]) ;
        NumberOfCharacters++ ;
    }
    
    Record_Data( characters ) ;
}

void Compression_File_Manager::Record_Data( std::vector<char> * characters )
{
    for ( int i = 0 ; i < 256 ; i++ ){
        if ( !characters[i].empty() ){
            Character * ch = new Character() ;
            ch->Set_Character(characters[i][0]) ;
            ch->Set_Frequency((int)characters[i].size()) ;
            ch->Set_Probability((float)characters[i].size()/(float)NumberOfCharacters) ;
            ch->Set_ASII( characters[i][0] ) ;
            Characters.push_back(ch) ;
        }
    }
    
    Close_File() ;
}

void Compression_File_Manager::Close_File()
{
    I.close() ;
    
    Build_Huffman_Tree() ;
}

void Compression_File_Manager::Build_Huffman_Tree()
{
    huffman_tree_builder->Set_Data(Characters , Raw_Data , Output_File_Path, Table_File ) ;
    huffman_tree_builder->Build_MinHeap() ;
}

Compression_File_Manager::~Compression_File_Manager()
{
    delete huffman_tree_builder ;
}
