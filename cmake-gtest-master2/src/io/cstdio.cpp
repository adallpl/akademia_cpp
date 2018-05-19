#include <cstdio>
#include <cstdlib> // for std::exit

using namespace std;

int main() {
    // FILE* - used to identify "stream"
    // fopen - opens file, args: file name and mode ("w" - write)
    // Detailed meaning of these flags:
    // http://en.cppreference.com/w/cpp/io/basic_filebuf/open

    // output formatowany
    const char* path = "plik.txt";
    FILE* file = fopen(path, "w");

    // Failed to open the file, print message and end program
    if (file == nullptr) {
        // stderr - standard error (diagnostic) output
        // stdout - standard output
        // stdin  - standard input
        fputs("Could not open file\n", stderr); // wyjscie standardowe bledu
        fputs("asdf", stdout);
        exit(1);
    }

    // output nieformatowany
    const int SIZE = 10;
    int data[SIZE];
    // Fill it with some data pattern
    for (int i = 0; i < SIZE; ++ i) {
        data[i] = 0x40302010;
    }
    // Write 10 data items, each of size sizeof(int)
    // array name = pointer to its beginning
    int written = fwrite(data, sizeof(int), SIZE, file); // dane do zapisania, rozmair pojed elelentu, rozmiar danych, gdzie chcemuy zapisac
    // zwraca ilsoc obiekotw ktore udalo sie zapisac

    // Less objects successfully written than we wanted = error
    if (written < SIZE) {
        // %d - integer, %s - string // pisze stringa razem z odpowiednio sformatowanymi danymi
        fprintf(stderr, "Error, only written %d items to file %s\n", written, path);
    }

    long pos = ftell(file); // pobieramy miejsce w ktorym jetesmy
    // %ld - long int
    printf("Current position in file: %ld\n", pos);

    // Move 10 bytes before the end of file
    fseek(file, -10, SEEK_END); // o ile chcemu sie poryuszcac, dokad( chcemy przejsc 30 bajtow od konca pliku
    printf("Current position in file: %ld\n", ftell(file));
    // Move 5 bytes forward
    fseek(file, 5, SEEK_CUR); // o 5 bajtow od pozycji current
    printf("Current position in file: %ld\n", ftell(file));

    // Write some data at that location
    fputc('A', file);
    fputc('L', file);
    fputc('A', file);

    fseek(file, 2, SEEK_SET); // pozycja bezwzgledna,
    printf("Current position in file: %ld\n", ftell(file));
    fputs("Kot", file);

    // Error, can't seek before the end of file
    // (but seeking past the end of file is OK)
    if (fseek(file, -10, SEEK_CUR) < 0) { // wyjscie poza poczatek pliku
        // prints error message based on value of global variable 'errno' set by C calls
        perror("Error seeking before start of file");
    }
    // Cannot read from file opened for writing only
    int ch = fgetc(file); // czyta poj. znak
    // same as printf("Is ...", ..)
    fprintf(stdout, "Is the error flag set? %d\n", ferror(file));
    // Remove the error flag
    clearerr(file);
    fprintf(stdout, "Is the error flag set after clearerr? %d\n", ferror(file));


    fclose(file); // we need to manually close the opened file
    // remove(path);
}
