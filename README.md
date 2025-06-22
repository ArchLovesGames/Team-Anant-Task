# Team-Anant-Task
This is one of my favorite projects as this was the first ever program I wrote which solved a unique problem that hadn't been solved before

Task for Team Anant

The task we had been given was to solve a complicated decoding algorithm that constantly changes the space system's state via a 32-bit message with each bit serving as an indicator for the data change. 

The ship's state is maintained in an array of 16 8-bit integers (128 bits total). Each bit represents a critical state property of the microverse battery (like power flow, dimensional stability, universe expansion rate, etc.). The ship's microcontroller needs to update these states constantly but can only communicate using 32-bit messages due to quantum interference from the supernova. 
The microcontroller uses a sophisticated addressing mechanism to update the state array: 
1. Message Format (32 bits total): 
Bits 31-24: Address1 (8 bits) 
Bits 23-16: Address2 (8 bits) Bits 15-8: Data1 (8 bits) 
Bits 7-0: Data2 (8 bits) 
2. Address Interpretation: 
First 7 bits of each address (Address1 and Address2) indicate the index in the state array (0-15) 
Last bit of each address determines which half of the 8-bit integer to modify: 
1: Modify first 4 bits (bits 7-4) 
0: Modify last 4 bits (bits 3-0) 
3. Data Interpretation: 
Each 8-bit data field (Data1 and Data2) is split into two 4-bit parts: 
First 4 bits (bits 7-4): Contains os for unchanged bits and new values for changed bits Last 4 bits (bits 3-0): Contains is for unchanged bits and new values for changed bits 
4. Bit Update Logic: 
Task: 
A bit should be updated only if it has the same value in both parts of the data field The matching value becomes the new value for that bit position 

