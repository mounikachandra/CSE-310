/* Recitation-1 mile stone
* 
* Author : Mounika Gandavarapu
* Version: 09-08-2018
*
*/
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <bits/stdc++.h>
#include <cmath>
#include "stdio.h"
#include "defns.h"

using namespace std;

/*
*
* This function takes in the string and delimiter and return 
* structure for mlb_stat
* input : line : string
* input : delimiter : char
* output : mlb_stat : struct<mlb_stat>
*
*/
mlb_stats splitString(string line, char delimiter) {
    mlb_stats  mlb_stat;
	string splitString;
    istringstream stringStream(line);
    int count;
    while(getline(stringStream,splitString,delimiter)) {
        count = count +1;
        switch(count) {
            case 1: 
            strcpy(mlb_stat.Team,splitString.c_str());
            break;
            case 2: 
            strcpy(mlb_stat.League,splitString.c_str());
            break;
            case 3: 
            {
            	stringstream gg(splitString);
				gg>>mlb_stat.G;
				break;
			}
            case 4: 
            {
            	stringstream ab(splitString);
				ab>> mlb_stat.AB;
				break;	
			}
            case 5:  
			{
            	stringstream r(splitString);
				r>> mlb_stat.R;
				break;
			}
            case 6:
            {
            	stringstream h(splitString);
				h>> mlb_stat.H; 
				break;
			}
            case 7: 
            {
            	stringstream b2(splitString);
				b2>> mlb_stat.B2; 
				break;
			}
            case 8: 
            {
            	 stringstream b3(splitString);
				 b3>> mlb_stat.B3;
            break;
			}
           
            case 9: 
            {
            	stringstream hr(splitString);
				hr>> mlb_stat.HR;
				break;
			} 
            case 10:
            {
            	stringstream rbi(splitString);
				rbi>> mlb_stat.RBI; 
				break;
			}
            case 11:
            {
            	stringstream bb(splitString);
				bb>> mlb_stat.BB; 
				break;
			}
            case 12: 
            {
            	stringstream so(splitString);
				so>> mlb_stat.SO;
				break;
			}
            case 13: 
            {
            	stringstream sb(splitString);
				sb>> mlb_stat.SB;
				break;
			}
            case 14:
            {
            	stringstream cs(splitString);
				cs>> mlb_stat.CS; 
				break;
			}
            case 15:
            {
            	stringstream avg(splitString);
				avg>> mlb_stat.AVG; 
				break;
			}
            case 16:
            {
            	stringstream obp(splitString);
				obp>> mlb_stat.OBP; 
				break;
			}
            case 17:
            {
            	stringstream slg(splitString);
				slg>> mlb_stat.SLG;
				break;
			}
            case 18:
            {
            	stringstream ops(splitString);
				ops>> mlb_stat.OPS; 
				break;
			}
            default:
            return mlb_stat;
        }
    }
    return mlb_stat;
}

/*
*
* This function takes in the year, no of teams and the constructs
* structure for our annual statistics
* input : year : no of years of annual_stats 
* input : no_teams : teams
* output : mlb_stats pointer
*
*/
mlb_stats* constructAnnualStats(int year, int noOfTeams) {
    string line;
	mlb_stats  *mlbStat = new mlb_stats[noOfTeams];
	int index = 0;
    while(noOfTeams >0) {
        getline(cin,line);
        mlbStat[index] = splitString(line,'\t');
		index= index+1;
        noOfTeams = noOfTeams-1;
    }
	return mlbStat;
}

/*
* This function returns the struct value when a given a field
* input : mlbstats : mlb_stats
* input : field : field for which you need to get the value
* output : float
*/
float getStructValue(mlb_stats mlbstats,char * field) {

    if(strcmp(field,"G")==0){return (float) mlbstats.G ;}
    if(strcmp(field,"AB")==0){return (float) mlbstats.AB ;}
    if(strcmp(field,"R")==0){return (float) mlbstats.R ;}
    if(strcmp(field,"H")==0){return (float) mlbstats.H ;}
    if(strcmp(field,"B2")==0){return (float) mlbstats.B2 ;}
    if(strcmp(field,"B3")==0){return (float) mlbstats.B3 ;}
    if(strcmp(field,"HR")==0){return (float) mlbstats.HR;}
    if(strcmp(field,"RBI")==0){return (float) mlbstats.RBI ;}
    if(strcmp(field,"BB")==0){return (float) mlbstats.BB ;}
    if(strcmp(field,"SO")==0){return (float) mlbstats.SO ;}
    if(strcmp(field,"SB")==0){return (float) mlbstats.SB ;}
    if(strcmp(field,"CS")==0){return (float) mlbstats.CS ;}
    if(strcmp(field,"AVG")==0){return (float) mlbstats.AVG ;}
    if(strcmp(field,"OBP")==0){return (float) mlbstats.OBP;}
    if(strcmp(field,"SLG")==0){return (float) mlbstats.SLG ;}
    if(strcmp(field,"OPS")==0){return (float) mlbstats.OPS ;}
}

