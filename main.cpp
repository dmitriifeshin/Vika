#include <iostream> 
#include <cstdlib> 
#include <unistd.h>

using namespace std;

void print_ship() {
    const int count_of_deck = 5; // количество палуб у корабля
    string ship[count_of_deck] = {
        "       _    _",
        "    __|_|__|_|__",
        "  _|____________|__",
        " |o o o o o o o o /",
    };
    
    string sea = "~'`~'`~'`~'`~'`~'`~'`~'`~'`~"; 
   
    system("clear");
    usleep(1000000);
    for (int k = 0; k < 4; ++k) {
        for (int i = 0; i < count_of_deck; ++i) {
            cout << ship[i] << endl;
        }
        cout << sea << endl;
        
        usleep(1000000); 
        system("clear");
        
        for (int i = 0; i < count_of_deck; ++i) {
            ship[i] = "   " + ship[i];
        }
    }
    
    cout << "Морской бой" << endl; 
    usleep(1000000);
    cout << "  ";
}

bool is_correct_shoot(int x, int y, int ships[10][10]) {
    return !(x > 9 or y > 9 or ships[x][y] == 2 or
             ships[x][y] == 3 or x < 0  or y < 0);
}

const string incorrect_shoot = "Некорректный выстрел. Попробуйте еще раз.\n";

void print_table(int ships[10][10]) {
    for (int i = 0; i < 10; i++) cout << i << " "; 
    cout << endl; 
    for (int i = 0; i < 10; i++) { 
        cout << i << " ";
        for (int j = 0; j < 10; j++) {
            if (ships[i][j] == 0) printf("\033[3%d;4%dm", 7, 7); 
            if (ships[i][j] == 1) printf("\033[3%d;4%dm", 7, 7);
            if (ships[i][j] == 2) printf("\033[3%d;4%dm", 1, 0);    
            if (ships[i][j] == 3) printf("\033[3%d;4%dm", 7, 4);

            if (ships[i][j] == 0) cout << "  "; 
            if (ships[i][j] == 1) cout << "  ";
            if (ships[i][j] == 2) cout << "+ ";  
            if (ships[i][j] == 3) cout << ". "; 
        } 
        printf("\033[00m");
        cout << endl; 
    }
}

int main() {
    int n = 2;
    do {
        int count = 20; 
        int ships[10][10] = { 
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
        {1, 0, 0, 1, 1, 1, 1, 0, 0, 1}, 
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 1, 0, 0, 1, 1, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0} }; 
        // ships[i][j] = 0 - ничего
        // ships[i][j] = 1 - корабль
        // ships[i][j] = 2 - подбитый корабль
        // ships[i][j] = 3 - мимо

        setlocale(0, ""); 

        print_ship(); // рисуем кораблик

        print_table(ships); // рисуем текущее поле противника
        
        int shoot = 0; 
        while (count > 0) {
            // делаем выстрел по противнику
            int x;
            int y;
            while (true) {
                cout << "Сделайте свой выстрел!" << endl; 
                usleep(1000000);
                cout << "Строка: "; 
                cin >> x;
                usleep(100000);
                cout << "Столбец: "; 
                cin >> y; 
                usleep(100000);
                
                // проверка на корректность выстрела
                if (!is_correct_shoot(x, y, ships)) cout << incorrect_shoot;
                else break;
            }

            system("clear");
            if (ships[x][y] == 1) { 
                ships[x][y] = 2; 
                count--; 
            } 
            else if(ships[x][y] == 0) ships[x][y] = 3; 
            shoot++; 
            
            cout << "  "; 
            for(int i = 0; i < 10; i++) cout << i<< " ";  
            cout <<endl; 
                for(int i = 0; i < 10; i++) { 
                cout << i<< " "; 
            
                for(int j=0;j<10;j++){ 
                    if(ships[i][j]==0)printf("\033[3%d;4%dm", 7, 7); 
                    else if(ships[i][j]==2) printf("\033[3%d;4%dm", 1, 0);  
                    else if(ships[i][j]==1) printf("\033[3%d;4%dm", 7, 7);  
                    else if(ships[i][j]==3) printf("\033[3%d;4%dm", 7, 4); 
                    if(ships[i][j]==0) cout << "  "; 
                    else if(ships[i][j]==2) cout << "+ "; 
                    else if(ships[i][j]==1) cout << "  "; 
                    else if(ships[i][j]==3) cout << ". "; 
                } 
                printf("\033[00m");
                cout << endl; 
            } 
        } 
        cout << "Вы победили!" << endl; 
        usleep(1000000);
        cout << "Вам потребовалось выстрелов: " <<  shoot<< endl;
        usleep(1000000);
        cout << "Если хотите начать сначала, нажмите 1, если нет, то 0." <<  endl;
        usleep(1000000);
        cout << "Введите: ";
        int e;
        cin>> e;
        if(e == 1) {
            n = 2;
        system("clear");
            
        }
        else{
        n = 0;
        system("clear");
        cout << "Спасибо за игру!";
        }

    } while (n == 2);
    
    cin.get();
}