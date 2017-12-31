# Audio-Things
Contains a collection of audio processing techniques used as part of one of my Uni Projects, such as circular buffers, FIR filter and more to come. 

How to use?
Once you've included the files "CircularBuffer.h" and "VecTemplate.h" in your project. create a new instance of the CircularBuffer class with the following. 

CircularBuffer myNewBuffer;

Now you should initialise the buffer and pass in the size of buffer you want as a variable of type int.

myNewBuffer.init(900);

Now to write elements to the buffer you need to pass in the data you want to write, as a float, and the number of elements that you want to write, in that order.

myNewBuffer.write(10.5, 1);

To read from the buffer you need to call the read function along with a variable. This variable relates to the index of the data that you want to read from, relative to the write head. e.g. if i want to read an element that was written 4 samples ago, i would do the following.

float fourSamplesAgo = myNewBuffer.read(4);