/*
* This function is called inside isort function which prints
* TeamName, field and value after sorting 
*
*/
void printmlbs(mlb_stats *mlbs, int teamSize,char *field) {
    for(int d= 0; d<teamSize;d++) {	
    	if(strcmp(field,"League") ==0) {
    		cout << "TeamName \t"<< mlbs[d].Team <<  "\t" <<  mlbs[d].League <<  "\t" << field << endl; 
		} else if (strcmp(field,"Team") ==0) {
				cout << "TeamName \t"<< mlbs[d].Team <<  "\t" << field << endl; 
		}else {
			 cout << "TeamName \t"<< mlbs[d].Team << "\t" << field << "\t" << getStructValue(mlbs[d],field) << 

endl; 
		}
    }
}

/*
* print function used in Ifind function to print the min,max record from the input set
* input: mlb : mlb_stats 
* input: field : the field on which the ifind function was called
*/
void printIFind(mlb_stats mlb,char *field) {
    cout << "TeamName \t"<< mlb.Team << "field \t"<< field << "\t" << getStructValue(mlb,field) << endl; 
}

/*
* This function is called inside ifind where it prints
* TeamName, startYear,endyear, field and value after sorting 
*
*/
void printIsortRange(mlb_stats *mlbs,int startYear,int endYear,int teamSize,char *field) {
    for(int d= 0; d<teamSize;d++) {	
    	if(strcmp(field,"League") ==0) {
    		cout << "TeamName \t"<< mlbs[d].Team <<  "\t" <<  mlbs[d].League << "\t"<< startYear << "\t" << endYear 

<<"\t" << field << endl; 
		} else if (strcmp(field,"Team") ==0) {
				cout << "TeamName \t"<< mlbs[d].Team <<  "\t" << startYear << "\t" << endYear << "\t"<< 

field << endl; 
		}else {
			 cout << "TeamName \t"<< mlbs[d].Team <<"\t" << startYear << "\t" << endYear << "\t" << field << 

"\t" << getStructValue(mlbs[d],field) << endl; 
		}     
    }
}

/*
* This function checks if we need to call isort or ifind 
* input : order : different compartionn(> or <) depends on the order( incr,decr)
* input : mlbs1 : mlb_stats first term
* input : mlbs2 : mlb_stats second term 
* order: field: values of the mlb_stats that need the be compared 
* return bool
*  
*/
bool compareMLBS(char *order,mlb_stats mlbs1,mlb_stats mlbs2,char* field) {
    bool pattern;
    if(strcmp(order,"decr")==0) {
        pattern = true;
    } else if(strcmp(order,"incr")==0) {
        pattern = false;
    }
    if(strcmp(field,"Team") == 0) {
        string mlbs1Team = mlbs1.Team;
        string mlbs2Team = mlbs2.Team;
        if((pattern && mlbs1Team.compare(mlbs2Team) <0) || (!pattern && mlbs1Team.compare(mlbs2Team) >0 )) {
            return true;
        } else {
            return false;
        }
    } else if(strcmp(field,"League") == 0) {
        string mlbs1League = mlbs1.League;
        string mlbs2League = mlbs2.League;
        if((pattern && mlbs1League.compare(mlbs2League) <0 ) || (!pattern && mlbs1League.compare(mlbs2League) >0)) {
            return true;
        } else {
            return false;
        }
    } else {
        float firstMlb = getStructValue(mlbs1,field);
        float secondMlb = getStructValue(mlbs2,field);
        if((firstMlb < secondMlb && pattern) || (firstMlb > secondMlb && !pattern) ){
            return true;
        } else {
            return false;
        }

    }
}

