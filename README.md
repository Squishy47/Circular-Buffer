How to use? Once you've included the files "CircularBuffer.h" and "VecTemplate.h" in your project. Create a new instance of the CircularBuffer class with the following.

`CircularBuffer myNewBuffer;`

Now initialize the buffer and pass in the size of buffer you want as a variable of type int.

`myNewBuffer.init(900);`

To write elements to the buffer you need to pass in the data you want to write, as a float.

`myNewBuffer.write(10.5);`

To read from the buffer you need to call the read function along with a variable. This variable relates to the index of the data that you want to read from, relative to the write head. e.g. If you want to read an element that was written 4 samples ago, you would do the following. The second argument allows you to set the interpolation type between "Linear" and "Cubic".

`float fourSamplesAgo = myNewBuffer.read(4, "Cubic");`

To read the last written sample pass 0.0 as an argument to the read function.
