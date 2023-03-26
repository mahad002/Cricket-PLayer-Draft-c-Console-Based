# Cricket-PLayer-Draft-c-Console-Based
A console based app working to draft players for different teams, read the read me for more information.

You have to develop a program that PSL teams will use to pick new players for the
coming season. League has a total of 4 teams where each team can have a maximum of 16 players. Let’s assume that
N Players have already been listed in the draft, and for each we have the following information as shown in the table
below.

You have to write atleast the following functions. Only name of the functions is given you can have any number of
arguments in them:
  1. playerData(): Get the number of players to enlist in the draft and store their information (as shown in the
    table above). For a batsman bowling average and strike rate should be set to -1, similarly for a bowler
    batting average and strike rate should be set to -1.
  2. sortPlayers(): Reorganize the player information on the basis of their expertise. Only allocate memory
    required to store players’ data separately (batsman bowler and allrounder).
  3. assignRanks(): Assign ranking to the 4 teams on the basis of random number.
  4. teamPicks(): To calculate how many new players each team can buy in the draft, the team ranked first gets
    to decide it first, then the 2nd and so on.
    a. Each team will be asked to tell the number of players they want to retain out of 16 (lets say this
       number is R). R cannot be less than 7 and greater than 11.
    b. New players they can have will be total players minus the players they want to retain (i.e. 16 – R)
  5. playerSelection(): Player selection function where each team chooses their pick one by one (starting with
    the team ranked first), you have to ask the team which type of player they want to pick (batsman, bowler
    and allrounder). Once a player is picked by a team change his status to false (meaning sold).
