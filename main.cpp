#include <time.h>
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector> // Pour stocker les options de choix.
using namespace std;
//  TODO:
// Choice ~ option.
// Repeat.
// Add check methods (XML...), couper ou regrouper les lignes selon les balises.


bool choice = false;

string toupp ( string a = "" ) // OK. // https://stackoverflow.com/questions/11635/case-insensitive-string-comparison-in-c
{
    for ( unsigned int i = 0; i < a.length(); i++ )
        {
        a[i] = toupper ( a[i] );
        }
    return a;
}

string tolow ( string a = "" ) // OK. // https://stackoverflow.com/questions/11635/case-insensitive-string-comparison-in-c
{
    for ( unsigned int i = 0; i < a.length(); i++ )
        {
        a[i] = tolower ( a[i] );
        }
    return a;
}

string noLeftSpace ( string stringToLeftCompress = "" ) // OK.
{
    while ( ( isspace ( stringToLeftCompress[0] ) ) && ( stringToLeftCompress.size() > 0 ) )
        {
        //   clog << "stringToLeftCompress: " << stringToLeftCompress << endl; // Tests ok.
        // stringToLeftCompress = stringToLeftCompress.substr(1, stringToLeftCompress.size() - 1);
        stringToLeftCompress = stringToLeftCompress.substr ( 1 );
        }


    return stringToLeftCompress;
}

string noRightSpace ( string stringToRightCompress = "" ) // OK.
{
    while ( ( stringToRightCompress[stringToRightCompress.size() - 1] == ' ' ) && ( stringToRightCompress.size() > 0 ) )
        {
        //   clog << "stringToRightCompress: " << stringToRightCompress << endl; // Tests ok.
        // stringToRightCompress = stringToRightCompress.substr(1, stringToRightCompress.size());
        stringToRightCompress = stringToRightCompress.substr ( 0,  stringToRightCompress.size() - 1 );
        }
    return stringToRightCompress;
}

string tabTo4Spaces ( string tabLine = "" ) // OK.
{
    string spaceLine = "";
    for ( int typographicCharacter = 0; typographicCharacter < tabLine.size(); typographicCharacter++ ) // iMax inclus.
        {
        if ( tabLine [typographicCharacter] != '\t' )
            {
            spaceLine = spaceLine + tabLine [typographicCharacter];
            }
        else
            {
            spaceLine = spaceLine + "    ";
            }
        }

    return spaceLine;
}

string noSpace ( string stringToCompress = " " ) // OK.
{
    string stringCompressed = "";
    for ( int typographicCharacter = 0; typographicCharacter < stringToCompress.size(); typographicCharacter++ ) // iMax inclus.
        {
        if ( stringToCompress [typographicCharacter] != ' ' )
            {
            stringCompressed = stringCompressed + stringToCompress [typographicCharacter];
            }
        }
    return stringCompressed;
}


void iout ( string message = "",  int colorisationFin = 0, int colorisation1 = 1, int colorisation2 = 31 ) // Ok.
{
    // 31 = RED.
    // 1 = bold.
    // 3 = italic.
    // 4 = underline.
    // 0 = normal.
    // 2 effects or color only.
    // 41 = red background...
    printf ( "\033[%dm", colorisation1 );
    printf ( "\033[%dm", colorisation2 );
    cout << message;  // http://www.cplusplus.com/forum/beginner/108474/
    printf ( "\033[%dm", colorisationFin );
}

void ierr ( string message = "",  int colorisationFin = 0, int colorisation1 = 1, int colorisation2 = 31 ) // Ok.
{
    // 31 = RED.
    // 1 = bold.
    // 3 = italic.
    // 4 = underline.
    // 0 = normal.
    // 2 effects or color only.
    // 41 = red background...
    printf ( "\033[%dm", colorisation1 );
    printf ( "\033[%dm", colorisation2 );
    cerr << message;  // http://www.cplusplus.com/forum/beginner/108474/
    printf ( "\033[%dm", colorisationFin );
}

void ok() // TODO!
{
    cout << "ok partiel." << endl;
}


void out ( string text = "" )
{
    cout << text ;
}

int appendFileString ( string file, string str = "" ) // OK // Do NOT forget "\n"...
{
    ofstream monFlux ( file.c_str(), ios::app );

    if ( !monFlux )
        {


        cerr << "ERROR: Impossible to open the file ";
        ierr ( file );
        cerr << " in append mode!" << endl;

        return 1;
        }
    else
        {
        monFlux << str;
        }

    return 0; // Ok.
}

