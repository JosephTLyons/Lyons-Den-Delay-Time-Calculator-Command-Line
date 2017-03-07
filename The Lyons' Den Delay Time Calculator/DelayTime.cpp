//
//  DelayTime.cpp
//  The Lyons' Den Delay Time Calculator
//
//  Created by Joseph Lyons on 3/7/17.
//  Copyright © 2017 Joseph Lyons. All rights reserved.
//

#include "DelayTime.hpp"

#include <iomanip> // for setprecision and setw
#include <iostream>
#include <unistd.h>// for usleep function

using namespace std;

DelayTime::DelayTime()
{
    MILLISECONDS      = 60000; // Milliseconds in a minute
    USLEEP            = 30000; // Delays output - easier to see
    MS_SETW           = 7;     // Change this to change all setwidth settings
    
    fillMillisecondArrayName();
}

void DelayTime::setPrecisionAndRounding(const int &tempo)
{
    //rounds back to whole after program loops - else it rounds to 100ths on second+ loop
    cout << fixed << setprecision(0);
    cout <<"\nExtracted tempo: " << tempo << "\n\n";
    cout << fixed << setprecision(2);//rounds decimals to hundredths
}

void DelayTime::fillMillisecondArrayName()
{
    // Stored in character array so I can change it quickly later
    MILLISECONDNAME[0] = 'M';
    MILLISECONDNAME[1] = 's';
    MILLISECONDNAME[2] = 'e';
    MILLISECONDNAME[3] = 'c';
    MILLISECONDNAME[4] = '\0';
}

void DelayTime::calculateWholeNotes(const int &tempo)
{
    // 1/1 notes
    usleep(USLEEP);
    
    cout << " 1/1  = " << setw(MS_SETW) << (MILLISECONDS / tempo) * 4
         << " " << MILLISECONDNAME << "\n\n";
}

void DelayTime::calculateHalfNotes(const int &tempo)
{
    // 1/2 notes
    usleep(USLEEP);
    
    cout << " 1/2. = " << setw(MS_SETW) << (MILLISECONDS / tempo) * (3.0 / 1)
         << " " << MILLISECONDNAME <<   "\n";
    
    usleep(USLEEP);
    
    cout << " 1/2  = " << setw(MS_SETW) << (MILLISECONDS / tempo) * 2
         << " " << MILLISECONDNAME <<   "\n";
    
    usleep(USLEEP);
    
    cout << " 1/2T = " << setw(MS_SETW) << (MILLISECONDS / tempo) * (4.0 / 3)
         << " " << MILLISECONDNAME << "\n\n";
}

void DelayTime::calculateQuarterNotes(const int &tempo)
{
    // 1/4 notes
    usleep(USLEEP);
    
    cout << " 1/4. = " << setw(MS_SETW) << (MILLISECONDS / tempo) * (3.0/2)
         << " " << MILLISECONDNAME <<   "\n";
    
    usleep(USLEEP);
    
    cout << " 1/4  = " << setw(MS_SETW) << (MILLISECONDS / tempo)
         << " " << MILLISECONDNAME <<   "\n";;//starting point
    
    usleep(USLEEP);
    
    cout << " 1/4T = " << setw(MS_SETW) << (MILLISECONDS / tempo) * (2.0 / 3)
         << " " << MILLISECONDNAME << "\n\n";
}

void DelayTime::calculateEighthNotes(const int &tempo)
{
    // 1/8 notes
    usleep(USLEEP);
    
    cout << " 1/8. = " << setw(MS_SETW) << (MILLISECONDS / tempo) * (3.0 / 4)
         << " " << MILLISECONDNAME <<   "\n";
    
    usleep(USLEEP);
    
    cout << " 1/8  = " << setw(MS_SETW) << (MILLISECONDS / tempo) / 2
         << " " << MILLISECONDNAME <<   "\n";
    
    usleep(USLEEP);
    
    cout << " 1/8T = " << setw(MS_SETW) << (MILLISECONDS / tempo) * (1.0 / 3)
         << " " << MILLISECONDNAME << "\n\n";
}

void DelayTime::calculateSixteenthNotes(const int &tempo)
{
    // 1/16 notes
    usleep(USLEEP);
    
    cout << "1/16. = " << setw(MS_SETW) << (MILLISECONDS / tempo) * (3.0 / 8)
         << " " << MILLISECONDNAME <<   "\n";
    
    usleep(USLEEP);
    
    cout << "1/16  = " << setw(MS_SETW) << (MILLISECONDS / tempo) / 4
         << " " << MILLISECONDNAME <<   "\n";
    
    usleep(USLEEP);
    
    cout << "1/16T = " << setw(MS_SETW) << (MILLISECONDS / tempo) * (0.5 / 3)
         << " " << MILLISECONDNAME << "\n\n";
}

void DelayTime::calculateThirtySecondNotes(const int &tempo)
{
    // 1/32 notes
    usleep(USLEEP);
    
    cout << "1/32. = " << setw(MS_SETW) << (MILLISECONDS/tempo)*(3.0/16)
         << " " << MILLISECONDNAME <<   "\n";
    
    usleep(USLEEP);
    
    cout << "1/32  = " << setw(MS_SETW) << (MILLISECONDS/tempo)/8
         << " " << MILLISECONDNAME <<   "\n";
    
    usleep(USLEEP);
    
    cout << "1/32T = " << setw(MS_SETW) << (MILLISECONDS/tempo)*(0.25/3)
         << " " << MILLISECONDNAME << "\n\n";
}

void DelayTime::calculateSixtyFourthNotes(const int &tempo)
{
    // 1/64 notes
    usleep(USLEEP);
    
    cout << "1/64. = " << setw(MS_SETW) << (MILLISECONDS / tempo) * (3.0 / 32)
         << " " << MILLISECONDNAME <<   "\n";
    
    usleep(USLEEP);
    
    cout << "1/64  = " << setw(MS_SETW) << (MILLISECONDS / tempo) / 16
         << " " << MILLISECONDNAME <<   "\n";
    
    usleep(USLEEP);
    
    cout << "1/64T = " << setw(MS_SETW) << (MILLISECONDS / tempo) * (0.125 / 3)
         << " " << MILLISECONDNAME << "\n\n";
    
    usleep(USLEEP);
    
    cout << "Seconds per measure: "     << (MILLISECONDS/tempo) /250
         << "\n";//takes 1/1 note and divides it by 1000 (4/1000=1/250)
}
