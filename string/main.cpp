#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const size_t MAX_SIZE = 256;
const size_t MAX_EXTENSION = 3;
const char* forbidden =  "*<>?|\"";

int main()
{
    char text[MAX_SIZE];
    cout << "Enter file name: ";
    fgets(text, MAX_SIZE, stdin);
    char* filename = text;
    while(true) {
        if( strcspn( filename, forbidden ) == strlen( filename ) ) ;
        else {
            cout << "Invalid format";
            break;
        }

        if( strchr( filename, ':' ) == nullptr ) ;
        else {
            char* colon = strchr(filename,':');
            if( colon - filename + 1 <= 1 ) {
                cout << "Invalid format";
                break;
            }
            while( colon != nullptr ) {
                if( isalpha( filename[colon - filename - 1] ) > 0 &&
                    filename[colon - filename + 1] == '\\')
                    colon = strchr(colon + 1, ':');
                else {
                    cout << "Invalid format";
                    break;
                }
            }
        }

        if( strrchr( filename, '.' ) == nullptr ) {
            *(filename + strlen(filename) - 1) = '.';                  //strcat не работает
            strcat( filename, "txt" );
        }

        else {
            char* ext = strrchr( filename, '.' );
            for( int i = 1; ext[i] != '\0'; i ++ )
                *(ext + i) = char(tolower(*(ext + i)));
            if( strncmp( ext, ".txt", MAX_EXTENSION + 1 ) == 0 ) ;
                //*( filename + strlen(filename) - 1 ) = '\0';              //problem
            else {
                cout << "Invalid format";
                break;
            }
        }

        FILE* file = fopen( filename, "r" );
        if( file == nullptr ) {
            cout << "Invalid file name";
            break;
        }
        fseek( file, 0, SEEK_END );
        long filesize = ftell( file );

        char* filedata = new char[filesize];
        rewind( file );
        fread( filedata, 1, filesize, file );
        char* fldt = filedata;
        *( fldt + strlen(fldt) - 1 ) = '\0';

        cout << fldt;                              //problem

        char STR[MAX_SIZE];
        cout << "Enter string: ";
        fgets(STR, MAX_SIZE, stdin);
        char* str = STR;
        *( str + strlen(str) - 1 ) = '\0';
        //cout << str;             //problem

        int occur = 0;
        while( strstr( fldt, str ) != nullptr ) {
            occur ++;
            //cout << strstr( filedata, str );
            fldt = strstr( fldt, str ) + 1;
            cout << fldt;
        }
        cout << "Occurance number: " << occur;
        delete[] filedata;
        fclose( file );
        break;
    }
    return 0;
}
