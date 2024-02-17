#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;

const int NUM_COWS = 10;
 const int NUM_DAYS = 7; 
const int NUM_MILKINGS_PER_DAY = 2; // Twice a day

// Struct to represent a cow
struct Cow
{
    double yields[NUM_DAYS][NUM_MILKINGS_PER_DAY];
};

// Recording yeild
void recordYield(Cow cows[]) 
{
    int lowerBound = 1;
    int upperBound = 60;
    cout << "Record the milk yields for each cow:" << endl;
    for (int i = 0; i < NUM_COWS; i++) 
    {
        cout << "Cow " << (i + 1) << ":" << endl;
        for (int day = 0; day < NUM_DAYS; ++day) 
        {
            for (int milking = 0; milking < NUM_MILKINGS_PER_DAY; ++milking) 
            {
                cout << "The yield for day " << (day + 1) << ", milking " << (milking + 1) << ": ";
              
                 cows[i].yields[day][milking] = rand() % (upperBound - lowerBound + 1) + lowerBound;
                 cout << cows[i].yields[day][milking] << endl;
            }
        }
    }
}

//Calculating total volume
double calculateTotalVolume( Cow cows[])
{
    double totalVolume = 0;
    for (int i = 0; i < NUM_COWS; i++)
    {
        for (int day = 0; day < NUM_DAYS; day++) 
        {
            for (int milking = 0; milking < NUM_MILKINGS_PER_DAY; milking++)
            {
                totalVolume += cows[i].yields[day][milking];
            }
        }
    }
    return totalVolume;
}

// Calculating Average  week
double calculateAverageYield( Cow cows[], double totalVolume) 
{
    return totalVolume / (NUM_COWS * NUM_DAYS * NUM_MILKINGS_PER_DAY);
}

// Identifying specific cow
void identifyCows( Cow cows[]) 
{
    double maxTotalYield = 0;
    int mostProductiveCowIndex = -1;
    int lowYieldCows[NUM_COWS] = { 0 }; // Array to count low yield days for each cow

    for (int i = 0; i < NUM_COWS; ++i) 
    {
        double totalYield = 0;
        for (int day = 0; day < NUM_DAYS; day++) 
        {
            for (int milking = 0; milking < NUM_MILKINGS_PER_DAY; milking++) 
            {
                totalYield += cows[i].yields[day][milking];
                if (cows[i].yields[day][milking] < 12) 
                {
                    lowYieldCows[i]++;
                }
            }
        }
        if (totalYield > maxTotalYield) 
        {
            maxTotalYield = totalYield;
            mostProductiveCowIndex = i;
        }
    }

    cout << "\nThe most productive cow this week is Cow " << (mostProductiveCowIndex + 1) << " with a total yield of "
        << round(maxTotalYield) << " litres." << endl;

    cout << "\nCows with a yield of less than 12 litres for four or more days this week:" << endl;
    for (int i = 0; i < NUM_COWS; i++) 
    {
        if (lowYieldCows[i] >= 4) 
        {
            cout << "Cow " << (i + 1) << endl;
        }
    }
}


int main()
{
    Cow cows[NUM_COWS];
    recordYield(cows);

    double totalVolume = calculateTotalVolume(cows);
    double averageYield = calculateAverageYield(cows, totalVolume);

    cout << "\n\nTotal weekly volume of milk: " << round(totalVolume) << " litres" << endl;
    cout << "\nAverage yield per cow: " << round(averageYield) << " litres" << endl;

    identifyCows(cows);

    return 0;
}
