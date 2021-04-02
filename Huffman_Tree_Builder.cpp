#include "Huffman_Tree_Builder.h"


Huffman_Tree_Builder::Huffman_Tree_Builder()
{
    encoder = new Encoder() ;
}

void Huffman_Tree_Builder::Set_Data(  std::vector<Character*> characters , std::string raw_data , std::string output_file_path , std::string table_file )
{
    Raw_Data = raw_data ;
    Characters = characters ;
    _Characters = Characters ;
    Table_File = table_file ;
    Output_File_Path = output_file_path ;
}

void Huffman_Tree_Builder::Build_MinHeap()
{
    for (int i = (int)(Characters.size()/2)-1; i >= 0; i--)
        Heapify( i );
    
    Build_Huffman_Tree() ;
}

void Huffman_Tree_Builder::Build_Huffman_Tree()
{
    int i ;
    while( (int)Characters.size() != 1 ){
        Character * M = new Character() ;
        i = Min() ;
        M->Set_Frequency(Characters[0]->Get_Frequency()+Characters[i]->Get_Frequency()) ;
        M->Set_Character(' ') ;
        M->Set_Probability(Characters[0]->Get_Probability()+Characters[i]->Get_Probability()) ;
        M->Set_Right(Characters[i]) ;
        M->Set_Left(Characters[0]) ;
        Characters.erase(Characters.begin()) ;
        Characters.erase(Characters.begin()+(i-1)) ;
        Insert(M) ;
    }
    Huffman_Tree = Characters[0] ;
    
    Encode_Letters() ;
}

void Huffman_Tree_Builder::Encode_Letters()
{
    encoder->Set_Data(Output_File_Path, Table_File ) ;
    encoder->Encode_Characters( Huffman_Tree , Huffman_Tree ) ;
    encoder->Sort_Characters() ;
    encoder->Compress_Data(Raw_Data) ;
}

void Huffman_Tree_Builder::Heapify( int i )
{
    int smallest = i ;
    int l = (2*i)+1 ;
    int r = (2*i)+2;
 
    if (l < Characters.size() && Characters[l]->Get_Probability() < Characters[smallest]->Get_Probability())
        smallest = l;
    if (r < Characters.size() && Characters[r]->Get_Probability() < Characters[smallest]->Get_Probability())
        smallest = r;
    if (smallest != i){
        Swap(i, smallest);
        Heapify( smallest );
    }
}

void Huffman_Tree_Builder::Insert( Character * m )
{
    Characters.push_back(m) ;
    if ( Characters[(((int)Characters.size())-1)/2]->Get_Frequency() > m->Get_Frequency() )
        Heapify((((int)Characters.size())-1)/2) ;
}

void Huffman_Tree_Builder::Swap( int i , int j )
{
    Character * Temp ;
    Temp = Characters[i] ;
    Characters[i] = Characters[j] ;
    Characters[j] = Temp ;
}

int Huffman_Tree_Builder::Min()
{
    if ( (int)Characters.size() > 2 ){
        if ( Characters[1]->Get_Probability() < Characters[2]->Get_Probability() )
            return 1 ;
        else
            return 2 ;
    }
    else
        return 1 ;
}

Huffman_Tree_Builder::~Huffman_Tree_Builder()
{
    delete encoder ;
}
