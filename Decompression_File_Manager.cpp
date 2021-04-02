#include "Decompression_File_Manager.h"


Decompression_File_Manager::Decompression_File_Manager()
{
    Binary_255 = "00000000000000000000000011111111" ;
    decoder = new Decoder() ;
}

void Decompression_File_Manager::Set_Data( std::string encoded_file, std::string output_file_path, std::string table_file_path)
{
    Encoded_File = encoded_file ;
    Output_File_Path = output_file_path ;
    Table_File_Path = table_file_path ;
}

void Decompression_File_Manager::Open_Files()
{
    E.open(Encoded_File,std::ios::in) ;
    T.open(Table_File_Path,std::ios::in) ;
    
    Check_Files() ;
}

void Decompression_File_Manager::Check_Files()
{
    if ( (E.is_open()) && (T.is_open()) )
        Read_Table() ;
    else
        Generate_Error("Files could not be opened") ;
}

void Decompression_File_Manager::Read_Table()
{
    std::pair<std::string,std::string> row ;
    std::string Row , character , encoding ;

    getline(T,Row) ;
    SizeOfExtension = std::stoi(Row) ;
    while( !T.eof() ){
        getline(T,Row) ;
        encoding = "" ;
        character = Row[0] ;
        for ( int i = 2 ; i < Row.size() ; i++ )
            encoding = encoding + Row[i] ;
        row.first = character ; row.second = encoding ;
        Table.push_back(row) ;
    }

    Read_Encoded_Texts() ;
}

void Decompression_File_Manager::Read_Encoded_Texts()
{
    std::string File_Data ;
    std::getline(E,File_Data) ;
    for ( int i = 0 ; i < File_Data.size() ; i++ )
        Encoded_Message.insert(0, Convert_To_Binary((((unsigned int)File_Data[i])&255))) ;
    Remove_Extension() ;
    
    Close_Files() ;
}

void Decompression_File_Manager::Close_Files()
{
    E.close() ;
    T.close() ;
    
    Decode() ;
}

void Decompression_File_Manager::Decode()
{
    decoder->Set_Data(Output_File_Path,Table,Encoded_Message) ;
    decoder->Decode() ;
}

void Decompression_File_Manager::Generate_Error( std::string Message )
{
    std::cout << Message << std::endl ;
}

std::string Decompression_File_Manager::Convert_To_Binary( unsigned int Decimal )
{
    std::string Binary = "" ;
    for( int i = 0 ; Decimal > 0 ; i++ ){
        Binary.insert(0, std::to_string(Decimal%2)) ;
        Decimal = Decimal / 2 ;
    }
    if ( Binary.size() < 8 ){
        std::string Appended_Binary = "" ;
        for ( int i = 0 ; i < (8-Binary.size()) ; i++ )
            Appended_Binary = Appended_Binary + "0" ;
        Appended_Binary = Appended_Binary + Binary ;
        Binary = Appended_Binary ;
    }
    return Binary ;
}

std::string Decompression_File_Manager::AND( std::string bin1 , std::string bin2 )
{
    std::string ANDED_Binary = "" ;
    for ( int i = 0 ; i < 32 ; i++ ){
        if ( (bin1[i] == '1') && (bin2[i] == '1') )
            ANDED_Binary = ANDED_Binary + bin1[i] ;
        else
            ANDED_Binary = ANDED_Binary + "0" ;
    }
    
    return ANDED_Binary ;
}

void Decompression_File_Manager::Remove_Extension()
{
    Encoded_Message.erase(Encoded_Message.begin(),Encoded_Message.begin()+SizeOfExtension) ;
}

Decompression_File_Manager::~Decompression_File_Manager()
{
    delete decoder ;
}
