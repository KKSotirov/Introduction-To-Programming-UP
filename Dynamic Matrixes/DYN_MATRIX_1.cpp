#include <iostream>
// veche ot main imame suzdadena int nxk matrica
void givePoints(int **matrix, size_t N)
{
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; matrix[i][j] != '\0'; j++)
        {
            std::cout << "Please enter points for player number " << j << " from team " << i << std::endl;
            std::cin >> matrix[i][j];
        }
    }
}

void printInfo(int **matrix, size_t N)
{
    int teamScore[N + 1] = {0};
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; matrix[i][j] != '\0'; j++)
        {
            // printing points for each player:
            std::cout << "Player: " << j << " from team: " << i << " points =  " << matrix[i][j] << std::endl;

            teamScore[i] = teamScore[i] + matrix[i][j];
            // filing up an array full of the points for each team
        }
    }

    // now we need to print the team values in descending order (meaning strongest teams are first)
    int orderedScores[N + 1];
    int orderedTeams[N + 1];
    int max = teamScore[0];
    int maxOrigin;
    // lower value than that allowed for the teams
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if (teamScore[j] > max)
            {
                max = teamScore[j];
                maxOrigin = j;
                teamScore[j] = 0; // we mark this team as used
            }
        }
        // after comparing the first team with every other, we have now got the max points ->
        orderedScores[i] = max;
        orderedTeams[i] = maxOrigin;
        max = -1; // by giving negative value, we ensure that every teamScore (the second, the third and so on)
    }

    // we have now filled every teams' scores, sorted in descending order in one array and the corresponding teams to which those values belong in another array. Now we just print
    for (size_t i = 0; i < N; i++)
    {
        std::cout << "Team: " << orderedTeams[i] + 1 << " with points = " << orderedScores[i] << ". " << std::endl;
    }
}

int main()
{
    // 1. Имаме N отбора, всеки с произволен брой играчи (един отбор може да има трима играчи, друг петима и т.н.). Напишете функция, която добавя точки на играч на определен индекс в даден отбор. Също така, напишете функция, която принтира следната информация за отборите - общи точки и точки за всеки играч в отбора. Отборите следва да се принтират сортирани в низходящ ред по общия брой точки.

    return 0;
}