#include "Encoder.h"


Encoder::Encoder()
{
    Encoding = Compressed_Data = Further_Compressed_Data = "" ;
    compression_file_writer = new Compression_File_Writer() ;
    SizeOfExtension = 0 ;
}

void Encoder::Set_Data( std::string output_file_path , std::string table_file )
{
    Output_File_Path = output_file_path ;
    Table_File = table_file ;
}

void Encoder::Encode_Characters( Character * Huffman_Tree , Character * Root )
{
    if ( Huffman_Tree->Get_Left() != NULL ){
        Encoding = Encoding + "0" ;
        Encode_Characters( Huffman_Tree->Get_Left() , Root ) ;
    }
    if ( Huffman_Tree->Get_Right() != NULL ){
        Encoding = Encoding + "1" ;
        Encode_Characters( Huffman_Tree->Get_Right() , Root ) ;
    }
    if ( (Huffman_Tree->Get_Right() == NULL ) && (Huffman_Tree->Get_Left() == NULL) ){
        Huffman_Tree->Set_Encoding(Encoding) ;
        Huffman_Tree->Encode_Character() ;
        Characters.push_back(Huffman_Tree) ;
        Encoding.erase(Encoding.end()-1) ;
    }
    else if ( Huffman_Tree != Root )
        Encoding.erase(Encoding.end()-1) ;
}

void Encoder::Sort_Characters()
{
    Quick_Sort( 0 , (int)Characters.size()-1) ;
}

void Encoder::Compress_Data( std::string Raw_Data )
{
    for ( int i = 0 ; i < Raw_Data.size() ; i++ )
        Compressed_Data = Compressed_Data + Search_Encoding(0,(int)(Characters.size()-1),Raw_Data[i]) ;
    
    Compress_Further() ;
}

void Encoder::Compress_Further()
{
    int i = (int)Compressed_Data.size()-1 ;
    while ( i >= 0 ){
        if ( i-7 >= 0 ){
            Further_Compressed_Data = Further_Compressed_Data + (char)Convert_To_Decimal(Extract_Bits(i-7,i)) ;
            i = i - 8 ;
        }
        else{
            SizeOfExtension = 7 - i ;
            Further_Compressed_Data = Further_Compressed_Data + (char)Convert_To_Decimal(Append(Extract_Bits(0,i),8-i)) ;
            break ;
        }
    }
    
    Write_In_File() ;
}

void Encoder::Write_In_File()
{
    compression_file_writer->Set_Data(Further_Compressed_Data, Output_File_Path,Characters,Table_File,SizeOfExtension) ;
    compression_file_writer->Open_Files() ;
}

int Encoder::Convert_To_Decimal( std::string Binary )
{
    int remainder, Bin = std::stoi(Binary) , Decimal = 0, b = 1 ;
    while (Bin > 0){
        remainder = Bin % 10;
        Decimal = Decimal + remainder * b;
        b *= 2;
        Bin /= 10;
    }
    
    return Decimal ;
}

std::string Encoder::Append(std::string Binary , int NumberOfBits )
{
    std::string Appended_Binary ;
    for ( int i = 0 ; i < NumberOfBits ; i++ )
        Appended_Binary = Appended_Binary + "0" ;
    Appended_Binary = Appended_Binary + Binary ;
    return Appended_Binary ;
}

std::string Encoder::Extract_Bits( int l , int h )
{
    std::string Extracted_Bits = "" ;
    for ( int i = l ; i <= h ; i++ )
        Extracted_Bits = Extracted_Bits + Compressed_Data[i] ;
    return Extracted_Bits ;
}

std::string Encoder::Search_Encoding( int l , int h , int ASCII )
{
    if ( l<=h ) {
        int m = l+(h-l)/2 ;
        if (Characters[m]->Get_ASCII() == ASCII)
            return Characters[m]->Get_Encoding() ;
        if (Characters[m]->Get_ASCII() > ASCII)
            return Search_Encoding(l, m-1, ASCII);
        return Search_Encoding( m+1, h, ASCII);
    }
    return "" ;
}

void Encoder::Quick_Sort( int l , int h )
{
    if ( l < h ){
        int PI = Partition( l , h ) ;
        Quick_Sort(l,PI-1) ;
        Quick_Sort(PI+1,h) ;
    }
}

int Encoder::Partition( int l , int h )
{
    int pivot = Characters[h]->Get_ASCII() ;
    int i = l-1 ;
    
    for (int j = l; j <= h-1; j++){
        if (Characters[j]->Get_ASCII() < pivot){
            i++;
            Swap(i, j);
        }
    }
    Swap(i+1, h);
    return (i+1);
}

void Encoder::Swap( int i , int j )
{
    Character * Temp ;
    Temp = Characters[i] ;
    Characters[i] = Characters[j] ;
    Characters[j] = Temp ;
}

Encoder::~Encoder()
{
    delete compression_file_writer ;
}
