/* Program will
/* 1. Place the first blockhouse on the bottom right of the map.
/* 2. Go along in a zig-zag manner from bottom right to bottom left, 
/*    middle right to middle left... placing blockhouses in the first
/*    legal box, then count the number of blockhouses(counter).
/* 3. Repeat step 1 but now place the blockhouse one box to the left of 
/*    the bottom right box.
/* 4. Repeat step 2, storing the higher counter into variable maxblockhouse 
/* 5. Repeat steps 3, followed by 2 untill the first blockhouse has been
/*    placed in each box of the bottom row.
/* 5. Output maxblockhouses.


/*
NEW IDEA:
    fills the first box with "y"(the boxes on the bottom half of the map will take turns being the "first")
    fills the boxes along the row and collumn that the "y" box is with "z", as long as not blocked 
    a wall.
    fills the next available box with "y"
    repeat
    check if any "." left over, and fill it with "y"
    count number of "y"
*/

/*
    Recurrent function that counts the number of "." left after "y and "z"
    are placed, then using a for loop place the next "y" in the last "."
    Repeat for every "."
*/


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//Traces the line of sight of each turret
int trace(int constant, int sizemap, int i, char array[])
{
    //fills the boxes on the row, that are not blocked by a wall with "z".
    while(((constant - 1) / sizemap) == (constant / sizemap)) //checks if the box before the current one is on the same row
    {
        if(constant == 0)
            break;
        if(array[constant - 1] == 'X')
            break;
        else
            array[constant - 1] = 'z';
        constant--;
    }

    constant = i;
    //fills the boxes above that are not blockes by a wall with "z".
    while(constant - sizemap)  //check the box above the current box, within the same collum
    {
        if(constant < 0)
            break;
        if(array[constant - sizemap] == 'X')
            break;
        else
            array[constant - sizemap] = 'z';
        constant = constant - sizemap;
    }

    return 0;
}

/*
forcecheck(int* sizemap, int* i, int* counter, char* array[])
{
    if(*i == 0,)
    {
        if(array[*i] == '.')
        {
            array[*i] = 'y';
            *counter++;
        }
    }

    for(int iterate = *i, iterate >= 0, --iterate)
    {
        //counts number of "."
        int dotcount = 0;
        for(j = iterate; j >= 0; --j)
        {
            if(*array[
        }
        for(int spacesleft = 

        //Place a "y" at the first ".", continuing down

}
*/
int main()
{
    char array[16] = {0};
    int maxblockhouses = 0;
    int counter = 0;
    int sizemap = 0;

    scanf("%d%*c", &sizemap);
    while(sizemap != 0)
    {
        //makes the map
        for(int i = 0; i < (sizemap * sizemap); ++i)
        {
            scanf("%c%*c", &array[i]);
        }

        //reset the values
        maxblockhouses = 0;

        for(int i = sizemap * sizemap - 1; i >= 0; --i)
        {
            char temparray[16] = {0};
            strncpy(temparray, array, 16);
            counter = 0;

            //fills next available box
            for(int iterate = i; iterate >= 0; --iterate)
            {
                int constant = iterate;
                if(temparray[constant] == '.')
                {
                    temparray[constant] = 'y';
                    counter++;
                    trace(constant, sizemap, iterate, temparray);
                }

                if(counter > maxblockhouses)
                    maxblockhouses = counter;
            }
        }

        printf("%d\n", maxblockhouses);
    }

    return 0;
}
