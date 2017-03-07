//
//  DelayTime.hpp
//  The Lyons' Den Delay Time Calculator
//
//  Created by Joseph Lyons on 3/7/17.
//  Copyright © 2017 Joseph Lyons. All rights reserved.
//

#ifndef DelayTime_hpp
#define DelayTime_hpp

class DelayTime
{
private:
    int MILLISECONDS;
    double USLEEP;
    int MS_SETW;
    char MILLISECONDNAME[5];
    
public:
    DelayTime();
    
    void fillMillisecondArrayName();
    void setPrecisionAndRounding(const int &tempo);
    
    void calculateWholeNotes(const int &tempo);
    void calculateHalfNotes(const int &tempo);
    void calculateQuarterNotes(const int &tempo);
    void calculateEighthNotes(const int &tempo);
    void calculateSixteenthNotes(const int &tempo);
    void calculateThirtySecondNotes(const int &tempo);
    void calculateSixtyFourthNotes(const int &tempo);
};

#endif /* DelayTime_hpp */
