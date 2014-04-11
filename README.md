Base64 coder and decoder on C++

Write a program encoder and decoder program - base64. Note: base64 encoding is an encoding method in which every 3 bytes of the original sequence is associated with a set of 4 characters A.. Z, a .. z, 0 .. 9, + / encoded by 6 bits each . In the case where the number of bytes of the source file is not a multiple of 3 , the necessary amount is added zero bytes . In this case , if the original file was only one byte in the resulting file it will fit 2 characters if the two bytes that, accordingly , the three characters . Also in this case, the output end of the file is added as the characters ' =' as null bytes are added for encoding. Input and output files are passed as arguments to the command line.

Created by Visual Studio 2010
