#include<stdio.h>
#include<stdint.h>

void update_state_array(uint32_t message, uint8_t state_array[16])
{
    uint8_t add1, add2, data1, data2, d1u, d1l, d2u, d2l, ind1, ind2, uv, lv, ux, lx;
    //LSB here is leftmost, which will be the recorded value as it gets truncated to 8-bits, hence I am not masking
    //assigning values by decoding the message
    add1 = (message >> 24);
    add2 = (message >> 16);
    data1 = (message >> 8);
    data2 = message;
    ind1 = add1 & 0x01;
    ind2 = add2 & 0x01;

    //assigning the true address (removing the last bit)
    add1 = (add1 >> 1);
    add2 = (add2 >> 1);

    //assigning the upper and lower nibbles for the box we wish to change for address 1 and address 2
    uv = (state_array[add1] >> 4) & 0x0F;
    lv = state_array[add1] & 0x0F;
    ux = (state_array[add2] >> 4) & 0x0F;
    lx = state_array[add2] & 0x0F;

    //I am assigning the bit-wise value of data1 and data2 in a two seperate variables to make it easier to compare the upper and lower values
    d1u = (data1 >> 4);
    d2u = (data2 >> 4);
    d1l = data1 & (0x0F);
    d2l = data2 & (0x0F);

    //calling the edit function: implemented below
    state_array[add1] = edit (ind1, d1u, d2l, uv, lv);
    state_array[add2] = edit (ind2, d2u, d2l, ux, lx);


}

//function to check
uint8_t edit (uint8_t ind, uint8_t du, uint8_t dl, uint8_t u, uint8_t l)
{
    if (ind != 0)
    {
        //run loop for checking if data match
        for (int i = 0; i < 4; i++)
        {
            if (((du >> (4-i-1)) & 0x01) == ((dl >> (4-i-1)) & 0x01))
            {
                uint8_t a = (du >> (4-i-1)) & 0x01;
                //edge case: both are 1, do nothing
                if ((u >> (4-i-1))==1 && a == 1);
                else{
                a =  (a << (4 - i - 1));
                u = (u + a) & 0x0F; 
                }
            }
        }

    }

    else 
    {
        //run loop for checking if data match
        for (int i = 0; i < 4; i++)
        {
            if (((du >> (4-i-1)) & 0x01) == ((dl >> (4-i-1)) & 0x01))
            {
                uint8_t a = (du >> (4-i-1)) & 0x01;
                //edge case: both are 1, do nothing
                if ((l >> (4-i-1)) == 1 && a == 1);
                else 
                {
                a = (a << (4 - i - 1));
                l = (l + a) & 0x0F; 
                }
            }
        }
    }
    //returns the updated value after the final calculations are done
    return (u << 4) + l;
}
