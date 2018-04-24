#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//Map of the journey the travelling salesman must go on, it represents the distance from a given city to another
//i.e the value of map[i][j] is the distance from the i-th city to the j-th one.
int map [25][25] = {
     {0, 3, 5, 3, 7, 8, 13, 5, 13, 19, 2, 5, 20, 11, 15, 6, 7, 8, 2, 10, 25, 11, 14, 24, 19 },
     {2, 0, 8, 9, 15, 14, 15, 5, 21, 20, 1, 11, 3, 18, 16, 8, 2, 25, 19, 6, 4, 22, 25, 5, 25},
     {4, 10, 0, 3, 9, 23, 13, 7, 22, 8, 9, 24, 10, 4, 6, 17, 2, 16, 4, 23, 8, 24, 14, 17, 14},
     {9, 12, 7, 0, 2, 4, 23, 1, 17, 25, 22, 22, 8, 9, 5, 16, 22, 23, 10, 20, 7, 81, 12, 14, 8},
     {15, 12, 11, 4, 0, 15, 10, 4, 6, 20, 15, 17, 10, 2, 11, 16, 10, 11, 24, 14, 5 ,6, 7, 8, 9 },
     {15, 7, 19, 25, 20, 0, 7, 3, 1, 5, 22, 8, 3, 4, 24, 12, 5, 6, 20, 17, 1, 2, 3, 4, 5},
     {5, 17, 20, 14, 14, 19, 0, 16, 25, 9, 25, 9, 17, 20, 14, 14, 19, 12, 5, 3, 14, 16, 18, 20, 13},
     {7, 14, 8, 16, 13, 24, 15, 0, 1, 1, 20, 18, 25, 11, 17, 16, 24, 15, 3, 1, 6, 8, 11, 14, 20},
     {19, 9, 5, 18, 10, 18, 25, 15, 0, 23, 1, 25, 2, 15, 20, 14, 4, 9, 19, 6, 3, 3, 3, 14, 3},
     {21, 10, 12, 6, 1, 16, 9, 3, 15, 0, 16, 1, 20, 12, 4, 6, 6, 13, 6, 14, 18, 16, 14, 12, 7},
     {13, 9, 10, 18, 14, 21, 14, 11, 24, 4, 0, 18, 18, 23, 20, 22, 11, 7, 11, 12, 7, 3, 16, 17, 2},
     {9, 14, 15, 21, 15, 11, 7, 13, 22, 21, 15, 0, 1, 7, 9, 2, 14, 15, 21, 21, 22, 23, 24, 25, 26},
     {10, 20, 16, 11, 19, 17, 4, 12, 22, 2, 21, 1, 0, 22, 4, 24, 4, 21, 3, 15, 26, 25, 24, 23, 22},
     {8, 14, 20, 1, 13, 17, 17, 2, 14, 15, 6, 19, 21, 0, 23, 8, 25, 6, 16, 13, 10, 8, 7, 6, 2},
     {11, 24, 3, 19, 9, 13, 13, 22, 1, 6, 11, 15, 7, 2, 0, 22, 2, 16, 25, 25, 9, 9, 3, 3, 18},
     {18, 2, 14, 13, 21, 24, 4, 25, 3, 9, 24, 21, 12, 11, 11, 0, 16, 8, 5, 17, 16, 20, 23, 22, 1},
     {23, 4, 9, 6, 13, 24, 5, 3, 14, 1, 7, 15, 17, 4, 23, 17, 0, 23, 9, 3, 4, 5, 6, 7, 8},
     {20, 18, 2, 2, 2, 13, 23, 13, 11, 18, 16, 7, 21, 16, 2, 4, 2, 0, 18, 4, 8, 12, 16, 20, 24},
     {17, 24, 8, 2, 6, 4, 1, 1, 21, 3, 19 ,18, 23, 22, 11, 5, 18, 25, 0, 2, 6, 8, 3, 15, 12},
     {20, 20, 5, 15, 20, 8, 19, 11, 5, 21, 20, 5, 22, 9, 19, 19, 15, 18, 5, 0, 8, 15, 32, 11, 9},
     {18, 17, 17, 18, 16, 5, 22, 10, 24, 8, 10, 2, 4, 25, 21, 5, 8, 11, 1, 2, 0, 22, 8, 19, 12},
     {13, 10, 11, 23, 2, 18, 22, 2, 17, 23, 2, 14 ,18, 16, 10, 9, 6, 20, 25, 6, 17, 0, 5, 15, 12},
     {8, 17, 20, 19, 17, 21, 12, 21, 4, 18, 8, 1, 12, 2, 10, 15, 8, 24, 22, 9, 20, 12, 0, 22, 11},
     {4, 4, 25, 8, 21, 9, 7, 10, 1, 15, 11, 5, 3, 25, 2, 9, 22, 8, 7, 17, 22, 6, 6, 0, 17},
     {1, 2, 12, 4, 10, 18, 8, 12, 8, 22, 3, 9, 1, 4, 20, 12, 16, 15, 17, 9, 4, 17, 12, 11, 0}

};