/*
* This function does the insertion sort on the given mlbs 
* input : *mlbs : pointer to the mlb_stats structure
* input : teamSize: size of mlb_stats ( no of teams in mlb_stats for a given year)
* input : field: field on which sorting and finding needs to be done
* order: order: incr and decr order for isort 
* return void
*/
void isortOnMLB(mlb_stats *mlbs,int teamSize,char *field,char *order) {
    int c;
    mlb_stats temp;
    for(int b = 1; b<teamSize; b++){
        c = b-1;
        temp = mlbs[b];
            while(c>=0 && compareMLBS(order,mlbs[c],temp,field)) {
        	mlbs[c+1] = mlbs[c];
        	c= c-1;
		}
		mlbs[c+1] = temp;
    }
}

/*
* This function does the merge on the given mlbs 
* input : *mlbs : pointer to the mlb_stats structure
* input : left : leftIndex  to the mlb_stats structure
* input : right: rightIndex  to the mlb_stats structure
* input : mid : mid to the mlb_stats structure
* order: order: incr and decr order for isort 
* return void
*/
void merge(mlb_stats *mlbs,int left,int right,int mid,char *field,char *order) {
	int leftIndex = mid-left+1;
	int rightIndex =  right-mid;
	mlb_stats *leftMLB = new mlb_stats[leftIndex];
	mlb_stats *rightMLB = new mlb_stats[rightIndex];
	for(int i = 0; i<leftIndex;i++){
		leftMLB[i] = mlbs[left+i];
	}
	for(int i = 0; i<rightIndex;i++){
		rightMLB[i] = mlbs[mid+1+i];
	}
	int a=0;
	int b=0;
	int c = left;
	while(a<leftIndex && b<rightIndex){
		if(compareMLBS(order,rightMLB[b],leftMLB[a],field)){
			mlbs[c] = leftMLB[a];
			a++;
		} else {
			mlbs[c] = rightMLB[b];
			b++;
		}
		c++;
	} 
	while(a<leftIndex){
		mlbs[c] = leftMLB[a];
		c++;
		a++;
	}
	while(b<rightIndex){
		mlbs[c] = rightMLB[b];
		c++;
		b++;
	}
	free(leftMLB);
	free(rightMLB);
}

/*
* This function does the merge sort on the given mlbs 
* input : *mlbs : pointer to the mlb_stats structure
* input : teamSize: size of mlb_stats ( no of teams in mlb_stats for a given year)
* input : field: field on which sorting and finding needs to be done
* order: order: incr and decr order for isort 
* return void
*/
void msortOnMLB(mlb_stats *mlbs,int startIndex,int teamSize,char *field,char *order) {
   if(startIndex<teamSize) {
        int mid;
        mid = (int)floor((startIndex+teamSize)/2);
        msortOnMLB(mlbs,startIndex,mid,field,order);
        msortOnMLB(mlbs,mid+1,teamSize,field,order);
        merge(mlbs,startIndex,teamSize,mid,field,order);
   }
}



/*
* This function internally calls msort function to find min and max for
*  MLB stats for average we iterate through all elements sum it over divide by total size
* for median when the size is even we take n/2-1 and n/2 terms and average of these terms
* for odd length we take n-1/2 term
* input: mlbs : mlb_stats pointer
* input: inputSize: no of mlbs for a given year
* input: field: field for which min,max,average and median is to be calculated 
* input: order: min,max,average and median functions
* output: void
*
*/
void mfindOnMLB(mlb_stats *mlbs,int inputSize,char *field,char *order) {
    float sum =0;
    float median =0;
    int startIndex = 0;
    if(strcmp(order,"max")==0){
        msortOnMLB(mlbs,startIndex,inputSize-1,field,"decr");
        printIFind(mlbs[0],field);
    } else if(strcmp(order,"min")==0) {
        msortOnMLB(mlbs,startIndex,inputSize-1,field,"incr");
        printIFind(mlbs[0],field);
    } else if(strcmp(order,"average") ==0) {
        for(int i =0;i<inputSize ; i++) {
            sum = sum + getStructValue(mlbs[i],field);
        }
        cout << "Average : " << sum/(float)inputSize << endl;
    } else if(strcmp(order,"median") ==0) {
    		int index = (inputSize+1)/2;
    		msortOnMLB(mlbs,startIndex,inputSize-1,field,"incr");
			median = getStructValue(mlbs[(int)floor(index)],field);
        cout << "Median : " << median << endl;
	}
}
/*
* This function internally calls isort function to find min and max for
*  MLB stats for average we iterate through all elements sum it over divide by total size
* for median when the size is even we take n/2-1 and n/2 terms and average of these terms
* for odd length we take n-1/2 term
* input: mlbs : mlb_stats pointer
* input: inputSize: no of mlbs for a given year
* input: field: field for which min,max,average and median is to be calculated 
* input: order: min,max,average and median functions
* output: void
*
*/
void ifindOnMLB(mlb_stats *mlbs,int inputSize,char *field,char *order) {
    float sum =0;
    float median =0;
    if(strcmp(order,"max")==0){
        isortOnMLB(mlbs,inputSize,field,"decr");
        printIFind(mlbs[0],field);
    } else if(strcmp(order,"min")==0) {
        isortOnMLB(mlbs,inputSize,field,"incr");
        printIFind(mlbs[0],field);
    } else if(strcmp(order,"average") ==0) {
        for(int i =0;i<inputSize ; i++) {
            sum = sum + getStructValue(mlbs[i],field);
        }
        cout << "Average : " << sum/(float)inputSize << endl;
    } else if(strcmp(order,"median") ==0) {
    		int index = (inputSize+1)/2;
    		isortOnMLB(mlbs,inputSize,field,"incr");
			median = getStructValue(mlbs[(int)floor(index)],field);
        cout << "Median : " << median << endl;
	}
}

