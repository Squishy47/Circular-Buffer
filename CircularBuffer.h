//
//  CircularBuffer.h
//  squishysPlugin1 - Shared Code
//
//  Created by Squishy on 27/12/2017.
//

#ifndef CircularBuffer_h
#define CircularBuffer_h

// USER HEADERS
#include "VecTemplate.h"

class CircularBuffer{
    Vec_Float buffer;
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
    float read(int numElementsToRead){
        tail = head - numElementsToRead;    // tail = current index in buffer - number of elements to read.
        if (tail > bufferLength - 1)        // if tail == bufferLength minus buffer length = 0;
            tail -= bufferLength;
        else if (tail < 0)
            tail += bufferLength;
        return buffer[tail];
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
};

#endif /* CircularBuffer_h */
