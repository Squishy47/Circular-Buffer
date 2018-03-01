How to use? Once you've included the files "CircularBuffer.h" in your project, create a new instance of the CircularBuffer class with the followed by the length of the buffer you want in samples.

`CircularBuffer myBuffer{44100};`


To write elements to the buffer you need to pass in the data you want to write, as a float.

`myBuffer.write(audioDataValue);`


To read from the buffer use `read(index, interpType)`. Index is the number of samples back you want to read; 0 being the last written sample and bufferLength - 1 being the furthest back in the buffer you can go. 

`float fourSamplesAgo = myBuffer.read(3, linear);`
`float lastWrittenSample = myBuffer.read(0, cubic);`


To resize the buffer after initialisation:

`myBuffer.setBufferLength(4);`


To get the buffer length:
`int bufferLength = myBuffer.getBufferLength(); // bufferLength = 4;` 


Note. The buffer is sensitive to when you read and write samples. The read head indexes by one every time you call the write function. e.g.

```
CircularBuffer myBuffer{4};
float audioData[4] = {4, 3, 2, 1};

myBuffer.write(audioData[0]);
myBuffer.write(audioData[1]);
myBuffer.write(audioData[2]);
float output = myBuffer.read(3, linear); // output = 0 because the 4th element in the buffer hasn't been written to yet

myBuffer.write(audioData[3]);
float output = myBuffer.read(3, linear); // output = 4 the last element in the buffer has been filled
```
