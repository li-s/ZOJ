#include <stdio.h> 
#include <string.h>

//THIS FUNCTION IS DONE, DO NOT TOUCH
//Finds all factorials in the number
int factorial(int factors[], int counter, long score, int nballoon)
{
    //Sets base factor as 1
    if(score == 1)
    {
        factors[counter] = 1;
        //Last number of each array shows the number of factors excluding 1
        factors[9] = counter;
        return 1;
    }
    
    //Iterates all possible numbers to find next smallest factorial
    for(int i = nballoon; i >= 2; --i)
    {
        if((score % i) == 0)
        {
            //Calls recurrent code to fill in factors
            while(factorial(factors, (counter + 1), (score / i), (i - 1)))
            {
                factors[counter] = i;
                return 1; 
            }

            return 0;
        }
    }

    return 0;
}
//DO NOT TOUCH

//This function is also done
//Finds all the combination of factors for the number, under 100
int find_all_factors(long number, int all_factors[][10], int checker, int counter)
{
    int new_factors[10] = {};
    int previous_factors[10] = {};
    
    //Cycle from the number / 100 (whichever lower) to 2
    for(int i = ((100 <= number) ? 100 : number); i >= 2; --i)
    {
        checker = factorial(new_factors, 0, number, i);
        if((checker == 1) && 
            //check if the new factors are unique
            (memcmp(new_factors, previous_factors, sizeof(new_factors)) != 0))
        {
            for(int j = 0; j < (sizeof(new_factors) / sizeof(new_factors[0])); ++j)
            {
                all_factors[counter][j] = new_factors[j];
            }
            counter++;
        }

        //Store the factors in another array and reset to 0
        for(int k = 0; k < (sizeof(new_factors) / sizeof(new_factors[0])); ++k)
        {
            previous_factors[k] = new_factors[k];
            new_factors[k] = 0;
        }
    }
    
    //First number of last array shows the number of different sets of factors
    all_factors[19][0] = counter;
    
    /*
    //Remove from actual, this is just for better display on printf
    for(int i = 0; i < 20 ; ++i)
    {
        printf("[");
        for(int j = 0; j < 10; ++j)
        {
            printf("%d", all_factors[i][j]);
            if(((j + 1) % 11) != 0)
            {
                printf(",");
            }
            
        }
        printf("]\n");
    }
    printf("\n");
    */

    return 0;
}
//DO NOT TOUCH


int compare(long major, long minor)
{
    int checker = 0;
    int counter = 0;
    int number_major[20][10] = {};
    int number_minor[20][10] = {};

    find_all_factors(major, number_major, checker, counter);
    find_all_factors(minor, number_minor, checker, counter);

    //check if anyone is lying
    if(number_minor[19][0] == 0)
    {
        if(number_major[19][0] == 0)
        {
            return 0;
        }
        return major;
    }

    if(number_major[19][0] == 0)
    {
        return minor;
    }

    for(int i = 0; i < number_major[19][0]; ++i)
    {
        for(int j = 0; j < number_minor[19][0]; ++j)
        {
            for(int k = 0; k < number_major[i][9]; ++k)
            {
                for(int l = 0; l < number_minor[j][9]; ++l)
                {
                    if(number_major[i][k] == number_minor[j][l])
                    {
                        goto next_factors;
                    }
                }
                //If reach here that means in number_major[i] there isnt any number that occured in number_minor[j]
                return major;
            }
            //If any number in number_major[i] matches any number in number_minor[j], check number_minor[j+1]
            next_factors: continue; 
        }
    }
    
    //If reach here that means for every number_major[i] there is a repeated number in numner_minor[j]
    return minor;
}

int main()
{
    long major = 0;
    long minor = 0;
    long answer = 0;

    scanf("%li %li", &major, &minor);
    if(major < minor)
    {
        long temp = 0;
        temp = minor;
        minor = major;
        major = temp;
    }

    answer = compare(major, minor);
    printf("%li\n", answer);

    return 0;
}
