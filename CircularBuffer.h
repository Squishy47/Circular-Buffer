//  CircularBuffer.h
//  Created by Squishy on 27/12/2017.

#ifndef CircularBuffer_h
#define CircularBuffer_h

// USER HEADERS
#include "VecTemplate.h"

class CircularBuffer{
    Vec_Float buffer;
    float interpValues[2];
    int interpDiff;
    int bufferLength;
    int tail = 0;
    int head = 4;
    
public:
    void init(int inValue){
        bufferLength = inValue;
        buffer.resize(bufferLength);
        for(int i = 0; i < bufferLength; i++)
            buffer[i] = 0.0;
    }

    // num of elements to read behind current sample (n-j) input being j
    float read(float numElementsToRead){
        interpolation(numElementsToRead);
        
        for(int i = 0; i < 2; i++){
            tail = head - interpValues[i];    // tail = current index in buffer - number of elements to read.
            
            if (tail > bufferLength - 1)
                tail -= bufferLength;
            else if (tail < 0)
                tail += bufferLength;
            
            interpValues[i] = buffer[tail];
        }
        
        return interpValues[1] * interpDiff + (1.0 - interpDiff) * interpValues[0];
    }
    
    // writes the new samples in the next index of the array,
    // if the index is greater than array, it loops to the index 0.
    void write(float inValue, int numElementsToWrite){
        for(int i = 0; i < numElementsToWrite; i++){
            if(head > bufferLength - 1)
                head -= bufferLength;
            else if(head < 0) tail += bufferLength;
                buffer[head] = inValue;
            head++;
        }
    }
    
    void interpolation(float inValue){
        int temp = round(inValue);

        if(temp > inValue){
            interpValues[1] = temp;                 // High value
            interpValues[0] = interpValues[1] - 1;  // Low Value
        }
        else{
            interpValues[0] = temp;                 // Low Value
            interpValues[1] = interpValues[0] + 1;  // High value
        }

        interpDiff = inValue - interpValues[0];
    }
};

#endif /* CircularBuffer_h */