//Generates random double in the given range
double generaDoubles( double min, double max ) {    

    double scale = rand(

    ) / (double) RAND_MAX;

    return min + scale * ( max - min );
}

//helper function to avoid creating invalid tours, since a tour must not have duplicate cities being visited
bool notInCitiesPlaced(int cities, int citiesPlaced[cities], int num){
    bool flag = true;
    int i;
    for (i = 0; i < cities; i++ ){
        if(citiesPlaced[i] == num )
            flag = false;
    }
    return flag;
}

//Randomly causes a given tour to "mutate" by swapping values
void mutation(int population, int cities, int newPop[population][cities], int index, double mutationChance){
    double chance = generaDoubles(0.0, 1.0);
    if (chance <= mutationChance){
        int firstIndex = RAND_MAX % cities;
        int secondIndex = RAND_MAX % cities;
        int firstPop = newPop[index][firstIndex];
        int secondPop = newPop[index][secondIndex];
        newPop[index][firstIndex] = secondPop;
        newPop[index][secondIndex] = firstPop;
    }
}

//Crossover is the "reproduction" method, the parents will pass on their genes to the next generation
//This should be achieved by randomly selecting a subset of the tour in the father and passing that to the offspring
//Afterwards the remaining cities should be choosen by adding them in order of how they appear on the mothers side
//Obviously while skipping the ones on the mothers side that have already been added by the father to avoid duplicate cities being visited
void crossover(int population, int cities, int popArray[population][cities], int newPop[population][cities], int index, int padre, int madre){
    int i;
    int currentOffspring [cities];

    for (i = 0; i < cities; i++){
        currentOffspring[i] = -1;
    }

    int startPoint = RAND_MAX % cities;
    int endPoint = RAND_MAX % cities;

    if (startPoint > endPoint){
        int temp = startPoint;
        startPoint = endPoint;
        endPoint = temp;
    }

    
    int indexArr = 0;
    for (i = startPoint; i <= endPoint; i++  ){
        newPop[index][i] = popArray[padre][i];
        currentOffspring[indexArr] = popArray[padre][i];
        indexArr++;
    }
    indexArr = 0;
    for (i = 0; i < cities; i++){
        if (i < startPoint || i > endPoint){
            if (notInCitiesPlaced(cities, currentOffspring, popArray[madre][indexArr])){
                newPop[index][i] = popArray[madre][indexArr];
                indexArr++; 
            } else{
                i--;
                indexArr++;
            }
        }
    }

}

//Finds the best route in a given generation
int findBestRoute(int population, int cities, int popArray[population][cities], int evalArray[population]){
    int bestFitness = 999999;
    int routeNumber;
    int i;
    for (i = 0; i < population; i++){
        if (evalArray[i] < bestFitness){
            bestFitness = evalArray[i];
            routeNumber = i;
        }
    }
    return routeNumber;
}
//Creates the probability to choose a given tour
void getProbability(int population, int cities, int popArray[population][cities], int evalArray[population], double popProba[population]){
    int fitness;
    int i, j;
    int a;
    int distance = 0; //distance of a given tour
    int cumulativeDistance = 0; //distance of every tour in a generation
    float sum = 0;
    for (i = 0; i < population; i++){
        //printf("%d ", evalArray[i]);
        cumulativeDistance += evalArray[i];
    }

    //printf("\nCumDist: %d", cumulativeDistance);
    //printf("\n");

    /*The probability must be in a range of 0.0 - 1, so it must be normalized
    This normalization means to find the total sum of each tour and then divide the given distance of a particular tour by the total distance
    However this approach gives a higher probability to higher values, and since our goal is to minimize distance, the resulting probability
    from this previous step is subtracted from 1 and is divided by the amount of population -1 to ensure that the new probabilities end up
    in a range from 0.0 to 1.0 
    */
    for (i = 0; i < population; i++){
        popProba[i] =  (1 - ((evalArray[i]) /(float) cumulativeDistance)) / (population - 1) ;
        sum+= popProba[i];
        if (i > 0){
            popProba[i] += popProba[i-1];
        }
        //printf("%lf ", popProba[i]);
    }

    //printf("\nprob total: %lf", popProba[9]);
}