void XML ( string ligne ) // TODO!
{
    /*
    OK if ligne = <?xml version="1.0" encoding="UTF-8"?>
    */


};

int minXML ( string lineMin = "" ) // Ok.
{
    while ( ( lineMin.substr ( 0, 3 ) != "min" ) && ( lineMin.size() > 0 ) )
        {
        lineMin = lineMin.substr ( 1 );
        }
    lineMin = lineMin.substr ( 3 );
    lineMin = noLeftSpace ( lineMin );
    lineMin = lineMin.substr ( 1 ); // Del "=";
    lineMin = noLeftSpace ( lineMin );

    return stoi ( lineMin );
}


int maxXML ( string lineMax = "" ) // Ok.
{
    while ( ( lineMax.substr ( 0, 3 ) != "max" ) && ( lineMax.size() > 0 ) )
        {
        lineMax = lineMax.substr ( 1 );
        }
    lineMax = lineMax.substr ( 3 );
    lineMax = noLeftSpace ( lineMax );
    lineMax = lineMax.substr ( 1 ); // Del "=";
    lineMax = noLeftSpace ( lineMax );

    return stoi ( lineMax );
};




int  number ( string ligne ) // <?number min = 1 max = 42?> // Ok.
{
    int min = minXML ( ligne );
    int max = maxXML ( ligne );
    int result = rand() % max + min; // ints tous inclus.
    return result;
};



string    include ( string test = "" ) // <?include name = "text_verb.xml"?> // Ok.
{
    test = noSpace ( test );
    test =          test.substr ( 15, test.size() - 18 ); // del "?>
    return test;
}


void intro()  // Ok.
{
    iout ( "Text generator\n", 0, 0, 4 );
    cout << "Ceci lit des fichiers de configuration, en choisit un type de paragraphe, \nde phrase, de vocabulaire... au pseudo-hasard." << endl;
    cout << "N\'oubliez pas de relire les résultats, de corriger et d\'améliorer les fichiers \nde configuration." << endl;
    cout << "Aujourd\'hui un texte, bientôt autre chose : musique, image, film..." << endl;
    cout << "Le principe est le même pour n\'importe quel type de fichier, \n(en ASCII de préférence)." << endl;
    iout ( "IMPORTANT: One line in the XML file by item. \n\n" );
}

void traite ( string ligne1 = "" ); // traite needed for read, read needed for traite.

void read ( string test = "" ) // Ok.
{
    ifstream litFichier ( test.c_str(), ios::in );
    if ( !litFichier )
        {
        cerr << "Impossible to open the file ";
        ierr ( test );
        cerr << "!" << endl;
        }
    else
        {
        string ligne;
        while ( getline ( litFichier, ligne ) )
            {
            traite ( ligne );
            }
        litFichier.close();
        }

}


void traite ( string ligne1  ) // TODO!
{

    string    ligne = tabTo4Spaces ( ligne1 );
    ligne = noSpace ( tolow ( ligne ) );

    if ( ligne.substr ( 0, 5 ) == "<\?xml" )
        {
        XML ( ligne1 );
        }

        //<?repeat  min = 1 max = 3?>   ...    </repeat>



    else if ( ligne.substr ( 0, 8 ) == "<\?number" )
        {
        out (    to_string ( number ( ligne ) ) );
        }


    /*
    <choice>
        <option>is running<option/>
        <option>is sleeping<option/>
        <option>is walking<option/>
    </choice>
    */

    else if ( ligne.substr ( 0, 8 ) == "<choice>" )
        {
        choice = true;
// vector.



        }

    else if ( ligne.substr ( 0, 9 ) == "</choice>" )
        {
        choice = false;}

        else if ( ligne.substr ( 0, 9 ) == "<\?include" ) // <?include name = "text_verb.xml"?>
            {
            read ( include ( ligne ) ); // Recursivity ok!!!    :-D

            }

        else if ( ligne.substr ( 0, 6 ) == "<span>" ){// <span>/n</span> // Pas else ! ?

        }
        else if ( ligne.substr ( 0, 7 ) == "</span>" ){// <span>/n</span> // Pas else ! ?
        }
        else // Erreur XML ?
            {
            cout << ligne1  ;
            }


}
    int main()
        {
        srand ( time ( NULL ) ); // No need for better init.
        intro();

        string test =  "text_type1.xml";
        read ( test );
      //  read ( "text_verb.xml" );

        return 0;
        }
