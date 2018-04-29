How to use? Once you've included the files "CircularBuffer.h" in your project, create a new instance of the CircularBuffer class with the followed by the length of the buffer you want in samples.

`CircularBuffer myBuffer{44100};`


To write elements to the buffer you need to pass in the data you want to write, as a float. the buffer will auto index everytime you write too it.

`myBuffer.write(audioDataValue);`

Reading samples back.
The read functions take 1 varialbe, a float equivalent to the number of samples back in time you want to go.
e.g 
`float sample = myBuffer.readCubic(4)`
sample will be 4 samples behind the last written sample.

there are 3 read functions avaible. the last 2 come at a performance cost and will be removed at some point.
`readCubic(value);
readLinear(value);
read(value, cubic); // read(value, linear);`