//evaluates the function to get its fitness, the objective is to minimize distance
void getFitness(int population, int cities, int index,int popArray[population][cities], int evalArray[population]){
    int fitness;
    int i, j;
    int distance = 0;
    int cumulativeDistance = 0;
    float sum = 0;

        for (i = 1; i < cities; i++ ){
            int startPoint = popArray[index][i-1];
            int endPoint= popArray[index][i];
            distance += map[startPoint][endPoint];

        }
        evalArray[index] = distance;
}


//create initial population
//A valid tour consists of an array of unique numbers from 0 to n, where n is the amount of cities placed
//The order of the array represents the order in which the n-th city was visited
void generateRoads(int population, int cities, int popArray[population][cities], int i ) {    
    int citiesPlaced [cities];
    int count = 0;

    for (count = 0; count < cities; count++){
        citiesPlaced[count] = -1;
    }

    for (count = 0; count < cities; count++){
        int num = rand() % cities;

        if (notInCitiesPlaced(cities, citiesPlaced, num)){
            popArray[i][count] = num;
            citiesPlaced[count] = num;
        } else{
            count--;
        }
    }
    
}

/* The main initialized the information needed to solve the problem. 
This process then repeats itself depending on how many generations were set and the best route it outputted*/
int main( ) {
   clock_t begin=clock();
   srand(time(NULL));
   int cities = 25; //amount of cities in the tour
   int population = 500; //Size of population, i.e how many tours are set in a given generation
   int generations = 250; //La cantidad de generaciones i.e how many times the program should loop
   double mutationChance = 0.03; //1.0 will be 100%

   int popArray [population][cities]; //Where population values are stored
   int newPop [population][cities]; //Where the new population will be stored
   int evalArray [population]; //Where the evaluation results are stored of every population
   double popProba[population];// Where the probability of each tour is stored to be selected to reproduce
   int resultadosGeneracion [generations]; //Where the best results of each generation are stored
   int bestRouteArray [cities]; //Where the final best route is stored

   int bestRoute = 999999; //initial given value to the best route, the point is to minimize this
   int i;
   int j;
   int k;

   for (i = 0; i < population; i++){
       //The initial population is randomly generated
        generateRoads(population, cities, popArray, i);
    }

    for (i = 0; i < generations; i++){

        /*printf("generation is\n\n");
        for(j = 0; j < population; j++){
            for (k = 0; k < cities; k++){
                printf("%d ", popArray[j][k]);
            }
            printf("\n");
        }
        printf("\n\nNormalized:\n ");*/

        for (j = 0; j < population; j++){
            //makes changes to evalArray
            getFitness(population, cities, j, popArray, evalArray);
        }
        //makes changes to popProba
        getProbability(population, cities, popArray, evalArray, popProba);

        
//Chooses which population should reproduce
//Does so by selecting a random interval between 0.0 and 1.0 and choosing the population index that is just below it.

        for (j = 0; j < population; j++){
            double ruleta1 = generaDoubles(0.0, 1.0);
            double ruleta2 = generaDoubles(0.0, 1.0);
            int padre, madre;

            for (k = 0; k < population; k++){
                if (ruleta1 <= popProba[k]){
                    padre = k;
                    break;
                }
            }

            for (k = 0; k < population; k++){
                if (ruleta2 <= popProba[k]){
                    madre = k;
                    break;
                }
            }

            //printf("\nruleta1: %lf\n ruleta2: %lf\n padre: %d\n Madre: %d\n",ruleta1, ruleta2, padre, madre);
            crossover(population, cities, popArray, newPop, j, padre, madre); //reproduction
            mutation(population, cities, newPop, j, mutationChance); //mutation
        }

        resultadosGeneracion[i] = findBestRoute(population, cities, popArray, evalArray);
        printf("Best route for generation %d\n", i);
        printf("With a score of: %d\n", evalArray[resultadosGeneracion[i]]);

        //Potentially updates the best route of all generations
        if (bestRoute > evalArray[resultadosGeneracion[i]]){
            bestRoute = evalArray[resultadosGeneracion[i]];
            for (j = 0; j < cities; j++){
                bestRouteArray[j] = popArray[resultadosGeneracion[i]][j];
            }
        }
        for (j = 0; j < cities; j++){
            printf("%d ", popArray[resultadosGeneracion[i]][j]);
            
        }
        printf("\n");

        //updates the generation to be the one that was most recently generated
         for(j = 0; j < population; j++){
            for (k = 0; k < cities; k++){
                popArray[j][k] = newPop[j][k];
            }
        }

    }   
    //Final results are given
        printf("Best route all generations\n");
        printf("With a score of: %d\n", bestRoute);
        for (i = 0; i < cities; i++){
            printf("%d ", bestRouteArray[i]);
        }
        printf("\n");
        
    clock_t end=clock();
    printf("Time taken:%lf",(double)(end-begin)/CLOCKS_PER_SEC);
}


