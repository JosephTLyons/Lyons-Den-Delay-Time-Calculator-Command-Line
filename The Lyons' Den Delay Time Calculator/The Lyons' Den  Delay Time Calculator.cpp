//  main.cpp
//  JTL Delay/Reverb Time Calculator
//  Created by Joseph Lyons on 11/7/15.
//  Copyright © 2015 Joseph Lyons. All rights reserved.

#include <iostream>
#include <ctype.h> // for isdigit
#include <iomanip> // for setprecision and setw
#include <unistd.h>// for usleep function

#include "DelayTime.hpp"

using namespace std;

void displayMainInformation();
int  tempoInput();
void calculateAndDisplayAllDelayTimes(int &tempo);

int main()
{
    //made this an array to hold any leftover input (if user types more than necessary)
    char repeatProgram[100] = "";
    
    displayMainInformation();
    
    do
    {
        int tempoNumber = tempoInput();
        
        calculateAndDisplayAllDelayTimes(tempoNumber);
        
        cout << "\nEnter \"Q\" to quit, any other key to repeat program: ";
        cin >> repeatProgram;
        cin.ignore(1);// eats newline
        cout << "\n";
        
    } while (toupper(repeatProgram[0]) != 'Q');
}

void displayMainInformation()
{
    cout << "\n\nThe Lyons' Den Delay/Reverb Time Calculator.";
    cout << "\n--------------------------------------------";
    cout << "\n*BPM input accepts whole numbers only";
    cout << "\n*Millisecond output is rounded to 100ths\n\n";
}

int tempoInput()
{
    char tempoTest[100] = {0};//stored in char, if stored in int, program can break if characters are typed in//tempo can be 100 digits longq
    int tempo = 0;
    
    cout << "Input tempo: ";
    cin.getline(tempoTest, 100);
    
    for (int i = 0; tempoTest[i] != 0; ++i)
    {
        // Gets number and stored it into tempo
        if (isdigit(tempoTest[i]))
            tempo = (tempo * 10) + ((tempoTest[i] - 48));//subtract 48 to convert character (ASCII) to numeric
        
        // If not a number, set that element to null terminator - ends loop
        else
        {
            tempoTest[i] = 0;//set non-numeric to null terminator
            --i; //decrement j to make null terminator show after for loop increments it
        }
    }
    
    return tempo;
}

void calculateAndDisplayAllDelayTimes(int &tempo)
{
    DelayTime delayTime;
    
    delayTime.setPrecisionAndRounding(tempo);
    delayTime.calculateWholeNotes(tempo);
    delayTime.calculateHalfNotes(tempo);
    delayTime.calculateQuarterNotes(tempo);
    delayTime.calculateEighthNotes(tempo);
    delayTime.calculateSixteenthNotes(tempo);
    delayTime.calculateThirtySecondNotes(tempo);
    delayTime.calculateSixtyFourthNotes(tempo);
}
