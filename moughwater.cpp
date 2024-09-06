#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

const int FLOOD_MAP = 10; // Assigns the value 10 to amount of values across the 2-D array.
const int FLOOD_HEIGHTS = 10; // Assigns the value 10 to the height of values across the 2-D array.

void print(double heights[10][10]);

void printfloodedAreas(double heights[10][10], double floodLevel)
    {

        for (int i = 0; i < 10; i++)                                        // This entire function will print out the flood map itself.
        {                                                                  // It checks if heights[i][j] is greater than the double floodLevel.
            for (int j = 0; j < 10; j++)                                  // In the event that it is, the void function will print out a "-" to signify the non - flooded areas.
            {                                                            // Otherwise, a "+" will be printed to signify the non - flooded areas.
                if (heights[i][j] > floodLevel)
                {
                    cout << "-" << " ";
                }
                else 
                {
                    cout << "+" << " ";
                }
            }
           cout << "" << endl;
        }
}

void printlowestVal(double arr[FLOOD_MAP][FLOOD_HEIGHTS], double floodLevel)
    {
        double lowestLvl = (floodLevel - arr[0][0]);                            // This void function checks for the coordinates of the lowest value.
        int k = 0;                                                             // Assigning two new ints, k and s, to i and j, we are given the coordinates in our output.
        int s = 0;
        for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (floodLevel > arr[i][j])
            {
                if (lowestLvl > floodLevel - arr[i][j])
                {
                    lowestLvl = floodLevel - arr[i][j];
                    k = i;
                    s = j;
                }
            }
        }
    }
    cout << "Here are the coordinates for the lowest level, friend! :) : " << lowestLvl << ". It's coordinates are (" << k << "," << s << ")." << endl;
    }

    void printhighestVal(double arr[FLOOD_MAP][FLOOD_HEIGHTS], double floodLevel)
    {
        double highestLvl = 0;                   // Similarly to the previous function, this void function checks for the coordinates of the highest value.
        int h = 0;                                                     // Again, we assign h and f, our newly assigned ints, to i and j to get the coordinates in our output.
        int f = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (floodLevel > arr[i][j])
                {
                    if (highestLvl < (floodLevel - arr[i][j]))
                    {
                        highestLvl = (floodLevel - arr[i][j]);
                        h = i;
                        f = j;
                    }
                }
            }
        }
    cout << "And here are the coordinates for the highest level, friend! :) : " << highestLvl << ". It's coordinates are (" << h << "," << f << ")." << endl;
    }

    void printaverageVal(double arr[FLOOD_MAP][FLOOD_HEIGHTS], double floodLevel)
    {
        double sum = 0;                                                      // We calculate the average by added the sum to the floodLevel subtracted by arr[i][j].
        int counter = 0;                                                    // We also add a counter, which will ultimately be divided by the sum to get the average.
        for( int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(floodLevel > arr[i][j])
                {
                    sum += floodLevel - arr[i][j];
                    counter++;
                }
            }
        }
        cout << "Finally, here is the average, friend! :) : " << sum/counter << endl;
    }

int main()
{

    string name;
    string answer2;
    char answer;
    char repeat;
    char floodAnswer;
    string average;
    string highest;
    string lowest;

    double heights[10][10];

        double arr[][FLOOD_MAP] =
    {

        43.2, 44.1, 44.4, 44.2, 45.1, 45.2, 45.6, 46.0, 46.7, 47.0, 
        43.4, 44.3, 44.4, 44.2, 45.7, 45.2, 45.3, 48.0, 48.7, 47.0,  
        43.5, 44.5, 45.4, 44.2, 46.2, 45.2, 45.7, 46.2, 50.7, 44.0,
        43.7, 45.5, 44.4, 48.2, 45.1, 45.2, 51.6, 46.4, 46.7, 44.0,
        44.0, 44.1, 45.4, 48.3, 48.4, 50.2, 50.3, 47.0, 48.7, 45.0, 
        44.2, 44.4, 45.9, 48.2, 48.1, 50.4, 50.6, 47.8, 48.9, 48.0, 
        45.4, 45.3, 46.4, 49.2, 49.7, 50.6, 51.3, 49.0, 49.7, 49.0,  
        46.5, 56.9, 56.9, 50.2, 51.2, 51.4, 52.7, 51.2, 51.7, 50.5, 
        45.7, 45.5, 45.4, 48.2, 46.1, 48.2, 51.6, 48.4, 48.7, 49.0, 
        44.7, 44.1, 45.1, 46.3, 45.1, 47.2, 49.3, 47.9, 47.7, 48.0

    };

    // The program welcomes the user in a humorous manner, as to convince them to try out the program.

    cout << "Psst! Hey, you! Yes, you! You there! What's your name? ";
    cin >> name;
    
    cout << "That's a very nice name, " << name << "! And I'm totally not just saying that so you can try out this program... " << endl;
    cout << "Wait, what? Who said that? Must've been the wind... Um, hey there, " << name << "!" << endl;                                  // The program provides a brief description, then asks the user
    cout << "This program will help you determine the flood level of a certain area.";                                                    // If they would like to give it a go.
    cout << " Would you like to give it a try, maybe? (y/n): ";
    cin >> answer;


    do{
        if(answer == 'y')
    {
        cout << "Awesome! We're so excited to have you trying this program out! \n" << endl;                // Should 'y' be answered, the program responds happily, then continues.
    }

    else if(answer == 'n')
    {
        cout << "Wait, what?! Okay, uh... That was unexpected. Maybe another time? Hopefully?";           // Alternatively, should 'n' be answered, the program responds in a confused manner.

        return 0;
    }

    else
    {
        cout << "Hey, " << answer << " isn't a valid response! That's it, no flood map for you!" << endl;       // Alternatively, again, should the user input anything else, the program responds with a
        cout << "Consider this friendship -- which I just recently discovered we have -- officially over!";     // humorous message.
        return 0;
    }


            cout << "Please enter the flood level to receive a proper map: ";
            double floodLevel;
            cin >> floodLevel;

            printfloodedAreas(arr, floodLevel);                                     // Prints the map.

            printlowestVal(arr, floodLevel);                                           // Prints the lowest value.

            printhighestVal(arr, floodLevel);                                         // Prints the highest value.

            printaverageVal(arr, floodLevel);                                        // Prints the average value.
            
            cout << "And voila! There you have it! Please, please! Hold your applause!" << endl;                // Once everything is outputted, the program will ask if the user would like to repeat.
            cout << "Anyway, that was pretty informative, no? How about you give it another try? ";            // If given a 'y', the program will redirect them back to line 158, where they can input a new value.
            cout << "One more time! Just one more time, maybe! Please? (y/n): ";
            cin >> repeat;
    }
    
    while(repeat != 'n');
    return 0;
}