/*
* This function checks if we need to call msort or mfind 
* input : *annual : pointer to the annual stats structure
* input : inputSize: size of annual stats ( no of years annual stats are given for )
* input : year: year on which sorting and finding needs to be done
* order: order: order in which sorting needs to be done/ min,max,avg and median for ifind 
* return void
*  
*/
void mcheck(bool sortFind,annual_stats *annual,int inputSize,int year,char *field,char *order) {
    bool foundYear = false;
    int startIndex = 0;
    for(int a = 0; a< inputSize ; a++) {
        if(annual[a].year == year) {
            foundYear = true;
            if(sortFind) {
                msortOnMLB(annual[a].stats,startIndex,annual[a].no_teams-1,field,order);
				printmlbs(annual[a].stats,annual[a].no_teams,field);
            } else {
                mfindOnMLB(annual[a].stats,annual[a].no_teams,field,order);				
            }
            
        }
    }
    if(!foundYear) {
        cout<< "Error : no such year" << endl;
    }
}

/*
* This function checks if we need to call isort or ifind 
* input : *annual : pointer to the annual stats structure
* input : inputSize: size of annual stats ( no of years annual stats are given for )
* input : year: year on which sorting and finding needs to be done
* order: order: order in which sorting needs to be done/ min,max,avg and median for ifind 
* return void
*  
*/
void icheck(bool sortFind,annual_stats *annual,int inputSize,int year,char *field,char *order) {
    bool foundYear = false;
    for(int a = 0; a< inputSize ; a++) {
        if(annual[a].year == year) {
            foundYear = true;
            if(sortFind) {
                isortOnMLB(annual[a].stats,annual[a].no_teams,field,order);
				printmlbs(annual[a].stats,annual[a].no_teams,field);
            } else {
                ifindOnMLB(annual[a].stats,annual[a].no_teams,field,order);				
            }
            
        }
    }
    if(!foundYear) {
        cout<< "Error : no such year" << endl;
    }
}

/*
* function that sorts using the range of years
* input : statsOfVariouYears : annual stats 
* input : annualStatsSize : total number of annual stats
* input : endYear : upper limit of the year
* input : startYear: lower limit of the year
* input: field : field on which sort range should work
* input : order : decr or incr sort on the given field
*
*/
void msortRange(annual_stats *statsOfVariousYears,int annualStatsSize, int startYear, int endYear, char* field,char* order) {
    int size = 0;
    int startIndex = 0;
    for(int i = 0 ; i< annualStatsSize ; i++) {
        if(statsOfVariousYears[i].year >= startYear && statsOfVariousYears[i].year <= endYear ) {
            size = size + statsOfVariousYears[i].no_teams;
        }
    }
    mlb_stats *mlbstatsMerge = new mlb_stats[size];
    int counter = 0;
    for(int j = 0 ; j< annualStatsSize ; j++) {
        if(statsOfVariousYears[j].year >= startYear && statsOfVariousYears[j].year <= endYear ) {
            for(int k= 0; k< statsOfVariousYears[j].no_teams; k++) {
                mlbstatsMerge[counter] = statsOfVariousYears[j].stats[k];
                counter = counter +1;
            }
        }
    }
    msortOnMLB(mlbstatsMerge,startIndex,size-1,field,order);
    printIsortRange(mlbstatsMerge,startYear,endYear,size,field);
}

