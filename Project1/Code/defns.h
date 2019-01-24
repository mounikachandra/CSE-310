#define TEAM_NAME_LEN	50 // Maximum team name string length
#define LEAGUE_NAME 	3  // Maximum league name string length

struct mlb_stats{
   char Team[ TEAM_NAME_LEN ]; // Name of the MLB team
   char League[ LEAGUE_NAME ]; // American or National league, AL or NL
   int G; // Number of games
   int AB; // Number of official at bats by a batter
   int R; // The number of times a baserunner safely reaches home plate
   int H; // The number of hits
   int B2; // The number of times a batter hits the ball and reaches second base
   int B3; // The number of times a batter hits the ball and reaches third base
   int HR; // The number of home runs
   int RBI; // The number of runs that score safely
   int BB; // The number of walks by a batter
   int SO; // The number of strikeouts by a batter
   int SB; // The number of times a player has stolen a base
   int CS; // The number of times a player has been put out attempting to steal a base
   float AVG; // The average number of hits by a batter 
   float OBP; // The on base percentage
   float SLG; // Slugging percentage
   float OPS; // The on base percentage plus slugging
};

struct annual_stats{
   int year;
   int no_teams; // Number of teams in the given year
   struct mlb_stats *stats; // Array size of statistics depends on number of teams in the given year
};