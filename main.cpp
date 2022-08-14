#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

// function to show instruction of Game
void showInstructions()
{
    printf("\t\t\t  Tic-Tac-Toe\n\n");
    printf("Choose a cell numbered from 1 to 9 as below"
           " and play\n\n");

    printf("\t\t\t  1 | 2  | 3  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  4 | 5  | 6  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  7 | 8  | 9  \n\n");

    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
}

// function to select random number from 1 to 9
int computer_turn()
{
    int a = rand() % 9 + 1;
    return a;
}

// function to select random number from 0 to 2
int comp_after()
{
    int a = rand() % 3;
    return a;
}

// function to show current status of board
void showBoard(char board[][3])
{
    printf("\n\n");

    printf("\t\t\t  %c | %c  | %c  \n", board[0][0],
           board[0][1], board[0][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n", board[1][0],
           board[1][1], board[1][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n\n", board[2][0],
           board[2][1], board[2][2]);
}

// function to cheak who won the game
int cheak_who_won(char board[3][3])
{
    int flag = -1;
    if ((board[0][0] == board[0][1]) && (board[0][1] == board[0][2]) && ((board[0][0] == 'X') || (board[0][0] == 'O')))
    {
        if (board[0][0] == 'O')
            flag = 0;
        else
            flag = 1;
    }
    else if ((board[1][0] == board[1][1]) && (board[1][1] == board[1][2]) && ((board[1][0] == 'X') || (board[1][0] == 'O')))
    {
        if (board[1][0] == 'O')
            flag = 0;
        else
            flag = 1;
    }
    else if ((board[2][0] == board[2][1]) && (board[2][1] == board[2][2]) && ((board[2][0] == 'X') || (board[2][0] == 'O')))
    {
        if (board[2][0] == 'O')
            flag = 0;
        else
            flag = 1;
    }
    else if ((board[0][0] == board[1][0]) && (board[1][0] == board[2][0]) && ((board[0][0] == 'X') || (board[0][0] == 'O')))
    {
        if (board[0][0] == 'O')
            flag = 0;
        else
            flag = 1;
    }
    else if ((board[0][1] == board[1][1]) && (board[1][1] == board[2][1]) && ((board[0][1] == 'X') || (board[0][1] == 'O')))
    {
        if (board[0][1] == 'O')
            flag = 0;
        else
            flag = 1;
    }
    else if ((board[0][2] == board[1][2]) && (board[1][2] == board[2][2]) && ((board[0][2] == 'X') || (board[0][2] == 'O')))
    {
        if (board[0][2] == 'O')
            flag = 0;
        else
            flag = 1;
    }
    else if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && ((board[0][0] == 'X') || (board[0][0] == 'O')))
    {
        if (board[0][0] == 'O')
            flag = 0;
        else
            flag = 1;
    }
    else if ((board[1][2] == board[1][1]) && (board[1][1] == board[2][0]) && ((board[1][2] == 'X') || (board[1][2] == 'O')))
    {
        if (board[1][2] == 'O')
            flag = 0;
        else
            flag = 1;
    }
    if (flag == 0)
    {
        cout << "*** Computer Won The Game ***\n\n";
        return 1;
    }
    else if (flag == 1)
    {
        cout << "*** You Won The Game ***\n\n";
        return 1;
    }
    return 0;
}

// function for playing game after three turn
void after_three_turn_game(char board[3][3], char ch, int arr_cmp[])
{

    int n, x, y, put, temp, n_u, put_u;

    // user turn
    if (ch == 'u')
    {
    show:
        cout << "\nEnter a Number from which you want to pick 'X' : ";
        cin >> n_u;
        x = n_u / 3;
        y = n_u % 3 - 1;
        if (board[x][y] != 'X')
        {
            cout << "Error , Please select appropriate number \n"
                 << endl;
            goto show;
        }
        board[x][y] = ' ';
    show_time:
        cout << "\nEnter a number where you want to put 'X : ";
        cin >> put_u;
        x = put_u / 3;
        y = put_u % 3 - 1;
        if (board[x][y] != ' ')
        {
            cout << "Error , Please select appropriate number " << endl;
            goto show_time;
        }
        board[x][y] = 'X';
        showBoard(board);
    }

    // computer turn
    else if (ch == 'c')
    {
        temp = comp_after();
        n = arr_cmp[temp];
        x = n / 3;
        y = n % 3 - 1;
        board[x][y] = ' ';

    repeat:

        put = computer_turn();
        arr_cmp[temp] = put;
        x = put / 3;
        y = put % 3 - 1;
        if (board[x][y] != ' ')
        {
            goto repeat;
        }
        board[x][y] = 'O';

        showBoard(board);

        cout << "\nComputer picked 'O' from " << n << " And puted on " << put << endl
             << endl
             << endl;
    }
}

void play_game()
{
    int x, y, t, input, temp = 0, count_u = 0, flag = 0, arr_cmp[3], i = 0, count_c = 0, result;

    // creating an empty board
    char board[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }

    while (temp == 0)
    {
        temp = cheak_who_won(board);
        if (count_u == 3 && temp == 1)
        {
            break;
        }
        else if (count_u == 3)
        {

            after_three_turn_game(board, 'u', arr_cmp);
            count_u--;
            flag = 1;
        }

    label:
        if (flag != 1)
        {
            cout << "Your Turn : ";
            cin >> input;
            x = input / 3;
            y = input % 3 - 1;
            if (board[x][y] != ' ')
            {
                cout << "Error , Please select appropriate number" << endl;
                goto label;
            }
            board[x][y] = 'X';
            showBoard(board);
        }
        count_u++;
        temp = cheak_who_won(board);
        if (temp == 1)
            break;

        if (count_c == 3 && temp == 1)
        {
            break;
        }
        else if (count_c == 3)
        {

            after_three_turn_game(board, 'c', arr_cmp);
            flag = 1;
            count_c--;
        }
        if (flag != 1)
        {
            // cout << "Computer turn : " << endl;

        again:
            t = computer_turn();
            arr_cmp[i] = t;
            i++;
            x = t / 3;
            y = t % 3 - 1;
            if (board[x][y] != ' ')
            {
                goto again;
            }

            board[x][y] = 'O';

            showBoard(board);
            cout << "You puted 'X' at cell number " << input << endl;
            cout << "Computer put 'O' in cell " << t << endl
                 << endl;

            temp = cheak_who_won(board);
        }
        count_c++;
    }
}

int main()
{
    showInstructions();

    srand(time(NULL));
    play_game();

    return 0;
}