/*
* function that sorts using the range of years
* input : statsOfVariouYears : annual stats 
* input : annualStatsSize : total number of annual stats
* input : endYear : upper limit of the year
* input : startYear: lower limit of the year
* input: field : field on which sort range should work
* input : order : decr or incr sort on the given field
*
*/
void isortRange(annual_stats *statsOfVariousYears,int annualStatsSize, int startYear, int endYear, char* field,char* 

order) {
    int size = 0;
    for(int i = 0 ; i< annualStatsSize ; i++) {
        if(statsOfVariousYears[i].year >= startYear && statsOfVariousYears[i].year <= endYear ) {
            size = size + statsOfVariousYears[i].no_teams;
        }
    }
    mlb_stats *mlbstatsMerge = new mlb_stats[size];
    int counter = 0;
    for(int j = 0 ; j< annualStatsSize ; j++) {
        if(statsOfVariousYears[j].year >= startYear && statsOfVariousYears[j].year <= endYear ) {
            for(int k= 0; k< statsOfVariousYears[j].no_teams; k++) {
                mlbstatsMerge[counter] = statsOfVariousYears[j].stats[k];
                counter = counter +1;
            }
        }
    }
    isortOnMLB(mlbstatsMerge,size,field,order);
    printIsortRange(mlbstatsMerge,startYear,endYear,size,field);
}

/*
* This is the main function which calls isort,ifind and irange functions
* This function also constructs constructs data structure for our input data
*
*/
int main() {
    string numberOfYears;
    string year;
    string noOfTeams;
    int noofy;
	int yearfy;
    int noofteam;
	int i=0;
    getline(cin,numberOfYears);
	stringstream noOfYear(numberOfYears);noOfYear>> noofy;
	annual_stats *statsOfVariousYears = new annual_stats[noofy];
	int annualStatsSize = noofy;
    while(noofy>0) {
        getline(cin,year);
        stringstream yearss(year);yearss>> yearfy; 
        getline(cin,noOfTeams);
        stringstream noote(noOfTeams);noote>> noofteam;
		statsOfVariousYears[i].year = yearfy;
		statsOfVariousYears[i].no_teams = noofteam;
        statsOfVariousYears[i].stats=constructAnnualStats(yearfy,noofteam);
        noofy--;
        i=i+1;	
    }
    int noOfCommands;
    cin >> noOfCommands;
    while(noOfCommands > 0) {
        int startYear;
        int endYear;
        int year;
        char field[100];
        char order[100];
        bool sortFind = false;
        string firstCommand;
        cin >> firstCommand;
        if(firstCommand.compare("isort") ==0) {
            string secondCommand;
            cin >> secondCommand;
            if(secondCommand.compare("range") ==0) {
                scanf("%d%d%s%s",&startYear,&endYear,field,order);
                isortRange(statsOfVariousYears,annualStatsSize,startYear,endYear,field,order);
            } else {
                stringstream secondCommandss(secondCommand);
                secondCommandss >> year;
                scanf("%s%s",field,order);
                sortFind = true;
                icheck(sortFind,statsOfVariousYears,annualStatsSize,year,field,order);
            }
        } else if(firstCommand.compare("ifind") ==0) {
            scanf("%d%s%s",&year,field,order);
            icheck(sortFind,statsOfVariousYears,annualStatsSize,year,field,order);
        }
		if(firstCommand.compare("msort") ==0) {
            string secondCommand;
            cin >> secondCommand;
            if(secondCommand.compare("range") ==0) {
                scanf("%d%d%s%s",&startYear,&endYear,field,order);
                msortRange(statsOfVariousYears,annualStatsSize,startYear,endYear,field,order);
            } else {
                stringstream secondCommandss(secondCommand);
                secondCommandss >> year;
                scanf("%s%s",field,order);
                sortFind = true;
                mcheck(sortFind,statsOfVariousYears,annualStatsSize,year,field,order);
            }
        } else if(firstCommand.compare("mfind") ==0) {
            scanf("%d%s%s",&year,field,order);
            mcheck(sortFind,statsOfVariousYears,annualStatsSize,year,field,order);
        }
        noOfCommands = noOfCommands -1;
        cout << "\n" << endl;
    }
}
