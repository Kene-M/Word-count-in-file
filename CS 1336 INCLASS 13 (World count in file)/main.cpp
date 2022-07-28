/*

    This program will read a file and count the number of characters, words and sentences inside it.

1. Open the input file.
2. Display error message if the file doesn't open and quit the program.
3. while ( read file into the current character )
        If x is a letter or period.
            Increment the number of characters.

        Else if the current character is not a letter or period and previous character is.
            Increment the number of words.

        If a new line was entered.
            Increment the number of sentences.

        Make the previous character hold the value of x in each iteration.

    end while
3. Close the input file.
4. Display the results to the user.

*/

// This program will read a file and count the number of characters, words and sentences inside it.

#include <iostream>
#include <fstream>


using namespace std ;

int main()
{
        // Declare variables.
    ifstream inputFile ;  // To hold the file to be read from.
    char x ;  // To hold the current character being read from the file.
    char prev ;  // To hold the preious character read from the file.
    long numChars = 0 ;  // To hold the number of characters in the file.
    long numSentences = 1 ;  // To hold the number of sentences (lines) in the file.
    long numWords = 0 ;  // To hold the number of words in the file.

        // Open the input file.
    inputFile.open( "info.txt" ) ;

        // Display error message if the file doesn't open.
    if ( !inputFile )
    {
        cout << "File \"info.txt\"" << " could not be opened" << endl ;
    }

        // Process the file if it opens.
    else
    {
            // Let x hold the current character.
        while ( inputFile.get(x) )
        {
                // Increment the number of characters if x is a letter or period.
            if ( (x != ' ' ) && (x != '\t') && (x != '\n') )
                numChars++ ;

                // Increment the number of words if x is not a letter or period and prev is.
            else if ( ( prev != ' ' )  && ( prev != '\t' ) && ( prev != '\n') )
                numWords++ ;

                // Increment the number of sentences if a new line was entered.
            if ( x == '\n' )
                numSentences++ ;

                // Make the previous character hold the value of x in each iteration.
            prev = x ;
        }

                // Close the input file.
            inputFile.close () ;

                // Display the number of characters in the file.
            cout << "The number of characters in file \"info.txt\" is " << numChars << endl ;

                // Display the number of words in the file.
            cout << "The number of words in file \"info.txt\" is " << numWords << endl ;

                // Display the number of sentences in the file.
            cout << "The number of sentences in file \"info.txt\" is " << numSentences << endl ;
    }

    return 0 ;
}

/*

    RUN:

The number of characters in file "info.txt" is 937
The number of words in file "info.txt" is 176
The number of sentences in file "info.txt" is 8

*/
