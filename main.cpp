#include <iostream> 
#include <random>
#include <cstdlib> 
#include <unistd.h>

using namespace std;

std::random_device dev;
std::mt19937 rng(dev());

bool add_ship(int deck, int (&ships)[10][10]) {
    int vert = rng() % 2;
    int start_x = rng() % 10;
    for (int i = start_x; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (vert && i + deck - 1 >= 10) continue;
            if (!vert && j + deck - 1 >= 10) continue;
            
            bool check = true;
            if (vert) {
                for (int k = max(i - 1, 0); k <= min(i + deck, 9); ++k) {
                    for (int t = max(0, j - 1); t <= min(j + 1, 9); ++t) {
                        check &= ships[k][t] == 0;
                    }
                }
                if (check) {
                    for (int k = i; k < i + deck; ++k) ships[k][j] = 1;
                    return true;
                }
            } else {
                for (int k = max(i - 1, 0); k <= min(i + 2, 9); ++k) {
                    for (int t = max(0, j - 1); t <= min(j + deck, 9); ++t) {
                        check &= ships[k][t] == 0;
                    }
                }
                if (check) {
                    for (int k = j; k < j + deck; ++k) ships[i][k] = 1;
                    return true;
                }
            }
        }
    }
    for (int i = start_x; i >= 0; --i) {
        for (int j = 9; j >= 0; --j) {
            if (vert && i + deck - 1 >= 10) continue;
            if (!vert && j + deck - 1 >= 10) continue;
            
            bool check = true;
            if (vert) {
                for (int k = max(i - 1, 0); k <= min(i + deck, 9); ++k) {
                    for (int t = max(0, j - 1); t <= min(j + 1, 9); ++t) {
                        check &= ships[k][t] == 0;
                    }
                }
                if (check) {
                    for (int k = i; k < i + deck; ++k) ships[k][j] = 1;
                    return true;
                }
            } else {
                for (int k = max(i - 1, 0); k <= min(i + 2, 9); ++k) {
                    for (int t = max(0, j - 1); t <= min(j + deck, 9); ++t) {
                        check &= ships[k][t] == 0;
                    }
                }
                if (check) {
                    for (int k = j; k < j + deck; ++k) ships[i][k] = 1;
                    return true;
                }
            }
        }
    }
    return false;
}

void build_table(int (&ships)[10][10]) {
    while (true) {
        bool check = true;
        check &= add_ship(4, ships);
        check &= add_ship(3, ships);
        check &= add_ship(3, ships);
        check &= add_ship(2, ships);
        check &= add_ship(2, ships);
        check &= add_ship(2, ships);
        check &= add_ship(1, ships);
        check &= add_ship(1, ships);
        check &= add_ship(1, ships);
        check &= add_ship(1, ships);
        if (check) break;

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                ships[i][j] = 0;
            }
        }
    }    
}

void print_ship() {
    const int count_of_deck = 4; // количество палуб у корабля
    string ship[count_of_deck] = { // наш кораблик
        "       _    _",
        "    __|_|__|_|__",
        "  _|____________|__",
        " |o o o o o o o o /",
    };
    
    string sea = "~'`~'`~'`~'`~'`~'`~'`~'`~'`~"; 
   
    system("clear");
    usleep(1000000);
    for (int k = 0; k < 4; ++k) {
        // рисуем корабль по палубам
        for (int i = 0; i < count_of_deck; ++i) { 
            cout << ship[i] << endl;
        }
        // рисуем море
        cout << sea << endl;
        
        usleep(1000000); 
        system("clear");
        
        // сдвигаем палубы, чтобы создать эффект плавания
        for (int i = 0; i < count_of_deck; ++i) {
            ship[i] = "   " + ship[i];
        }
    }
    
    cout << "Морской бой" << endl; 
    usleep(1000000);
}

bool is_correct_shoot(int x, int y, int ships[10][10]) {
    return !(x > 9 or y > 9 or ships[x][y] == 2 or
             ships[x][y] == 3 or x < 0  or y < 0);
}

void print_table(int ships[10][10]) {
    cout << "  ";
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
        int ships[10][10]{};
        build_table(ships); // рандомная расстановка кораблей

        // ships[i][j] = 0 - ничего
        // ships[i][j] = 1 - корабль
        // ships[i][j] = 2 - подбитый корабль
        // ships[i][j] = 3 - мимо

        setlocale(0, ""); 

        print_ship(); // рисуем кораблик
        
        int shoot = 0; 
        while (count > 0) {
            print_table(ships); // рисуем текущее поле противника

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
                if (!is_correct_shoot(x, y, ships)) 
                    cout << "Некорректный выстрел. Попробуйте еще раз.\n";
                else break;
            }

            // обновляем поле противника, в зависиморсти
            // от того, куда попали
            system("clear");
            if (ships[x][y] == 1) { 
                ships[x][y] = 2; 
                count--; 
            } 
            if (ships[x][y] == 0) ships[x][y] = 3; 
            shoot++;
        }

        cout << "Вы победили!" << endl; 
        usleep(1000000);
        cout << "Вам потребовалось выстрелов: " <<  shoot << endl;
        usleep(1000000);
        cout << "Если хотите начать сначала, нажмите 1, если нет, то 0." << endl;
        usleep(1000000);
        cout << "Введите: ";
        int e;
        cin >> e;
        if (e == 1) {
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