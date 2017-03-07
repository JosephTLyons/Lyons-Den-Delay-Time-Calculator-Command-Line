//  main.cpp
//  JTL Delay/Reverb Time Calculator
//  Created by Joseph Lyons on 11/7/15.
//  Copyright © 2015 Joseph Lyons. All rights reserved.

#include <iostream>
#include <iomanip> // for setprecision and setw
#include <ctype.h> // for isdigit
#include <unistd.h>// for usleep function

using namespace std;

void DisplayMainInformation();
int TempoInput();
void CalculateAndDisplayDelayTimes(float Temp);

int main()
{
    char RepeatProgram[100] = "";//made this an array to hold any leftover input (if user types more than necessary)
    
    DisplayMainInformation();
    
    do
    {
        CalculateAndDisplayDelayTimes(TempoInput());
        
        cout << "\nEnter \"Q\" to quit, any other key to repeat program: ";
        cin >> RepeatProgram;
        cin.ignore(1);// eats newline
        cout << "\n";
        
    } while (toupper(RepeatProgram[0]) != 'Q');
}

void DisplayMainInformation()
{
    cout << "\n\nThe Lyons' Den Delay/Reverb Time Calculator.";
    cout << "\n--------------------------------------------";
    cout << "\n*BPM input accepts whole numbers only";
    cout << "\n*Millisecond output is rounded to 100ths\n\n";
}

int TempoInput()
{
    char TempoTest[100] = {0};//stored in char, if stored in int, program can break if characters are typed in//tempo can be 100 digits longq
    int Tempo = 0;
    
    cout << "Input tempo: ";
    
    cin.getline(TempoTest, 100);
    
    for (int LoopControl = 0; TempoTest[LoopControl] != 0; ++LoopControl)
    {
        /* Gets number and stored it into tempo */
        
        if (isdigit(TempoTest[LoopControl]))
            Tempo = (Tempo * 10) + ((TempoTest[LoopControl] - 48));//subtract 48 to convert character (ASCII) to numeric
        
        /* if not a number, set that element to null terminator - ends loop */
        
        else
        {
            TempoTest[LoopControl] = 0;//set non-numeric to null terminator
            --LoopControl; //decrement j to make null terminator show after for loop increments it
        }
    }
    
    return Tempo;
}

void CalculateAndDisplayDelayTimes(float Temp)
{
    const int MILLISECONDS = 60000;//Milliseconds in a minute
    const double USLEEP    = 30000;//delays output - easier to see
    const int MS_SETW      = 7;//Change this to change all setwidth settings
    char MillisecondName[] = "Msec";//Stored in character array so I can change it quickly later
    
    /*-----------------------------------------------------------------------------------------*/
    
    //rounds back to whole after program loops - else it rounds to 100ths on second+ loop
    cout << fixed << setprecision(0);
    cout <<"\nExtracted tempo: " << Temp << "\n\n";
    
    cout << fixed << setprecision(2);//rounds decimals to hundredths
    
    // 1/1 notes
    usleep(USLEEP); cout << " 1/1  = " << setw(MS_SETW) << (MILLISECONDS/Temp)*4
                         << " " << MillisecondName << "\n\n";
    
    // 1/2 notes
    usleep(USLEEP); cout << " 1/2. = " << setw(MS_SETW) << (MILLISECONDS/Temp)*(3.0/1)
                         << " " << MillisecondName <<   "\n";
    
    usleep(USLEEP); cout << " 1/2  = " << setw(MS_SETW) << (MILLISECONDS/Temp)*2
                         << " " << MillisecondName <<   "\n";
    
    usleep(USLEEP); cout << " 1/2T = " << setw(MS_SETW) << (MILLISECONDS/Temp)*(4.0/3)
                         << " " << MillisecondName << "\n\n";
    
    // 1/4 notes
    usleep(USLEEP); cout << " 1/4. = " << setw(MS_SETW) << (MILLISECONDS/Temp)*(3.0/2)
                         << " " << MillisecondName <<   "\n";
    
    usleep(USLEEP); cout << " 1/4  = " << setw(MS_SETW) << (MILLISECONDS/Temp)
                         << " " << MillisecondName <<   "\n";;//starting point
    
    usleep(USLEEP); cout << " 1/4T = " << setw(MS_SETW) << (MILLISECONDS/Temp)*(2.0/3)
                         << " " << MillisecondName << "\n\n";
    
    // 1/8 notes
    usleep(USLEEP); cout << " 1/8. = " << setw(MS_SETW) << (MILLISECONDS/Temp)*(3.0/4)
                         << " " << MillisecondName <<   "\n";
    
    usleep(USLEEP); cout << " 1/8  = " << setw(MS_SETW) << (MILLISECONDS/Temp)/2
                         << " " << MillisecondName <<   "\n";
    
    usleep(USLEEP); cout << " 1/8T = " << setw(MS_SETW) << (MILLISECONDS/Temp)*(1.0/3)
                         << " " << MillisecondName << "\n\n";
    
    // 1/16 notes
    usleep(USLEEP); cout << "1/16. = " << setw(MS_SETW) << (MILLISECONDS/Temp)*(3.0/8)
                         << " " << MillisecondName <<   "\n";
    
    usleep(USLEEP); cout << "1/16  = " << setw(MS_SETW) << (MILLISECONDS/Temp)/4
                         << " " << MillisecondName <<   "\n";
    
    usleep(USLEEP); cout << "1/16T = " << setw(MS_SETW) << (MILLISECONDS/Temp)*(0.5/3)
                         << " " << MillisecondName << "\n\n";
    
    // 1/32 notes
    usleep(USLEEP); cout << "1/32. = " << setw(MS_SETW) << (MILLISECONDS/Temp)*(3.0/16)
                         << " " << MillisecondName <<   "\n";
    
    usleep(USLEEP); cout << "1/32  = " << setw(MS_SETW) << (MILLISECONDS/Temp)/8
                         << " " << MillisecondName <<   "\n";
    
    usleep(USLEEP); cout << "1/32T = " << setw(MS_SETW) << (MILLISECONDS/Temp)*(0.25/3)
                         << " " << MillisecondName << "\n\n";
    
    // 1/64 notes
    usleep(USLEEP); cout << "1/64. = " << setw(MS_SETW) << (MILLISECONDS/Temp)*(3.0/32)
                         << " " << MillisecondName <<   "\n";
    
    usleep(USLEEP); cout << "1/64  = " << setw(MS_SETW) << (MILLISECONDS/Temp)/16
                         << " " << MillisecondName <<   "\n";
    
    usleep(USLEEP); cout << "1/64T = " << setw(MS_SETW) << (MILLISECONDS/Temp)*(0.125/3)
                         << " " << MillisecondName << "\n\n";
    
    usleep(USLEEP); cout << "Seconds per measure: "     << (MILLISECONDS/Temp)/250
                         << "\n";//takes 1/1 note and divides it by 1000 (4/1000=1/250)
}
